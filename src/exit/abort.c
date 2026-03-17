#include <stdlib.h>

_Noreturn void abort(void)
{
	/* In WASM, trigger an unreachable trap */
	__builtin_trap();
	/* Fallback - should never reach here */
	for (;;);
}
