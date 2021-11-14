#include "printf.h"

//int g_result;
//int g_width;
//int g_dot;

/*int ft_pr_width(int width, int minus, int zero)
{
    int len;

    len = 0
    while(width - minus > 0)
    {
        if (zero)
            ft_putchar('0');
        else 
            ft_putchar(' ');
        width -= 1;
        len++;
    }
    return (len);
}

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


int putstring(char *str, t_flags flags)
{
    int len;

    len = 0;
    if (precision >=0 )
    {
        len += ft_pr_width(precision, ft_strlen(str)), 0);
        len += ft_putstrprec(str, precision);
    }
    else
    {
        len += ft_putstrprec(str, ft_strlen(str));
    }
    return (len);
}

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

int processor_pointer(unsigned long long ar,t_flags flags)
{
    int len;
    char *pointer;

    len = 0;
    if (ar == 0 && precision == 0)
    {
        len += ft_putstrprec("0x", 2);
        return (len += ft_pr_width(width, 0, 1));
    }
    pointer = ft_ull_base(ar, 16);
    len = 0;
    len += ft_putstrprec("0x", 2);
    if (precision >= 0)
    {
        len += ft_pr_width(precision, ft_strlen(pointer) + 2, 0);
        len += ft_putstrprec(pointer, precision);
    }
    else
        len += ft_putstrprec(pointer, precision);   
    free(pointer);
    return(len);
}

static int  ft_ret_part_int(char *string, int buff_i, t_flags flags)
{
    int len;

    len = 0;
    if (buff_i < 0 && precision >= 0 && i > 2147483648)
        ft_putchar('-');
    if (precision >= 0)
        len += ft_pr_width(precision - 1, ft_strlen(string) - 1, 0);
    len += ft_putstrprec(string, ft_strlen(string));
    return (len);
}

static int ft_part_int(char *string, int buff_i, int i, t_flags flags)
{
    if (minus == 1)
        len += ft_ret_part_int(string, buff_i, flags);
    if (precision >= 0, precision < ft_strlen(string))
        precision = ft_strlen(string);
    if (precision >= 0)
        {
            width -= precision;
            len = ft_pr_width(width, 0, 0);
        }
    else
        len += ft_pr_width(width, ft_strlen(string), zero);
    if (minus == 0)
        len += ft_ret_part_int(string, buff_i, flags);
    return (len);
}

int processor_int(int i, t_flags flags)
{
    int len;
    int buff_i; 
    char *string;

    len = 0;
    buff_i = i;
    if (precision == 0 && i == 0)
    {
        len += ft_pr_width(width, 0, 0);
        return(len);    
    }
    if (i < 0 && (precision >= 0 || zero == 1))
    {
        if (zero == 1 && precision < 0 && i > -2147483648)
            ft_putstrprec("-", 1);
        if (i = -2147483648)
            len = len - 1;
        i *= (-1);
        zero = 1;
        width = -1
        len += 1;
    }
string = ft_itoa(i);
len = ft_part_int(string, buff_i, flags);
free(string);
return(len)
}

int ft_pr_unit(char *unit_str, t_flags flags)
{
    if (minus == 1)
    {
        if (precision >= 0)
            len += ft_pr_width(width, ft_strlen(unit_str), 0);
    ft_putstrprec(unit_str, ft_strlen(unit_str));
    }
        if (precision >= 0 && precision <= ft_strlen(unit_str))
            precision = ft_strlen(unit_str);
        if (precision >= 0)
    {
        width -= precision;
        len += ft_pr_width(width, 0, 0);
    }
    else
        len += ft_pr_width(width, ft_strlen(unit_str), 0);
    if (minus == 0)
    {
        if (precision >= 0)
            len += ft_pr_width(width, ft_strlen(unit_str), 1); // nepravilno
        len += ft_putstrprec(unit_str, ft_strlen(unit_str));
    }
    return (len);
}

int processor_unit(unsigned int unit, t_flags flags)
{
    char *unit_str;
    int len;

    unit = (unsigned int)(unit + 4294967295 + 1);
    if (precision == 0 && unit == 0)
        len += ft_pr_width(width, 0, 0);
    unit_str = ft_itoa(unit);
    len += ft_pr_unit(unit_str, flags);
    free (unit);
    return (len);
}

static int ft_part_hex(char *hex, t_flags flags)
{
    int len;

    len = 0;
    if (minus == 1)
        {
            if (precision >= 0)
                len += ft_pr_width(width, 0, 0);
            len += ft_putstrprec(hex, ft_strlen(hex));
        }
    if (precision >= 0 && precision < ft_strlen(hex))
        precision = ft_strlen(hex);
    if (precision >= 0)
    {
        width -= precision;
        len += ft_pr_width(width, 0, 0);
    }
    else
        len += ft_pr_width(width, ft_strlen(hex), zero);
    if (minus == 0)
        len += ft_ret_part_hex(hex, flags);
    if (precision >= 0)
        len += ft_pr_width(width, 0, 0);
    len += ft_putstrprec(string, ft_strlen(string));
    return(len);
}

int ft_processor_hex(unsigned int i, int height, t_flags flags)
{
    char    *hex;
    int     len;
    int     index;

    index = 0;
    i = (unsigned int)(i + 4294967295 + 1);
    if (precision == 0 && i == 0)
    {
        len += ft_pr_width(width, 0, 0);
        return (len);
    }
    hex = ft_ull_base((unsigned long long)i, 16);
    if (height == 1)
        while (index < len)
        {
            hex[index] = ft_tolower(hex[index]);
            index++;
        }
    len = ft_part_hex(hex, flags); //
}

int ft_processor_percent(t_flags flags)
{
    int len;

    len = 0;
    if (minus == 1)
        len += ft_putstrprec("%", 1);
    len += ft_pr_width(width, 1, zero);
    if (minus == 0)
        len += ft_putstrprec("%", 1);
    return (len);
}

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
    minus = 1;
    zero = 0;
    return (flags);    
}

t_flags flag_width(va_list args,t_flags flags)
{
    star = 1;
    width = va_arg(args, int);
    if (width < 0)
    {
        minus = 1;
        width *= (-1);
        zero = 0;
    }
    return (flags);
}

t_flags flag_digit(char s, t_flags flags)
{
    if (flags->star == 1)
        width = 0;
    width = width * 10 + (s - '0');
} 

int parse_input(char *str1, va_list args)
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
}*/

int ft_printf(const char *str, ...)
{
    int len;
    const char    *s;
    va_list ap;

    len = 0;
    s = (const char *)str;
    va_start(ap, s);
    len = parse_input(s, ap);
    va_end(ap)
    return (len);
}