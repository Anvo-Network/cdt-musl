/* wasm32 alltypes.h - pre-generated from musl 1.2.5 alltypes.h.in
 *
 * WASM target: ILP32, little-endian, 64-bit time_t
 *   _Addr = int (32-bit pointers), _Int64 = long long, _Reg = int
 *
 * Native target (CORE_NET_NATIVE): LP64, for host-side unit testing
 *   _Addr = long (64-bit pointers), _Int64 = long, _Reg = long
 */

#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN 4321
#define __USE_TIME_BITS64 1

#define __BYTE_ORDER 1234

#ifdef CORE_NET_NATIVE
#define __LONG_MAX 0x7fffffffffffffffL
#else
#define __LONG_MAX 0x7fffffffL
#endif

#ifdef __NEED_size_t
#ifdef CORE_NET_NATIVE
typedef unsigned long size_t;
#else
typedef unsigned int size_t;
#endif
#endif
#ifdef __NEED___isoc_va_list
typedef __builtin_va_list __isoc_va_list;
#endif
#if defined(__NEED_size_t) && !defined(__DEFINED_size_t)
#define __DEFINED_size_t
#endif

#ifdef __NEED_uintptr_t
#ifdef CORE_NET_NATIVE
typedef unsigned long uintptr_t;
#else
typedef unsigned int uintptr_t;
#endif
#endif
#if defined(__NEED_uintptr_t) && !defined(__DEFINED_uintptr_t)
#define __DEFINED_uintptr_t
#endif

#ifdef __NEED_ptrdiff_t
#ifdef CORE_NET_NATIVE
typedef long ptrdiff_t;
#else
typedef int ptrdiff_t;
#endif
#endif
#if defined(__NEED_ptrdiff_t) && !defined(__DEFINED_ptrdiff_t)
#define __DEFINED_ptrdiff_t
#endif

#ifdef __NEED_ssize_t
#ifdef CORE_NET_NATIVE
typedef long ssize_t;
#else
typedef int ssize_t;
#endif
#endif
#if defined(__NEED_ssize_t) && !defined(__DEFINED_ssize_t)
#define __DEFINED_ssize_t
#endif

#ifdef __NEED_intptr_t
#ifdef CORE_NET_NATIVE
typedef long intptr_t;
#else
typedef int intptr_t;
#endif
#endif
#if defined(__NEED_intptr_t) && !defined(__DEFINED_intptr_t)
#define __DEFINED_intptr_t
#endif

#ifdef __NEED_regoff_t
typedef int regoff_t;
#endif
#if defined(__NEED_regoff_t) && !defined(__DEFINED_regoff_t)
#define __DEFINED_regoff_t
#endif

#ifdef __NEED_register_t
typedef int register_t;
#endif
#if defined(__NEED_register_t) && !defined(__DEFINED_register_t)
#define __DEFINED_register_t
#endif

#ifdef __NEED_time_t
typedef long long time_t;
#endif
#if defined(__NEED_time_t) && !defined(__DEFINED_time_t)
#define __DEFINED_time_t
#endif

#ifdef __NEED_suseconds_t
typedef long long suseconds_t;
#endif
#if defined(__NEED_suseconds_t) && !defined(__DEFINED_suseconds_t)
#define __DEFINED_suseconds_t
#endif

#ifdef __NEED_int8_t
typedef signed char int8_t;
#endif
#if defined(__NEED_int8_t) && !defined(__DEFINED_int8_t)
#define __DEFINED_int8_t
#endif

#ifdef __NEED_int16_t
typedef signed short int16_t;
#endif
#if defined(__NEED_int16_t) && !defined(__DEFINED_int16_t)
#define __DEFINED_int16_t
#endif

#ifdef __NEED_int32_t
typedef signed int int32_t;
#endif
#if defined(__NEED_int32_t) && !defined(__DEFINED_int32_t)
#define __DEFINED_int32_t
#endif

