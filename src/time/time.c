#include <time.h>
#include <stdint.h>

__attribute__((core_net_wasm_import))
extern uint64_t current_time(void);

time_t time(time_t *t)
{
	time_t elapsed = (time_t)(current_time() / 1000000LL);
	if (t) *t = elapsed;
	return elapsed;
}
