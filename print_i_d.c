#include "ft_printf.h"

void	printprecision(t_list *lst, uintmax_t i)
{
	int	r;

	r = (!lst->minus && !lst->plus) ? (lst->p_n - lst->nsymb)
		: (lst->p_n - lst->nsymb + 1);
	lst->nsymb = lst->nsymb + r;
	lst->minus ? (r--) : 0;
	lst->minus ? (lst->width--) : 0;
	(lst->conv != 9 && lst->conv != 10 && lst->minus != 1 && lst->plus != 1 &&
	lst->space == 1) ? ft_putchar(' ') : 0;
	(lst->conv != 9 && lst->conv != 10 && lst->minus != 1 && lst->plus != 1 &&
	lst->space == 1) ? (lst->width--) : 0;
	while (lst->width > lst->nsymb && lst->min == 0)
	{
		ft_putchar(' ');
		lst->width--;
	}
	(lst->minus) ? ft_putchar('-') : 0;
	(lst->plus && lst->minus != 1) ? ft_putchar('+') : 0;
	r++;
	while (--r)
		ft_putchar('0');
	ft_putnbr(i);
	print_p_add(lst);
}

void	printi(t_list *lst, void *nt)
{
	long	i;

	i = 0;
	conv_sm(lst, &i, nt);
	if (i == 0 && lst->p_n == 0)
	{
		print_d_i_null_p_n(lst);
		return ;
	}
	countnumsymb(lst, i);
	lst->rp = lst->plus;
	lst->rm = lst->minus;
	lst->nsymb0 = lst->nsymb;
	lst->plus ? (lst->nsymb0--) : 0;
	if (lst->p_n && (lst->p_n - lst->nsymb > 0))
	{
		printprecision(lst, i);
		return ;
	}
	if (lst->plus == 1 && lst->min == 1 && lst->p_n >= lst->nsymb)
	{
		print_p_m_symb(lst, i);
		return ;
	}
	printi_add_1(lst, i);
}

void	f(unsigned long value, int base1, char *str, int *i)
{
	char			*tmp;
	unsigned long	base;

	base = (unsigned long)base1;
	tmp = (char*)malloc(17);
	tmp = "0123456789ABCDEF";
	if (value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

void	f2(unsigned long value, int base1, char *str, int *i)
{
	char			*tmpl;
	unsigned long	base;

	base = (unsigned long)base1;
	tmpl = (char*)malloc(17);
	tmpl = "0123456789abcdef";
	if (value >= base)
		f2(value / base, base, str, i);
	str[(*i)++] = tmpl[(value % base)];
}

void	print_x(t_list *lst, void *nt, unsigned long base, int i)
{
	char			*str;
	unsigned long	value;

	value = 0;
	conv_sm_x_o(lst, &value, nt);
	str = (char*)malloc(32);
	if (lst->hash == 1 && (lst->conv == 7 || lst->conv == 8) && value != 0)
		str[i++] = '0';
	if (lst->conv == 12 || lst->conv == 7 || lst->conv == 8)
		f(value, base, str, &i);
	if (lst->conv == 11)
		f2(value, base, str, &i);
	str[i] = '\0';
	nul_x(str, lst);
}
