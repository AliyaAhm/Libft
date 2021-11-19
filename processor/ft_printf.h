#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct  s_flags
{
    int type;
    int width;
    int minus;
    int zero;
    int precision;
    int star;
}   t_flags;

int ft_printf(const char *str, ...);
int ft_pr_width(int width, int minus, int zero);
int ft_processor_char(char c, t_flags flags);
int ft_processor_hex(unsigned int i, int height, t_flags flags);
int ft_processor_int(int i, t_flags flags);
int ft_processor_percent(t_flags flags);
int ft_processor_pointer(unsigned long long ar,t_flags flags);
int ft_processor_string(char *str, t_flags flags);
int ft_processor_unit(unsigned int unit, t_flags flags);
void	ft_putchar(int c);
int	ft_putstrprec(char *str, int pr);
int processor(int   type, va_list args, t_flags flags);
int putstring(char *str, t_flags flags);
char    *ft_ull_base(unsigned long long ull, int base);
int flag_precision(const char *str, int i, t_flags *flags, va_list args);
t_flags flag_minus(t_flags flags);
t_flags flag_width(va_list args,t_flags flags);
t_flags flag_digit(char s, t_flags flags);
int parse_flag(const char *str, int i, t_flags *flags, va_list args);
int parse_input(const char *str1, va_list args);
char	*ft_pitoa(unsigned int n);

#endif