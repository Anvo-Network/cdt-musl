#include <stddef.h>

/* WASM: No filesystem - __map_file always fails */
const char unsigned *__map_file(const char *pathname, size_t *size)
{
	return 0;
}
