#include "../includes/tuligma_C03.h"

int	main()
{
	char *str;
	char *to_find;
	

	printf("\nstrstr vs ft_strstr\n");
	printf("\nTest 1");
	str = "xxxxxxxx";
	to_find = "";
	printf("\nstr string:		\"%s\" -> for strstr", str);
	printf("\nto_find string:		\"%s\" -> for ft_strstr", to_find);
	printf("\n------------------------------");
	printf("\nresult pos:		%s -> strstr", strstr(str, to_find));
	printf("\nresult pos:		%s -> ft_strstr\n\n", ft_strstr(str, to_find));

	printf("\nTest 2");
	str = "xyxyza";
	to_find = "xyz";
	printf("\nstr string:		\"%s\" -> for strstr", str);
	printf("\nto_find string:		\"%s\" -> for ft_strstr", to_find);
	printf("\n------------------------------");
	printf("\nresult pos:		%s -> strstr", strstr(str, to_find));
	printf("\nresult pos:		%s -> ft_strstr\n\n", ft_strstr(str, to_find));

	printf("\nTest 3");
	str = "xyxyaza";
	to_find = "xyz";
	printf("\nstr string:		\"%s\" -> for strstr", str);
	printf("\nto_find string:		\"%s\" -> for ft_strstr", to_find);
	printf("\n------------------------------");
	printf("\nresult pos:		%s -> strstr", strstr(str, to_find));
	printf("\nresult pos:		%s -> ft_strstr\n\n", ft_strstr(str, to_find));

	printf("\nTest 4");
	str = "xyxyza";
	to_find = "";
	printf("\nstr string:		\"%s\" -> for strstr", str);
	printf("\nto_find string:		\"%s\" -> for ft_strstr", to_find);
	printf("\n------------------------------");
	printf("\nresult pos:		%s -> strstr", strstr(str, to_find));
	printf("\nresult pos:		%s -> ft_strstr\n\n", ft_strstr(str, to_find));

	printf("\nTest 5");
	str = "";
	to_find = "";
	printf("\nstr string:		\"%s\" -> for strstr", str);
	printf("\nto_find string:		\"%s\" -> for ft_strstr", to_find);
	printf("\n------------------------------");
	printf("\nresult pos:		%s -> strstr", strstr(str, to_find));
	printf("\nresult pos:		%s -> ft_strstr\n\n", ft_strstr(str, to_find));

	printf("\nTest 6");
	str = "";
	to_find = "xxx";
	printf("\nstr string:		\"%s\" -> for strstr", str);
	printf("\nto_find string:		\"%s\" -> for ft_strstr", to_find);
	printf("\n------------------------------");
	printf("\nresult pos:		%s -> strstr", strstr(str, to_find));
	printf("\nresult pos:		%s -> ft_strstr\n\n", ft_strstr(str, to_find));

	
}