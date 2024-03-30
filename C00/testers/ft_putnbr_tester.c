#include "../includes/tuligma.h"

int main()
{
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(-44);
	write(1, "\n", 1);
	ft_putnbr(-2147483649);
	write(1, "\n", 1);
	ft_putnbr(INT_MIN);
	write(1, "\n", 1);
	return (0);
}