/* WASM stub - no floating-point environment control */
#ifndef _FENV_H
#define _FENV_H

#define FE_TONEAREST    0
#define FE_DOWNWARD     0x400
#define FE_UPWARD       0x800
#define FE_TOWARDZERO   0xc00

#define FE_INEXACT      0x20
#define FE_UNDERFLOW    0x10
#define FE_OVERFLOW     0x08
#define FE_DIVBYZERO    0x04
#define FE_INVALID      0x01

#define FE_ALL_EXCEPT   0x3f

typedef unsigned short fexcept_t;
typedef struct { unsigned short __cw; } fenv_t;

#define FE_DFL_ENV ((const fenv_t *)-1)

static inline int feclearexcept(int m) { return 0; }
static inline int feraiseexcept(int m) { return 0; }
static inline int fetestexcept(int m) { return 0; }
static inline int fegetround(void) { return FE_TONEAREST; }
static inline int fesetround(int r) { return 0; }
static inline int fegetenv(fenv_t *e) { return 0; }
static inline int fesetenv(const fenv_t *e) { return 0; }
static inline int feholdexcept(fenv_t *e) { return 0; }
static inline int feupdateenv(const fenv_t *e) { return 0; }
static inline int fegetexceptflag(fexcept_t *f, int m) { return 0; }
static inline int fesetexceptflag(const fexcept_t *f, int m) { return 0; }

#endif
