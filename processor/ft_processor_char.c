#include "ft_printf.h"

int ft_processor_char(char c, t_flags flags)
{
    int len;

    len = 0;
    if (flags.minus == 1)
    {
        ft_putchar(c);
        len = ft_pr_width(flags.width, 1, 0);
    }
    if (flags.minus == 0)
        ft_putchar(c);
    return (len + 1);
}