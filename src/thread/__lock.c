/* No-op locking for single-threaded WASM */
void __lock(volatile int *l)
{
	*l = 1;
}

void __unlock(volatile int *l)
{
	*l = 0;
}
