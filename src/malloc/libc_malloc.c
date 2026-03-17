#include <stdlib.h>

/* __libc_malloc: internal alias for malloc used by musl internals.
 * In WASM, this simply forwards to the contract runtime's malloc. */
void *__libc_malloc(size_t n)
{
	return malloc(n);
}
