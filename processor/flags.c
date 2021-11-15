#include "ft_printf.h"

int flag_precision(const char *str, int i, t_flags *flags, va_list args)
{
    int index;

    index = i;
    index++;
    if (str[i] == '*')
    {
        flags->precision = va_arg(args, int);
        index++
    }
    else
    {
        flags->precision = 0;
        while (ft_isdigit(str[i]))
            flags->precision = (flags->precision*10) + (str[index++] - '0');
    }
    return(index)
}

t_flags flag_minus(t_flags flags)
{
    flags.minus = 1;
    flags.zero = 0;
    return (flags);    
}

t_flags flag_width(va_list args,t_flags flags)
{
    flags.star = 1;
    flags.width = va_arg(args, int);
    if (flags.width < 0)
    {
        flags.minus = 1;
        flags.width *= (-1);
        flags.zero = 0;
    }
    return (flags);
}

t_flags flag_digit(char s, t_flags flags)
{
    if (flags->star == 1)
        flags.width = 0;
    flags.width = flags.width * 10 + (s - '0');
} 