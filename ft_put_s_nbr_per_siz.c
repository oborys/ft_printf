#include "ft_printf.h"

void		ft_putpercent(int *i)
{
	write(1, "%", 1);
	(*i)++;
	g_symb++;
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
	g_symb++;
}

void		ft_putstr(char const *s)
{
	unsigned long	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		g_symb++;
	}
}

void		ft_putnbr(uintmax_t n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		g_symb++;
	}
}

size_t		ft_strlen(const char *s)
{
	size_t		size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
