#ifndef FEATURES_H
#define FEATURES_H

#include "../../include/features.h"

#define weak __attribute__((__weak__))
#define hidden __attribute__((__visibility__("hidden")))

#ifdef __APPLE__
/* macOS Mach-O linker does not support __alias__ attribute.
 * For native test builds on macOS, weak_alias is a no-op.
 * The aliased symbols must be provided separately. */
#define weak_alias(old, new)
#else
#define weak_alias(old, new) \
	extern __typeof(old) new __attribute__((__weak__, __alias__(#old)))
#endif

#endif
