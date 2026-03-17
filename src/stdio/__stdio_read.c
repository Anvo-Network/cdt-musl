#include "stdio_impl.h"

/* No file input in WASM - always returns EOF */
size_t __stdio_read(FILE *f, unsigned char *buf, size_t len)
{
	f->flags |= F_EOF;
	return 0;
}
