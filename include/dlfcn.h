/* Stub dlfcn.h for CDT WASM sysroot.
 * Dynamic linking is not available in WASM, but libc++ refstring.h
 * includes this header on macOS builds. Provides declarations so
 * compilation succeeds; functions are never called at runtime. */
#ifndef _DLFCN_H
#define _DLFCN_H

#define RTLD_DEFAULT ((void *)0)
#define RTLD_LAZY    1
#define RTLD_NOW     2
#define RTLD_GLOBAL  256
#define RTLD_LOCAL   0
#define RTLD_NOLOAD  4

static inline void *dlopen(const char *__file, int __mode) { return (void *)0; }
static inline int dlclose(void *__handle) { return 0; }
static inline void *dlsym(void *__handle, const char *__name) { return (void *)0; }
static inline char *dlerror(void) { return (char *)0; }

#endif
