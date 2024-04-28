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
	while (++x < argc)
	{
		node = ft_create_elem(argv[x]);
		if (node == NULL)
		{
			printf("Memory allocation fails.\n");
			return (1);
		}
		current->next = node;
		current = current->next;
	}
	printf("\nThe struct list:\n\n");
	current = head;
	print_list(current);
	free_list(current);
	return (0);
}