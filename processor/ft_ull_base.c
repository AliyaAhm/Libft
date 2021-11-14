#include "../printf.h"

static char	*treat_base(unsigned long long ull, int base,
char *n, int len)
{
	while (ull != 0)
	{
		if ((ull % base) < 10)
			n[len] = (ull % base) + 48;
		else
			n[len] = (ull % base) + 87;
		ull /= base;
		len--;
	}
	return (n);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char				*n;
	unsigned long long	buff_ull;
	int					len;

	n = 0;
	len = 0;
	buf_ull = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		len++;
	}
    n = malloc(sizeof(char) * (len + 1));
	if (!n)
		return (0);
	n[len] = '\0';
	n = treat_base(buf_ull, base, n, (len - 1));
	return (n);
}

