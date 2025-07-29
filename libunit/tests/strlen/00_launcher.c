#include "../../framework/libunit.h"

int	ok_test(void);
int	ko_test(void);
int	segv_test(void);
int	bus_test(void);

int	strlen_launcher(void)
{
	t_unit_test	*list;

	list = NULL;
	load_test(&list, "OK test", &ok_test);
	load_test(&list, "KO test", &ko_test);
	load_test(&list, "SEGV test", &segv_test);
	load_test(&list, "BUS test", &bus_test);
	return (launch_tests(&list));
}
