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

int	arrlen(char **list)
{
	int	x;

	x = 0;
	while (list[x] != NULL)
		x++;
	return x;
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

t_list  *list_creation(char **list)
{
	t_list	*current;
	t_list	*head;
	t_list	*node;
	t_list	*temp;
	int	x;

	x = 0;
	node = ft_create_elem(list[x]);
	if (node == NULL)
	{
		printf("Memory allocation fails.\n");
		return (NULL);
	}
	head = node;
	current = head;
	while (list[++x] != NULL)
	{
		node = ft_create_elem(list[x]);
		if (node == NULL)
		{
			printf("Memory allocation fails.\n");
			while (x > 0)
			{
					temp = current;
					current = current->next;
					free(temp);
				x--;
			}
			return (NULL);
		}
		current->next = node;
		current = current->next;
	}
	return (head);
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
			printf("node%d	|	head:   	%p	|	content:	\"%s\"      	|	pointing to:	%p	->	node%d\n\n", x + 1, current, (char *)current->data, current->next, x + 2);
		else if (x < len - 1)
			printf("node%d	|	address:	%p	|	content:	\"%s\"      	|	pointing to:	%p	->	node%d\n\n", x + 1, current, (char *)current->data, current->next, x + 2);
		else
			printf("node%d	|	tail:   	%p	|	content:	\"%s\"      	|	pointing to:	%p	\n\n", x + 1, current, (char *)current->data, current->next);
		current = current->next;
	}

}

int	main(void)
{
	char	*list1[] = {"I", "love", "42", "abu", "dhabi", "!", NULL};
	char	*list2[] = {"Apple", "Banana", "Watermelon", "Beet", "Melon", NULL};
	t_list	*head1;
	t_list	*head2;
	t_list	*current;
	t_list	*current2;

	head1 = NULL;
	head1 = list_creation(list1);
	if (head1 == NULL)
		return (1);
	head2 = list_creation(list2);
	if (head2 == NULL)
		return (1);
	current = head1;
	printf("\nThe struct list1:\n\n");
	print_list(current);
	current2 = head2;
	printf("\nThe struct list2:\n\n");
	print_list(current2);
	ft_list_sort(&head1, &ft_strcmp);
	ft_list_sort(&head2, &ft_strcmp);
	current = head1;
	printf("\nThe struct list1: Sorted\n\n");
	print_list(current);
	current2 = head2;
	printf("\nThe struct list2: Sorted\n\n");
	print_list(current2);
	ft_sorted_list_merge(&head1, head2, &ft_strcmp);
	current = head1;
	printf("\nThe struct merge list: Sorted\n\n");
	print_list(current);
	free_list(current);
	return (0);
}