#include "pthread_impl.h"

/* WASM stub: return the singleton thread struct */
void *__get_tp(void)
{
	return __pthread_self();
}
