#include <string.h>

int	segv_test(void)
{
	char	*s;

	s = NULL;
	return (strlen(s));
}
