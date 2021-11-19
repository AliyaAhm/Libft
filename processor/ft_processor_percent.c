#include "ft_printf.h"

int ft_processor_percent(t_flags flags)
{
    int len;

    len = 0;
    if (flags.minus == 1) 
        len += ft_putstrprec("%", 1);
    len += ft_pr_width(flags.width, 1, flags.zero);
    if (flags.minus == 0)
        len += ft_putstrprec("%", 1);
    return (len);
}