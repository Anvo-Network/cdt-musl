/* WASM stub: provide __get_tp for single-threaded WASM.
 * pthread_impl.h defines __pthread_self() in terms of __get_tp(). */

void *__get_tp(void);

#define TP_ADJ(p) (p)
#define MC_PC pc
