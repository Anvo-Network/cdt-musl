#include "stdio_impl.h"

/* No file descriptors in WASM */
int __stdio_close(FILE *f)
{
	return 0;
}
