#include "ft_printf.h"
#include <limits.h>

int  main(void)
{
	//char	var = NULL; 
	ft_printf("El texto %i %i %u  aca", INT_MAX, INT_MIN, UINT_MAX);
	return (0);
}