#ifndef TULIGMA_H
#define TULIGMA_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <bsd/string.h>

int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);

#endif