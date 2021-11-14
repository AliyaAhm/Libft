#include "../printf.h"

int ft_processor_string(char *str, t_flags flags)
{
    int len;

    len = 0;
    if (!str)
        str = "(null)";
    if (precision >= 0 && (size_t)precission > ft_strlen(str))
        precision = ft_strlen(str);
    if (minus == 1)
        len += putstring(str, flags);
    if (precision >= 0)
        len += ft_pr_width(width, precision, 0);
    else
        len += ft_pr_width(width, ft_strlen(str), 0);
    if (minus == 0)
        len += putstring(str, flags);
    return (len);
}