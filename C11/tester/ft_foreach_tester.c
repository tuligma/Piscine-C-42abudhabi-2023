#include "../includes/tuligma_C11.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}


int	main(void)
{

	int tab[100];
	int	x;
	
	x = -1;
	while (++x < 100)f
		tab[x] = x;
	ft_foreach(tab, 100, &ft_putnbr);
	printf("\n");
	return (0);
}