#ifndef FEATURES_H
#define FEATURES_H

#include "../../include/features.h"

#define weak __attribute__((__weak__))
#define hidden __attribute__((__visibility__("hidden")))

/* For WASM targets, use #pragma weak instead of __alias__ because clang on
   macOS/Darwin rejects __alias__ even when cross-compiling to WASM. The
   pragma approach produces identical weak symbols and works on all hosts. */
#if defined(__wasm__)
#define _WA_STR(x) #x
#define _WA_PRAGMA(x) _Pragma(_WA_STR(x))
#define weak_alias(old, new) \
	_WA_PRAGMA(weak new=old)
#else
#define weak_alias(old, new) \
	extern __typeof(old) new __attribute__((__weak__, __alias__(#old)))
#endif

#endif
