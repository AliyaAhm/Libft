#include "ft_printf.h"

static int ft_pr_unit(char *unit_str, t_flags flags)
{
    int len;

    len = 0;
    if (flags.minus == 1)
    {
        if (flags.precision >= 0)
            len += ft_pr_width(flags.width, ft_strlen(unit_str), 0);
    ft_putstrprec(unit_str, ft_strlen(unit_str));
    }
        if (flags.precision >= 0 && (size_t)flags.precision <= ft_strlen(unit_str))
            flags.precision = ft_strlen(unit_str);
        if (flags.precision >= 0)
    {
        flags.width -= flags.precision;
        len += ft_pr_width(flags.width, 0, 0);
    }
    else
        len += ft_pr_width(flags.width, ft_strlen(unit_str), 0);
    if (flags.minus == 0)
    {
        if (flags.precision >= 0)
            len += ft_pr_width(flags.width, ft_strlen(unit_str), 1); // nepravilno
        len += ft_putstrprec(unit_str, ft_strlen(unit_str));
    }
    return (len);
}

int ft_processor_unit(unsigned int unit, t_flags flags)
{
    char *unit_str;
    int len;

    len = 0;
    unit = (unsigned int)(unit + 4294967295 + 1);
    if (flags.precision == 0 && unit == 0)
        len += ft_pr_width(flags.width, 0, 0);
    unit_str = ft_itoa(unit);
    len += ft_pr_unit(unit_str, flags);
    free (unit_str);
    return (len);
}