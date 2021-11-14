#include "../rintf.h"

int		ft_putstrprec(char *str, int pr)
{
	int len;

	len = 0;
	while (str[len] && len < pr)
    {
		ft_putchar(str[len]);
        len++;
    }
	return (len);
}