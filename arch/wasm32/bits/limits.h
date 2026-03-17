#define PAGE_SIZE 65536

#ifdef CORE_NET_NATIVE
#define LONG_BIT 64
#define LONG_MAX 0x7fffffffffffffffL
#else
#define LONG_BIT 32
#define LONG_MAX 0x7fffffffL
#endif

#define LLONG_MAX 0x7fffffffffffffffLL