#ifdef __NEED_int64_t
typedef signed long long int64_t;
#endif
#if defined(__NEED_int64_t) && !defined(__DEFINED_int64_t)
#define __DEFINED_int64_t
#endif

#ifdef __NEED_intmax_t
typedef signed long long intmax_t;
#endif
#if defined(__NEED_intmax_t) && !defined(__DEFINED_intmax_t)
#define __DEFINED_intmax_t
#endif

#ifdef __NEED_uint8_t
typedef unsigned char uint8_t;
#endif
#if defined(__NEED_uint8_t) && !defined(__DEFINED_uint8_t)
#define __DEFINED_uint8_t
#endif

#ifdef __NEED_uint16_t
typedef unsigned short uint16_t;
#endif
#if defined(__NEED_uint16_t) && !defined(__DEFINED_uint16_t)
#define __DEFINED_uint16_t
#endif

#ifdef __NEED_uint32_t
typedef unsigned int uint32_t;
#endif
#if defined(__NEED_uint32_t) && !defined(__DEFINED_uint32_t)
#define __DEFINED_uint32_t
#endif

#ifdef __NEED_uint64_t
typedef unsigned long long uint64_t;
#endif
#if defined(__NEED_uint64_t) && !defined(__DEFINED_uint64_t)
#define __DEFINED_uint64_t
#endif

#ifdef __NEED_u_int64_t
typedef unsigned long long u_int64_t;
#endif
#if defined(__NEED_u_int64_t) && !defined(__DEFINED_u_int64_t)
#define __DEFINED_u_int64_t
#endif

#ifdef __NEED_uintmax_t
typedef unsigned long long uintmax_t;
#endif
#if defined(__NEED_uintmax_t) && !defined(__DEFINED_uintmax_t)
#define __DEFINED_uintmax_t
#endif

#ifdef __NEED_mode_t
typedef unsigned mode_t;
#endif
#if defined(__NEED_mode_t) && !defined(__DEFINED_mode_t)
#define __DEFINED_mode_t
#endif

#ifdef __NEED_nlink_t
typedef unsigned int nlink_t;
#endif
#if defined(__NEED_nlink_t) && !defined(__DEFINED_nlink_t)
#define __DEFINED_nlink_t
#endif

#ifdef __NEED_off_t
typedef long long off_t;
#endif
#if defined(__NEED_off_t) && !defined(__DEFINED_off_t)
#define __DEFINED_off_t
#endif

#ifdef __NEED_ino_t
typedef unsigned long long ino_t;
#endif
#if defined(__NEED_ino_t) && !defined(__DEFINED_ino_t)
#define __DEFINED_ino_t
#endif

#ifdef __NEED_dev_t
typedef unsigned long long dev_t;
#endif
#if defined(__NEED_dev_t) && !defined(__DEFINED_dev_t)
#define __DEFINED_dev_t
#endif

#ifdef __NEED_blksize_t
typedef long blksize_t;
#endif
#if defined(__NEED_blksize_t) && !defined(__DEFINED_blksize_t)
#define __DEFINED_blksize_t
#endif

#ifdef __NEED_blkcnt_t
typedef long long blkcnt_t;
#endif
#if defined(__NEED_blkcnt_t) && !defined(__DEFINED_blkcnt_t)
#define __DEFINED_blkcnt_t
#endif

#ifdef __NEED_fsblkcnt_t
typedef unsigned long long fsblkcnt_t;
#endif
#if defined(__NEED_fsblkcnt_t) && !defined(__DEFINED_fsblkcnt_t)
#define __DEFINED_fsblkcnt_t
#endif

#ifdef __NEED_fsfilcnt_t
typedef unsigned long long fsfilcnt_t;
#endif
#if defined(__NEED_fsfilcnt_t) && !defined(__DEFINED_fsfilcnt_t)
#define __DEFINED_fsfilcnt_t
#endif

