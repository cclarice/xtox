#include "xtox.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int c, char *v[])
{
	char	*str;

	if (c != 1)
		str = v[1];
	else
		str = "125";
	write(1, "<-Test->\n", 9);
	printf("Origin atoi   : %ld\n", atoi(str));
	printf("My Own atoi   : %ld\n", ft_atoi(str));
	write(1, "<->\n", 4);
	printf("Origin atol   : %ld\n", atol(str));
	printf("My Own atol   : %ld\n", ft_atol(str));
	write(1, "<->\n", 4);
	printf("!!!!!! strtoul: %ld\n", strtoul(str));
	printf("My Own strtoui: %ld\n", ft_strtoui(str));
	write(1, "<->\n", 4);
	printf("Origin strtoul: %ld\n", strtoul(str));
	printf("My Own strtoul: %ld\n", ft_strtoul(str));
	write(1, "<-Done->\n", 9);
	return (0);
}