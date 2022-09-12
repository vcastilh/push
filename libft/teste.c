#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int		s_int;
	long	s_lg;

	//Test atoi and atol behaviour
	s_int = ft_atoi(ft_strdup("2147483648"));
	if (s_int <= 2147483647)
		printf("atoi ok\n");
	else
		printf("atoi ko\n");
	
	s_lg = ft_atol(ft_strdup("2147483648"));
	if (s_lg >= 2147483647)
		printf("atol ok\n");
	else
		printf("atol ko\n");
	return (0);
}