#ifdef __NEED_wint_t
typedef unsigned wint_t;
#endif
#if defined(__NEED_wint_t) && !defined(__DEFINED_wint_t)
#define __DEFINED_wint_t
#endif

#ifdef __NEED_wctype_t
typedef unsigned long wctype_t;
#endif
#if defined(__NEED_wctype_t) && !defined(__DEFINED_wctype_t)
#define __DEFINED_wctype_t
#endif

#ifdef __NEED_timer_t
typedef void * timer_t;
#endif
#if defined(__NEED_timer_t) && !defined(__DEFINED_timer_t)
#define __DEFINED_timer_t
#endif

#ifdef __NEED_clockid_t
typedef int clockid_t;
#endif
#if defined(__NEED_clockid_t) && !defined(__DEFINED_clockid_t)
#define __DEFINED_clockid_t
#endif

#ifdef __NEED_clock_t
typedef long clock_t;
#endif
#if defined(__NEED_clock_t) && !defined(__DEFINED_clock_t)
#define __DEFINED_clock_t
#endif

#ifdef __NEED_struct_timeval
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif
#if defined(__NEED_struct_timeval) && !defined(__DEFINED_struct_timeval)
#define __DEFINED_struct_timeval
#endif

#ifdef __NEED_struct_timespec
struct timespec { time_t tv_sec; long tv_nsec; };
#endif
#if defined(__NEED_struct_timespec) && !defined(__DEFINED_struct_timespec)
#define __DEFINED_struct_timespec
#endif

#ifdef __NEED_pid_t
typedef int pid_t;
#endif
#if defined(__NEED_pid_t) && !defined(__DEFINED_pid_t)
#define __DEFINED_pid_t
#endif

#ifdef __NEED_id_t
typedef unsigned id_t;
#endif
#if defined(__NEED_id_t) && !defined(__DEFINED_id_t)
#define __DEFINED_id_t
#endif

#ifdef __NEED_uid_t
typedef unsigned uid_t;
#endif
#if defined(__NEED_uid_t) && !defined(__DEFINED_uid_t)
#define __DEFINED_uid_t
#endif

#ifdef __NEED_gid_t
typedef unsigned gid_t;
#endif
#if defined(__NEED_gid_t) && !defined(__DEFINED_gid_t)
#define __DEFINED_gid_t
#endif

#ifdef __NEED_key_t
typedef int key_t;
#endif
#if defined(__NEED_key_t) && !defined(__DEFINED_key_t)
#define __DEFINED_key_t
#endif

#ifdef __NEED_useconds_t
typedef unsigned useconds_t;
#endif
#if defined(__NEED_useconds_t) && !defined(__DEFINED_useconds_t)
#define __DEFINED_useconds_t
#endif

#ifdef __NEED_pthread_t
#ifdef __cplusplus
typedef unsigned long pthread_t;
#else
typedef struct __pthread * pthread_t;
#endif
#endif
#if defined(__NEED_pthread_t) && !defined(__DEFINED_pthread_t)
#define __DEFINED_pthread_t
#endif

#ifdef __NEED_pthread_once_t
typedef int pthread_once_t;
#endif

#ifdef __NEED_pthread_key_t
typedef unsigned pthread_key_t;
#endif

#ifdef __NEED_pthread_spinlock_t
typedef int pthread_spinlock_t;
#endif

#ifdef __NEED_pthread_mutexattr_t
typedef struct { unsigned __attr; } pthread_mutexattr_t;
#endif

#ifdef __NEED_pthread_condattr_t
typedef struct { unsigned __attr; } pthread_condattr_t;
#endif

#ifdef __NEED_pthread_barrierattr_t
typedef struct { unsigned __attr; } pthread_barrierattr_t;
#endif

#ifdef __NEED_pthread_rwlockattr_t
typedef struct { unsigned __attr[2]; } pthread_rwlockattr_t;
#endif

