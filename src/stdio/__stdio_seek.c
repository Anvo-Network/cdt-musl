#include "stdio_impl.h"

/* No file seeking in WASM */
off_t __stdio_seek(FILE *f, off_t off, int whence)
{
	return -1;
}
