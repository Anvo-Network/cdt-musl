/* Minimal pthread header for WASM (single-threaded) */
#ifndef _PTHREAD_H
#define _PTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_pthread_t
#define __NEED_pthread_once_t
#define __NEED_pthread_key_t
#define __NEED_pthread_spinlock_t
#define __NEED_pthread_mutexattr_t
#define __NEED_pthread_condattr_t
#define __NEED_pthread_barrierattr_t
#define __NEED_pthread_rwlockattr_t
#define __NEED_pthread_attr_t
#define __NEED_pthread_mutex_t
#define __NEED_pthread_cond_t
#define __NEED_pthread_rwlock_t
#define __NEED_pthread_barrier_t
#define __NEED_size_t
#define __NEED_time_t
#define __NEED_clockid_t
#define __NEED_struct_timespec

#include <bits/alltypes.h>

#define PTHREAD_MUTEX_INITIALIZER {{{0}}}
#define PTHREAD_COND_INITIALIZER {{{0}}}
#define PTHREAD_RWLOCK_INITIALIZER {{{0}}}
#define PTHREAD_ONCE_INIT 0

#ifdef __cplusplus
}
#endif

#endif
