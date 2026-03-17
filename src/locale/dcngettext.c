#include <libintl.h>
#include <string.h>
#include <errno.h>

/* WASM: No filesystem-based message catalog support.
 * Returns msgid1 or msgid2 directly (no translation). */

static char *dummy_gettextdomain(void)
{
	return "messages";
}

weak_alias(dummy_gettextdomain, __gettextdomain);

char *bindtextdomain(const char *domainname, const char *dirname)
{
	return (char *)dirname;
}

char *dcngettext(const char *domainname, const char *msgid1, const char *msgid2, unsigned long int n, int category)
{
	return (char *)((n == 1) ? msgid1 : msgid2);
}

char *dcgettext(const char *domainname, const char *msgid, int category)
{
	return (char *)msgid;
}

char *dngettext(const char *domainname, const char *msgid1, const char *msgid2, unsigned long int n)
{
	return dcngettext(domainname, msgid1, msgid2, n, 0);
}

char *dgettext(const char *domainname, const char *msgid)
{
	return (char *)msgid;
}
