/* WASM stub - no syscalls available */
#ifndef _INTERNAL_SYSCALL_H
#define _INTERNAL_SYSCALL_H

#include <errno.h>

/* All syscall macros resolve to setting ENOSYS and returning -1 */
#define __syscall0(n) (-ENOSYS)
#define __syscall1(n,a) (-ENOSYS)
#define __syscall2(n,a,b) (-ENOSYS)
#define __syscall3(n,a,b,c) (-ENOSYS)
#define __syscall4(n,a,b,c,d) (-ENOSYS)
#define __syscall5(n,a,b,c,d,e) (-ENOSYS)
#define __syscall6(n,a,b,c,d,e,f) (-ENOSYS)

#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)
#define __SYSCALL_LL_PRW(x) (x)

#define __syscall_ret(r) (((r) < 0) ? (errno = -(r), -1L) : (r))

#define SYS_writev 0
#define SYS_readv 0
#define SYS_read 0
#define SYS_write 0
#define SYS_close 0
#define SYS_ioctl 0
#define SYS_exit_group 0
#define SYS_exit 0
#define SYS_lseek 0
#define SYS_mmap 0
#define SYS_mmap2 0
#define SYS_munmap 0
#define SYS_mremap 0
#define SYS_madvise 0
#define SYS_brk 0
#define SYS_set_tid_address 0
#define SYS_futex 0
#define SYS_clock_gettime 0
#define SYS_clock_gettime64 0
#define SYS_gettimeofday 0
#define SYS_kill 0
#define SYS_tkill 0
#define SYS_tgkill 0
#define SYS_rt_sigaction 0
#define SYS_rt_sigprocmask 0

/* Variadic __syscall — all syscalls return -ENOSYS in WASM */
#define __syscall(...) (-ENOSYS)
#define syscall(...) (-ENOSYS)

#define SYSCALL_MMAP2_UNIT 4096ULL
#define SYSCALL_RLIM_INFINITY (~0ULL)

/* Stub for code that references __clock_gettime */
#define __clock_gettime(clk, ts) (-ENOSYS)

/* Note: __futexwait and __wake are defined as inline functions in
 * pthread_impl.h using __syscall(SYS_futex, ...) which resolves
 * to -ENOSYS via the __syscall macro above. Do NOT redefine them
 * as macros here — it breaks the function declarations. */

typedef long syscall_arg_t;

#endif