#ifdef __NEED_FILE
struct _IO_FILE { char __x; };
typedef struct _IO_FILE FILE;
#endif
#if defined(__NEED_FILE) && !defined(__DEFINED_FILE)
#define __DEFINED_FILE
#endif

#ifdef __NEED_va_list
typedef __builtin_va_list va_list;
#endif
#if defined(__NEED_va_list) && !defined(__DEFINED_va_list)
#define __DEFINED_va_list
#endif

#ifdef __NEED___isoc_va_list
#ifndef __DEFINED___isoc_va_list
typedef __builtin_va_list __isoc_va_list;
#define __DEFINED___isoc_va_list
#endif
#endif

#ifdef __NEED_mbstate_t
typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;
#endif
#if defined(__NEED_mbstate_t) && !defined(__DEFINED_mbstate_t)
#define __DEFINED_mbstate_t
#endif

#ifdef __NEED_locale_t
typedef struct __locale_struct * locale_t;
#endif
#if defined(__NEED_locale_t) && !defined(__DEFINED_locale_t)
#define __DEFINED_locale_t
#endif

#ifdef __NEED_sigset_t
typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;
#endif
#if defined(__NEED_sigset_t) && !defined(__DEFINED_sigset_t)
#define __DEFINED_sigset_t
#endif

#ifdef __NEED_struct_iovec
struct iovec { void *iov_base; size_t iov_len; };
#endif
#if defined(__NEED_struct_iovec) && !defined(__DEFINED_struct_iovec)
#define __DEFINED_struct_iovec
#endif

#ifdef __NEED_socklen_t
typedef unsigned socklen_t;
#endif

#ifdef __NEED_sa_family_t
typedef unsigned short sa_family_t;
#endif

#ifdef __NEED_pthread_attr_t
typedef struct { union { int __i[9]; volatile int __vi[9]; unsigned long __s[9]; } __u; } pthread_attr_t;
#endif

#ifdef __NEED_pthread_mutex_t
typedef struct { union { int __i[6]; volatile int __vi[6]; volatile void *volatile __p[6]; } __u; } pthread_mutex_t;
#endif

#ifdef __NEED_mtx_t
typedef struct { union { int __i[6]; volatile int __vi[6]; volatile void *volatile __p[6]; } __u; } mtx_t;
#endif

#ifdef __NEED_pthread_cond_t
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[12*sizeof(int)/sizeof(void*)]; } __u; } pthread_cond_t;
#endif

#ifdef __NEED_cnd_t
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[12*sizeof(int)/sizeof(void*)]; } __u; } cnd_t;
#endif

#ifdef __NEED_pthread_rwlock_t
typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[8]; } __u; } pthread_rwlock_t;
#endif

#ifdef __NEED_pthread_barrier_t
typedef struct { union { int __i[5]; volatile int __vi[5]; void *__p[5]; } __u; } pthread_barrier_t;
#endif

#ifndef __cplusplus
#ifdef __NEED_wchar_t
typedef int wchar_t;
#endif
#if defined(__NEED_wchar_t) && !defined(__DEFINED_wchar_t)
#define __DEFINED_wchar_t
#endif
#endif

#ifdef __NEED_float_t
typedef float float_t;
#endif
#if defined(__NEED_float_t) && !defined(__DEFINED_float_t)
#define __DEFINED_float_t
#endif

#ifdef __NEED_double_t
typedef double double_t;
#endif
#if defined(__NEED_double_t) && !defined(__DEFINED_double_t)
#define __DEFINED_double_t
#endif

#ifdef __NEED_max_align_t
typedef struct { long long __ll; long double __ld; } max_align_t;
#endif
#if defined(__NEED_max_align_t) && !defined(__DEFINED_max_align_t)
#define __DEFINED_max_align_t
#endif

#if defined(__NEED_struct_winsize)
struct winsize { unsigned short ws_row, ws_col, ws_xpixel, ws_ypixel; };
#endif
