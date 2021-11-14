#include "../printf.h"

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

int ft_processor_int(int i, t_flags flags)
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