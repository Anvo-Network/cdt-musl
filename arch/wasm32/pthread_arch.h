/* Stub pthread for single-threaded WASM */

static inline struct pthread *__pthread_self(void)
{
	static struct pthread self;
	return &self;
}

#define TP_ADJ(p) (p)
#define MC_PC pc
