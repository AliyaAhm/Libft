#include "ft_printf.h"

int ft_processor_string(char *str, t_flags flags)
{
    int len;

    len = 0;
    if (!str)
        str = "(null)";
    if (flags.precision >= 0 && (size_t)flags.precission > ft_strlen(str))
        flags.precision = ft_strlen(str);
    if (flags.minus == 1)
        len += putstring(str, flags);
    if (flags.precision >= 0)
        len += ft_pr_width(flags.width, flags.precision, 0);
    else
        len += ft_pr_width(flags.width, ft_strlen(str), 0);
    if (flags.minus == 0)
        len += putstring(str, flags);
    return (len);
}