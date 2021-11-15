#include "ft_printf.h"

int parse_input(const char *str1, va_list args)
{
    int leng;
    t_flags flags;
    int i;

    leng = 0;
    i = 0;
    while (1)
    {
        flags = init_flags(t_flags);
        if (!str1[i])
            break;
        else if (str[i] == '%' && str1[i + 1])
        {
            i = parse_flag(str, i, &flags, args);
            if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') 
                || (c == 'i') || (c == 'u') || (c == 'x') 
                || (c == 'X') || (c == '%'));
                leng = leng + processor(str[i], args)
        }
        else if (str[i] != '%')
            {
                ft_putchar(str[i]);
                leng++;
            }
        i++;
    }
    return (leng);
}