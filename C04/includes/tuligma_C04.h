#ifndef TULIGMA_H
#define TULIGMA_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <bsd/string.h>
#include <stddef.h>
#include <limits.h>

int	ft_strlen(char *str);
int	ft_putstr(char *str);
void	ft_putnbr(int nb);
int	ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);
int	ft_atoi_base(char *str, char *base);

#endif