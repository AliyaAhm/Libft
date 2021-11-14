#include "../printf.h"

int ft_processor_char(char c, t_flags flags)
{
    int len;

    len = 0;
    if (minus == 1)
    {
        ft_putchar(c);
        len = ft_pr_width(flags, 1, 0);
    }
    if (minus == 0)
        ft_putchar(c);
    return (len + 1);
}