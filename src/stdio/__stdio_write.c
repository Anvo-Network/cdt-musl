#include "stdio_impl.h"

__attribute__((core_net_wasm_import))
extern void prints_l(const char *, unsigned int);

size_t __stdio_write(FILE *f, const unsigned char *buf, size_t len)
{
	size_t buf1 = f->wpos - f->wbase;
	if (buf1) prints_l((const char *)f->wbase, buf1);
	if (len) prints_l((const char *)buf, len);
	f->wend = f->buf + f->buf_size;
	f->wpos = f->wbase = f->buf;
	return buf1 + len;
}
