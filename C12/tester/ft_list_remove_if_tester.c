#include "../includes/tuligma_C12.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	free_fct(void *data)
{
	if (data != NULL)
	{
		free(data);
		data = NULL;
		return ;
	}
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		size;
	int		i;

	size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	**allocation(int argc, char *argv[])
{
	char 	**arr;
	int		x;
	int	i;

	x = 0;
	i = 0;
	arr = (char **)malloc(sizeof(char *) * argc);
	while (x < argc)
	{
		arr[x]= ft_strdup(argv[++i]);
		if (arr[x] == NULL)
		{
			while (i >= 0)
				free(arr[i--]);
			free(arr);
			arr = NULL;
			return (arr);
		}
		x++;
	}
	return (arr);
}

int	list_size(t_list *current)
{
	int	x;

	x = 0;
	while (current != NULL)
	{
		current = current->next;
		x++;
	}
	return (x);
}

void	print_list(t_list *current)
{

	int	len;
	int	x;

	len = list_size(current);
	x = -1;
	while (++x < len && current != NULL)
	{
		if (x == 0)
			printf("node%d| head:   	%p	| content:	\"%s\"	| pointing to:	%p	->	node%d\n\n", x + 1, current, (char *)current->data, current->next, x + 2);
		else if (x < len - 1)
			printf("node%d| address:	%p	| content:	\"%s\"	| pointing to:	%p	->	node%d\n\n", x + 1, current, (char *)current->data, current->next, x + 2);
		else
			printf("node%d| tail:   	%p	| content:	\"%s\"	| pointing to:	%p	\n\n", x + 1, current, (char *)current->data, current->next);
		current = current->next;
	}

}

int	main(int argc, char *argv[])
{
	t_list	*head;
	t_list	*current;
	char	**strs;

	if (argc < 2)
	{
		printf("Please provide an argument to make a new node!\n");
		return (1);
	}
	strs = allocation(argc - 1, argv);
	if (strs == NULL)
	{
		printf("Memory allocation fails.\n");
		return (1);
	}
	head = ft_list_push_strs(argc - 1, strs);
	if (head == NULL)
	{
		printf("Memory allocation fails.\n");
		return (1);
	}
	printf("\nThe struct list: Before\n\n");
	current = head;
	print_list(current);
	ft_list_remove_if(&head, (void *)"42", ft_strcmp, free_fct);
	printf("\nThe struct list: After\n\n");
	current = head;
	print_list(current);
	ft_list_clear(current, &free_fct);
	free(strs);
	printf("Successfully freed!\n\n");
	return (0);
}