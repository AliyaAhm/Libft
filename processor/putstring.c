#include "../printf.h"

int putstring(char *str, t_flags flags)
{
    int len;

    len = 0;
    if (precision >=0 )
    {
        len += ft_pr_width(precision, ft_strlen(str)), 0);
        len += ft_putstrprec(str, precision);
    }
    else
    {
        len += ft_putstrprec(str, ft_strlen(str));
    }
    return (len);
}