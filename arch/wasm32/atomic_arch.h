/* No-op atomics for single-threaded WASM */

#define a_ll a_ll
static inline int a_ll(volatile int *p)
{
	return *p;
}

#define a_sc a_sc
static inline int a_sc(volatile int *p, int v)
{
	*p = v;
	return 1;
}

#define a_barrier a_barrier
static inline void a_barrier()
{
}

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	int old = *p;
	if (old == t) *p = s;
	return old;
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
	void *old = *(void *volatile *)p;
	if (old == t) *(void *volatile *)p = s;
	return old;
}

#define a_swap a_swap
static inline int a_swap(volatile int *p, int v)
{
	int old = *p;
	*p = v;
	return old;
}

#define a_fetch_add a_fetch_add
static inline int a_fetch_add(volatile int *p, int v)
{
	int old = *p;
	*p += v;
	return old;
}

#define a_and a_and
static inline void a_and(volatile int *p, int v)
{
	*p &= v;
}

#define a_or a_or
static inline void a_or(volatile int *p, int v)
{
	*p |= v;
}

#define a_store a_store
static inline void a_store(volatile int *p, int v)
{
	*p = v;
}

#define a_ctz_32 a_ctz_32
static inline int a_ctz_32(uint32_t x)
{
	return __builtin_ctz(x);
}

#define a_ctz_64 a_ctz_64
static inline int a_ctz_64(uint64_t x)
{
	return __builtin_ctzll(x);
}

#define a_clz_64 a_clz_64
static inline int a_clz_64(uint64_t x)
{
	return __builtin_clzll(x);
}
