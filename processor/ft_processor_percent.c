#include "../printf.h"

int ft_processor_percent(t_flags flags)
{
    int len;

    len = 0;
    if (minus == 1)
        len += ft_putstrprec("%", 1);
    len += ft_pr_width(width, 1, zero);
    if (minus == 0)
        len += ft_putstrprec("%", 1);
    return (len);
}