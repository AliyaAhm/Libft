#include "ft_printf.h"

static int ft_part_hex(char *hex, t_flags flags)
{
    int len;

    len = 0;
    if (flags.minus == 1)
        {
            if (flags.precision >= 0)
                len += ft_pr_width(flags.width, 0, 0);
            len += ft_putstrprec(hex, ft_strlen(hex));
        }
    if (flags.precision >= 0 && flags.precision < (int)ft_strlen(hex))
        flags.precision = (int)ft_strlen(hex);
    if (flags.precision >= 0)
    {
        flags.width -= flags.precision;
        len += ft_pr_width(flags.width, 0, 0);
    }
    else
        len += ft_pr_width(flags.width, ft_strlen(hex), flags.zero);
    if (flags.minus == 0)
        {
            if (flags.precision >= 0)
                len += ft_pr_width(flags.width, 0, 0);
            len += ft_putstrprec(hex, ft_strlen(hex));
        }
    return(len);
}

int ft_processor_hex(unsigned int i, int height, t_flags flags)
{
    char    *hex;
    int     len;
    int     index;

    index = 0;
    len = 0;
    i = (unsigned int)(i + 4294967295 + 1);
    if (flags.precision == 0 && i == 0)
    {
        len += ft_pr_width(flags.width, 0, 0);
        return (len);
    }
    hex = ft_ull_base((unsigned long long)i, 16);
    if (height == 1)
        while (index < len)
        {
            hex[index] = ft_tolower(hex[index]);
            index++;
        }
    len = ft_part_hex(hex, flags);
    free(hex);
    return(len);
}