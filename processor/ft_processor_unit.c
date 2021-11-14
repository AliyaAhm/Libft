#include "../printf.h"

static int ft_pr_unit(char *unit_str, t_flags flags)
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

int ft_processor_unit(unsigned int unit, t_flags flags)
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