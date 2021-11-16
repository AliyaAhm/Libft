#include "ft_printf.h"

t_flags init_flags(void)
{
    t_flags flags;

    flags.type = 0;
    flags.width = 0;
    flags.minus = 0;
    flags.zero = 0;
    flags.precision = -1;
    flags.star = 0;
    return(flags);
}

int parse_flag(const char *str, int i, t_flags *flags, va_list args)
{
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && !((str[i] == 'c') || (str[i] == 's') || (str[i] == 'p') 
        || (str[i] == 'd') || (str[i] == 'i') || (str[i] == 'u') || (str[i] == 'x') 
        || (str[i] == 'X') || (str[i] == '%')) && !((str[i] == '-') || (str[i] == ' ') 
        || (str[i] == '0') || (str[i] == '.') || (str[i] == '*')))
            break;
        if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
            flags->zero = 1;
        if (str[i] == '.')
            i = flag_precision(str, i, flags, args);
        if (str[i] == '-')
            *flags = flag_minus(*flags);
        if (str[i] == '*')
            *flags = flag_width(args, *flags);
        if (ft_isdigit(str[i]))
            *flags = flag_digit(str[i], *flags);
        if ((str[i] == 'c') || (str[i] == 's') || (str[i] == 'p') 
        || (str[i] == 'd') || (str[i] == 'i') || (str[i] == 'u') || (str[i] == 'x') 
        || (str[i] == 'X') || (str[i] == '%'))
        {
            flags->type = str[i];
            break;
        }
        i++;
    }
    return (i);
}

int parse_input(const char *str1, va_list args)
{
    int leng;
    t_flags flags;
    int i;

    leng = 0;
    i = 0;
    while (1)
    {
        flags = init_flags();
        if (!str1[i])
            break;
        else if (str1[i] == '%' && str1[i + 1])
        {
            i = parse_flag(str1, i, &flags, args);
            if ((str1[i] == 'c') || (str1[i] == 's') || (str1[i] == 'p') 
            || (str1[i] == 'd') || (str1[i] == 'i') || (str1[i] == 'u') 
            || (str1[i] == 'x') || (str1[i] == 'X') || (str1[i] == '%'))
                leng += processor((char)flags.type, args, flags);
        }
        else if (str1[i] != '%')
            {
                ft_putchar(str1[i]);
                leng++;
            }
        i++;
    }
    return (leng);
}