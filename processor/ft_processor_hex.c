#include "../printf.h"

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