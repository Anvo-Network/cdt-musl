#include <stdlib.h>
#include <errno.h>

void *aligned_alloc(size_t alignment, size_t size)
{
	void *p;
	if (posix_memalign(&p, alignment, size))
		return 0;
	return p;
}
