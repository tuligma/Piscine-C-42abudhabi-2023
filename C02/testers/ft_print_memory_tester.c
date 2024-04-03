#include "../includes/tuligma_C02.h"

int	main()
{
	// unsigned char src[] = "Hello, th\tis is a \nstring wi\reth so\rme non-pr\027nt\able cha\racters:";
	char str1[] = "Bonjour les amin";
	char str2[] = "ches\t\n\tc  est fo";
	char str3[] = "u\ttout\tce qu on ";
	char str4[] = "peut faire avec\t";
	char str5[] = "\n\tprint_memory\n\n";
	char str6[] ="\n\tlol.lol\n \0";

	// ft_print_memory((void *)src, 16);
	// printf("printf address:		%p\n", str1);
	// fflush(stdout);
	ft_print_memory((void *)str1, sizeof(str1));
	ft_print_memory((void *)str2, sizeof(str2));
	ft_print_memory((void *)str3, sizeof(str3));
	ft_print_memory((void *)str4, sizeof(str4));
	ft_print_memory((void *)str5, sizeof(str5));
	ft_print_memory((void *)str6, sizeof(str6));
	// printf("%ld\n", sizeof(str1));
	// printf("%ld\n", sizeof(str2));
	// printf("%ld\n", sizeof(str3));
	// printf("%ld\n", sizeof(str4));
	// printf("%ld\n", sizeof(str5));
	// printf("%ld\n", sizeof(str6));
}