#include "stdio_impl.h"

/* No-op locking for single-threaded WASM */
int __lockfile(FILE *f)
{
	return 1;
}

void __unlockfile(FILE *f)
{
}
