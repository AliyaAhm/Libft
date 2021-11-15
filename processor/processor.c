#include "ft_printf.h"

int processor(int   type, va_list args, t_flags flags)
{
    int len;

    len = 0
    if (type[i] == 'c')
        len = len + ft_processor_char(va_arg(args, int), flags);
    else if (type[i] == 's')
        len = len + ft_processor_string(va_arg(args, char *), flags);
    else if (type[i] == 'p')
        len = len + ft_processor_pointer(va_arg(args, unsigned long long), flags);
    else if (type[i] == 'd' || type[i] == 'i')
        len = len + ft_processor_int(va_arg(args, int));
    else if (type[i] == 'u')
        len = len + ft_processor_unit((unsigned int)va_arg(args, unsigned int));
    else if (type[i] == 'x')
        len = len + ft_processor_hex(va_arg(args, unsigned int), 1, flags);
    else if (type[i] == 'X')
        len = len + ft_processor_hex1(va_arg(args, unsigned int), 0, flags);
    else if (type[i] == '%')
        len = len + ft_processor_percent(flags);
    return (len);
}