#include <signal.h>

int bus_test(void)
{
	raise(SIGBUS);
	return (0);
}
