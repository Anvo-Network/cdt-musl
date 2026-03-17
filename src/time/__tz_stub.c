#include <time.h>
#include <string.h>

/* WASM stubs for timezone functions.
 * Contracts run in UTC with no timezone support. */

static const char utc[] = "UTC";

const char *__utc = utc;

const char *__tm_to_tzname(const struct tm *tm)
{
	return utc;
}

void __secs_to_zone(long long t, int local, int *isdst, long *offset,
                    long *oppoff, const char **zonename)
{
	*isdst = 0;
	*offset = 0;
	if (oppoff) *oppoff = 0;
	*zonename = utc;
}
