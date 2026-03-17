/* Stub pthread for single-threaded WASM.
 * This header is included from pthread_impl.h AFTER the struct pthread
 * definition, so we can use it here. */

static inline struct pthread *__pthread_self(void)
{
	static struct pthread self;
	return &self;
}

#define TP_ADJ(p) (p)
#define MC_PC pc
