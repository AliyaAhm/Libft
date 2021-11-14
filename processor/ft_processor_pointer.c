#include "../ft_printf.h"

int ft_processor_pointer(unsigned long long ar,t_flags flags)
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