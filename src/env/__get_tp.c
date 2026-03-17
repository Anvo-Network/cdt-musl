/* WASM stub: return pointer to singleton thread struct.
 * Zero-initialized; single-threaded environment. */

static char __wasm_pthread[256]; /* oversized to cover struct pthread */

void *__get_tp(void)
{
	return __wasm_pthread;
}
