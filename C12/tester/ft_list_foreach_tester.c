#include "../includes/tuligma_C12.h"

void	ft_strupcase(void *data)
{
	char *str;
	int	i;

	str = (char *)data;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}


void	free_list(t_list *current)
{
	t_list	*next;

	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void list_creation(t_list **node, t_list *current, char *argv[], int argc)
{
	int	x;

	x = 1;
	while (++x < argc)
	{
		*node = ft_create_elem(argv[x]);
		if (*node == NULL)
		{
			printf("Memory allocation fails.\n");
			return ;
		}
		current->next = *node;
		current = current->next;
	}
}

void	print_list(t_list *current)
{

	int	len;
	int	x;

	len = ft_list_size(current);
	x = -1;
	while (++x < len)
	{
		if (x == 0)
			printf("node%d| head:   	%p	| content:	\"%s\"	| pointing to:	%p	->	node%d\n\n", x + 1, current, (char *)current->data, current->next, x + 2);
		else if (x < len - 1)
			printf("node%d| address:	%p	| content:	\"%s\"	| pointing to:	%p	->	node%d\n\n", x + 1, current, (char *)current->data, current->next, x + 2);
		else
			printf("node%d| tail:   	%p	| content:	\"%s\"	| pointing to:	%p	\n\n", x + 1, current, (char *)current->data, current->next);
		current = current->next;
	}
	// printf("the total size of the list is %d\n\n", len);

}

int	main(int argc, char *argv[])
{
	t_list	*node;
	t_list	*head;
	t_list	*current;
	int		x;

	if (argc < 2)
	{
		printf("Please provide an argument to make a new node!\n");
		return (1);
	}
	x = 1;
	node = ft_create_elem(argv[x]);
	if (node == NULL)
	{
		printf("Memory allocation fails.\n");
		return (1);
	}
	head = node;
	current = head;
	list_creation(&node, current, argv, argc);
	if (node == NULL)
		return (1);
	printf("\nThe struct list: Before\n\n");
	current = head;
	print_list(current);
	ft_list_foreach(current, ft_strupcase);
	current = head;
	printf("\nThe struct list: After\n\n");
	print_list(current);
	free_list(current);
	return (0);
}