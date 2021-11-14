#include "../printf.h"

t_flags init_flags(void)
{
    t_flags flags;

    type = 0;
    width = 0;
    minus = 0;
    zero = 0;
    precision = -1;
    star = 0;
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
        || (str[i] == 'X') || (str[i] == '%'));
        {
            flags->type = str[i];
            break;
        }
        i++;
    }
    return (i);
}