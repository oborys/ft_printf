#include "ft_printf.h"

void	printi_add_3(t_list *lst, long i)
{
	if (lst->minus == 1 && lst->nul != 1)
		ft_putchar('-');
	ft_putnbr(i);
	if (lst->rm == 1 || lst->rp == 1)
		lst->nsymb++;
	while (lst->width > lst->nsymb && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	(lst->width > (lst->plus + lst->nsymb0))
		&& !(lst->rm) ? ft_putchar(' ') : 0;
}

void	print_p_str_add(char *s, t_list *lst)
{
	ft_putstr("0x");
	while ((lst->width - 2 > lst->nsymb) && lst->nul == 1 && lst->min != 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	ft_putstr(s);
	while (lst->width - 2 > lst->nsymb && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	null_to_print(char *str, t_list *lst)
{
	if (lst->p_n >= 0)
		lst->nul = 0;
	print_xstr(str, lst);
}

int		len_n(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

void	print_p_add(t_list *lst)
{
	while (lst->min && lst->width > lst->nsymb)
	{
		ft_putchar(' ');
		lst->width--;
	}
}
