#include <time.h>
#include <stdint.h>

#ifndef CORE_NET_NATIVE
__attribute__((core_net_wasm_import))
#endif
extern uint64_t current_time(void);

time_t time(time_t *t)
{
	time_t elapsed = (time_t)(current_time() / 1000000LL);
	if (t) *t = elapsed;
	return elapsed;
}
