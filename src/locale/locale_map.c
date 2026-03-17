#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "locale_impl.h"
#include "libc.h"

/* WASM: No filesystem-based locale loading.
 * Always returns the built-in C/UTF-8 locale. */

const char *__lctrans_impl(const char *msg, const struct __locale_map *lm)
{
	const char *trans = 0;
	if (lm) trans = __mo_lookup(lm->map, lm->map_size, msg);
	return trans ? trans : msg;
}

volatile int __locale_lock[1];
volatile int *const __locale_lockptr = __locale_lock;

const struct __locale_map *__get_locale(int cat, const char *val)
{
	if (cat == LC_CTYPE)
		return (void *)&__c_dot_utf8;
	return 0;
}
