#include <nl_types.h>

/* WASM: No message catalog support */
int catclose(nl_catd catd)
{
	return 0;
}
