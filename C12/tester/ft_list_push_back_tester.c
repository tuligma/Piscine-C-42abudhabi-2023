#include "../includes/tuligma_C12.h"

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

void list_creation(t_list **node, t_list *current, char **list)
{
	int	x;

	x = 1;
	while (++x < 4)
	{
		*node = ft_create_elem(list[x]);
		if (*node == NULL)
		{
			printf("Memory allocation fails.\n");
			return ;
		}
		current->next = *node;
		current = current->next;
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
	char	*list[] = {"love", "42", "abu", "dhabi"};
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
	node = ft_create_elem(list[x]);
	if (node == NULL)
	{
		printf("Memory allocation fails.\n");
		return (1);
	}
	head = node;
	current = head;
	list_creation(&node, current, list);
	if (node == NULL)
		return (1);
	printf("\nThe struct list: Before\n\n");
	print_list(current);
	x = 0;
	while (++x < argc)
	{
		ft_list_push_back(&current, argv[x]);
		if (node == NULL)
		{
			printf("Memory allocation fails.\n");
			return (1);
		}
	}
	current = head;
	printf("\nThe struct list: After\n\n");
	print_list(current);
	free_list(current);
	return (0);
}