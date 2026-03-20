#ifndef FEATURES_H
#define FEATURES_H

#include "../../include/features.h"

#define weak __attribute__((__weak__))
#define hidden __attribute__((__visibility__("hidden")))

/* Clang on macOS/Darwin rejects __alias__ for both WASM and native MachO
   targets. Use #pragma weak instead, which works on all platforms and
   produces identical weak symbol bindings. */
#if defined(__APPLE__) || defined(__wasm__)
#define _WA_STR(x) #x
#define _WA_PRAGMA(x) _Pragma(_WA_STR(x))
#define weak_alias(old, new) \
	_WA_PRAGMA(weak new=old)
#else
#define weak_alias(old, new) \
	extern __typeof(old) new __attribute__((__weak__, __alias__(#old)))
#endif

#endif
