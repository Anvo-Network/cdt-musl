#include <nl_types.h>
#include <errno.h>

/* WASM: No message catalog support */
nl_catd catopen(const char *name, int oflag)
{
	errno = ENOENT;
	return (nl_catd)-1;
}
