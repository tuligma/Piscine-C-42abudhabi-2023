#include "../includes/tuligma_C04.h"


int	main(void)
{
	
	printf("\natoi vs ft_atoi\n");
	printf("\nstring: 	\"\\t\\n\\v\\f\\r      23\"");
	printf("\natoi:		(%d)", atoi("\t\n\v\f\r      23"));
	printf("\nft_atoi:	(%d)\n\n", ft_atoi("\t\n\v\f\r      23"));

	printf("\nstring: 	\"     ------+++++---12341\"");
	printf("\natoi:		(%d)", atoi("     ------+++++---12341"));
	printf("\nft_atoi:	(%d)\n\n", ft_atoi("     ------+++++---12341"));

	printf("\nstring: 	\"     ------+++++---123413abc\"");
	printf("\natoi:		(%d)", atoi("     ------+++++---123413abc"));
	printf("\nft_atoi:	(%d)\n\n", ft_atoi("     ------+++++---123413abc"));

	printf("\nstring: 	\"00000000002147483647\"");
	printf("\natoi:		(%d)", atoi("00000000002147483647"));
	printf("\nft_atoi:	(%d)\n\n", ft_atoi("00000000002147483647"));

	printf("\nstring: 	\"-2147483648\"");
	printf("\natoi:		(%d)", atoi("-2147483648"));
	printf("\nft_atoi:	(%d)\n\n", ft_atoi("-2147483648"));

	printf("\nstring: 	\"-21474xien83648\"");
	printf("\natoi:		(%d)", atoi("-21474xien83648"));
	printf("\nft_atoi:	(%d)\n\n", ft_atoi("-21474xien83648"));
	
	printf("\nstring: 	\"a\"");
	printf("\natoi:		(%d)", atoi("a"));
	printf("\nft_atoi:	(%d)\n\n", ft_atoi("a"));

	// printf("atoi:	%d\n", atoi("     ------+++++---12341"));
	// printf("ft_atoi:	%i\n", ft_atoi("     ------+++++---12341"));
	// printf("%i\n", ft_atoi("     ------+++++---123413"));
	// printf("%i\n", ft_atoi("00000000002147483647"));
	// printf("%i\n", ft_atoi("-2147483648"));
	// printf("%i\n", ft_atoi("a"));
}