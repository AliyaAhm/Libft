#include "processor/ft_printf.h"

int ft_printf(const char *str, ...)
{
    int len;
    const char    *s;
    va_list ap;

    len = 0;
    s = ft_strdup(str);
    va_start(ap, str);
    len += parse_input(s, ap);
    va_end(ap);
    free((char *)s);
    return (len);
}