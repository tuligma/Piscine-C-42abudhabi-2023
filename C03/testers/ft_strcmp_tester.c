#include "../includes/tuligma_C03.h"

int	main()
{
	char	*s0;
	char	*s1;
	char	*s2;

	
	s0 = "";
	s1 = "abcadef";
	s2 = "abcadef";
	printf("\n Comparison of strcmp and ft_strcmp\n");
	printf("\n Strcmp	vs	ft_strcmp\n");
	printf("\n%d <-> %d	%s | %s\n", strcmp(s0, "a"), ft_strcmp(s0, "a"), s0, "a");
	printf("\n %d <-> %d %s | %s\n", strcmp(s1, s2), ft_strcmp(s1, s2), s1, s2);
	s1 = "abcadef";
	s2 = "abcad";
	printf("\n %d <-> %d %s | %s\n", strcmp(s1, s2), ft_strcmp(s1, s2), s1, s2);
	printf("\n %d <-> %d %s | %s\n", strcmp(s1, s2), ft_strcmp(s1, s2), s1, s2);
	s1 = "abcad";
	s2 = "abcadtg";
	printf("\n %d <-> %d %s | %s\n", strcmp(s1, s2), ft_strcmp(s1, s2), s1, s2);
	printf("\n %d <-> %d %s | %s\n\n", strcmp(s1, s2), ft_strcmp(s1, s2), s1, s2);
	return (0);
}