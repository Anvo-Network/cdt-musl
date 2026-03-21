/* Stub mach-o/dyld.h for CDT WASM sysroot.
 * Mach-O dynamic loading is not available in WASM, but libc++ refstring.h
 * includes this header on macOS builds. Provides declarations so
 * compilation succeeds; functions are never called at runtime. */
#ifndef _MACHO_DYLD_H
#define _MACHO_DYLD_H

#include <stdint.h>

static inline uint32_t _dyld_image_count(void) { return 0; }
static inline const char *_dyld_get_image_name(uint32_t __index) { return (const char *)0; }

#endif
