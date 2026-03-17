# cdt-musl — musl libc for WASM Smart Contracts

A WASM-targeted port of [musl libc](https://musl.libc.org/) for the
Anvo Network Contract Development Toolkit (CDT).

## Base Version

**musl 1.2.5** (released 2024-02-29), the latest stable release.

This port replaces the previous fork which was based on musl 1.1.18
(October 2017). The upgrade spans **6+ years** of upstream development,
including 12 releases and numerous bug fixes, security patches, and
standard conformance improvements.

## Security Fixes Included

The following security vulnerabilities present in the old musl 1.1.18-based
fork are fixed in this port:

### CVE-2020-28928 — Buffer overflow in `wcsnrtombs` (CVSS 5.5)

**Affected:** musl 1.1.15 through 1.2.1. **Fixed in:** musl 1.2.2.

The `wcsnrtombs()` function mishandled the interaction between the destination
buffer size limit and the source wide-character count limit. When both limits
were active, the function could enter an infinite loop or write past the end
of the destination buffer. A contract accepting wide-character input and
converting it to multibyte could trigger this, potentially corrupting WASM
linear memory state used by the contract.

### CVE-2019-14697 — x87 floating-point stack imbalance (CVSS 9.8)

**Affected:** musl through 1.1.23, i386 only. **Fixed in:** musl 1.1.24.

Assembly code in `math/i386/` could leave the x87 FP stack in an imbalanced
state, causing out-of-bounds writes in subsequent math operations. **Not
applicable to WASM** (no x87 stack), but fixed in this release for completeness.

### Aligned allocation crash on failure

**Affected:** musl through 1.2.2. **Fixed in:** musl 1.2.3.

`aligned_alloc()` and its variants (`memalign`, `posix_memalign`) would
dereference a null pointer when the underlying allocator returned NULL (out of
memory). In the old fork, this would cause an immediate contract abort (WASM
traps on null dereference at address 0) rather than allowing graceful error
handling. The fix adds a null check before accessing the allocation metadata.

### `fmaf` wrong rounding on softfloat architectures

**Affected:** musl through 1.2.2. **Fixed in:** musl 1.2.3.

The fused multiply-add function `fmaf()` produced incorrectly rounded results
on all architectures that do not have hardware FMA instructions. WASM is
effectively a softfloat target — all floating-point operations go through the
WASM runtime. A contract performing financial calculations using `fmaf()` could
produce subtly incorrect results. This was particularly dangerous because the
errors were deterministic and could be exploited for precision-dependent logic.

### `expm1f` and `acoshf` incorrect results

**Affected:** musl through 1.2.2. **Fixed in:** musl 1.2.3.

Both functions produced incorrect results for certain input ranges. `expm1f`
(exponential minus one) is commonly used in financial and scientific
calculations where precision near zero matters. Incorrect results could cause
erroneous interest calculations, pricing, or scientific modeling in contracts.

### printf positional argument buffer overflow

**Affected:** musl through 1.2.3. **Fixed in:** musl 1.2.4.

Using the `%9$` positional argument specifier in printf format strings
overflowed an undersized internal buffer. A contract using printf-style
formatting with positional arguments (e.g., for internationalized messages)
could corrupt its own memory state. The previous fork was not directly
affected because it used a third-party printf replacement, but this port
restores musl's native printf, which includes the fix.

### `wcscmp`/`wcsncmp`/`wmemcmp` comparison overflow

**Affected:** musl through 1.2.3. **Fixed in:** musl 1.2.4.

Wide string comparison functions returned incorrect results when the
difference between two `wchar_t` values overflowed a signed integer. This
could cause incorrect sorting, searching, or equality checks on wide-character
data, potentially allowing a contract to accept data it should reject or
vice versa.

### `memccpy` off-by-one error

**Affected:** musl through 1.1.20. **Fixed in:** musl 1.1.21.

`memccpy()` returned an incorrect pointer when the first byte past the
source buffer happened to match the delimiter character. A contract using
`memccpy()` for bounded string operations could read past intended boundaries
or miscalculate output lengths.

### `sscanf` buffer overread

**Affected:** musl 1.1.21 (regression). **Fixed in:** musl 1.1.22.

`sscanf()` could read past the end of its input buffer under certain format
string conditions. While WASM traps on out-of-bounds linear memory access,
within-bounds overreads of unintended data are possible and could leak
sensitive contract state to parsing logic.

### Math library accuracy rewrite

**Affected:** musl through 1.1.22.

The core mathematical functions `log()`, `exp()`, and `pow()` were completely
rewritten in musl 1.1.23 for improved accuracy and edge-case correctness.
The old implementations had known accuracy issues that could produce subtly
wrong results in financial or scientific contract calculations.

### Not Applicable

- **CVE-2025-26519** (iconv out-of-bounds write, musl through 1.2.5): This
  port does not include `iconv` — character set conversion is not needed in
  the WASM contract environment. The affected code has been removed entirely.
- **CVE-2019-14697** (x87 FP stack imbalance): i386-specific assembly, not
  applicable to WASM.

## Key Improvements Over Previous Fork

### 64-bit `time_t` (Y2038 fix)

The previous fork defined `time_t` as `long` (32-bit on wasm32), which would
overflow on January 19, 2038. This port uses 64-bit `time_t` (`long long`),
matching musl 1.2.0+ behavior and ensuring contracts can safely handle
timestamps well beyond 2038.

### Native musl printf

The previous fork replaced musl's `vfprintf` with Marco Paland's "tiny printf"
— a separate, independently maintained implementation. This port uses musl's
own printf, which has received extensive bug fixes and conformance improvements
through the 1.2.x series. Output is routed through the `prints_l()` host
import via musl's standard `__stdio_write` hook.

### Centralized `weak_alias` handling

The previous fork scattered `#ifdef __APPLE__` guards across ~100 source
files to handle macOS's lack of `__alias__` attribute support. This port
handles it in a single macro definition in `src/include/features.h`.

### Clean architecture separation

The WASM platform definition lives entirely in `arch/wasm32/` with clearly
separated type definitions, instead of being mixed into upstream headers.

## WASM Adaptations

This port adapts musl for the WASM smart contract execution environment:

- **No OS**: All syscalls return `-ENOSYS`. No filesystem, networking,
  signals, or dynamic linking.
- **No threads**: Atomics are no-ops. Locking is `*l = 1` / `*l = 0`.
- **stdout → `prints_l()`**: Console output goes through the blockchain
  runtime's `prints_l()` host import via `__stdio_write`.
- **`time()` → `current_time()`**: Block time provided by the
  `current_time()` host import (microseconds), converted to seconds.
- **No `memcpy`/`memmove`/`memset`**: WASM provides these as built-in
  bulk memory instructions via compiler intrinsics.
- **Heap-allocated strtod buffer**: The `decfloat()` function in
  `floatscan.c` heap-allocates its large working buffer instead of using
  the stack, avoiding WASM stack overflow (WASM stacks are typically 8KB).
- **`abort()` → `__builtin_trap()`**: Triggers WASM `unreachable` trap.
- **Locale**: Always returns C/UTF-8 (no filesystem-based locale loading).
- **`sbrk()`**: The only function in `unistd.h` — WASM memory growth.

## Native Build Support

For host-side unit testing of contracts, define `CORE_NET_NATIVE` to switch
type widths to 64-bit pointers (`size_t`, `ptrdiff_t`, `intptr_t`, etc.).
This is handled automatically by CDT's native build toolchain.

## Directory Structure

```
arch/
  generic/       — musl's generic bits headers
  wasm32/        — WASM32 platform definition
    bits/        — Type definitions, limits, errno
    atomic_arch.h — No-op atomics
    pthread_arch.h — Stub pthread_self
include/         — Public C standard library headers
src/
  crypt/         — Password hashing (DES, SHA, Blowfish, MD5)
  ctype/         — Character classification
  env/           — Environment variables
  errno/         — errno location
  exit/          — _Exit, abort, atexit
  internal/      — Internal helpers (floatscan, intscan, stdio_impl)
  locale/        — Simplified locale (always C/UTF-8)
  malloc/        — memalign, posix_memalign, calloc, free, realloc
  math/          — Full math library (210 functions)
  misc/          — ffs, basename, dirname, etc.
  multibyte/     — UTF-8/wide character conversion
  search/        — hsearch, tsearch, etc.
  stdio/         — printf, scanf, FILE operations
  stdlib/        — strtol, strtod, qsort, bsearch, etc.
  string/        — String operations (memcmp, strlen, etc.)
  thread/        — No-op __lock/__unlock only
  time/          — time, mktime, strftime, gmtime
```

## License

musl libc is licensed under the MIT license. See [COPYRIGHT](COPYRIGHT).
