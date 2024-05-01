#include "../includes/tuligma_C13.h"

int	print_error_argument(void)
{
	printf("\n\nPlease provide an argument to make a binary tree\n\n");
	return (1);
}

int	print_error_malloc(void)
{
	printf("\n\nMemory allocation failed!\n\n");
	return (1);
}

int	ft_atoi(char *str)
{
	int	x;
	int	state;
	int	result;

	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ' || str[x] == '\n')
		x++;
	state = 0;
	while (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			state++;
		x++;
	}
	result = 0;
	while (str[x] >= '0' && str[x] <= '9')
		result = result * 10 + (str[x++] - '0');
	if (state % 2)
		result *= -1;
	return (result);
}

void	print_btree(t_btree *root, int level, int *height)
{
	if (root == NULL)
        return ;
	printf("           |level:%d|\n", level);
    printf("           |Root: %d|\n", *((int*)(root->item)));
	printf("          /         \\\n");
    if (root->left != NULL)
		printf("|Left:	%d|", *((int*)(root->left->item)));
	else
        printf("|Left:  X|");
	
	if (root->right != NULL)
		printf("	     |Right: %d|\n\n", *((int*)(root->right->item)));
	else
		printf("	     |Right: X|\n\n");
	printf("\n");
	print_btree(root->left, level + 1, height);
	print_btree(root->right, level + 1, height);
	if (level > *height)
		*height = level;
}

void	insert_node(t_btree *root, t_btree *node)
{
	int	node_item;
	int	root_item;

	node_item = *((int *)(node->item));
	root_item = *((int *)(root->item));
	if (node_item < root_item)
	{
		if (root->left == NULL)
			root->left = node;
		else
			insert_node(root->left, node);
	}
	else
	{
		if (root->right == NULL)
			root->right = node;
		else
			insert_node(root->right, node);
	}
}

int	**arg_to_int(int argc, char *argv[])
{
	int	**arr;
	int		x;

	arr = (int **)malloc(sizeof(int *) * (argc - 1));
	if (arr == NULL)
		return (NULL);
	x = -1;
	while (++x < argc - 1)
	{
		arr[x] = (int *)malloc(sizeof(int));
		if (arr[x] == NULL)
		{
			while (x > 0)
				free(arr[x--]);
			free(arr);
			return (NULL);
		}
	
		*arr[x] = ft_atoi(argv[x + 1]);
	}
	return (arr);
}

void	free_list(int	**list, int size)
{
	int	x;

	x = -1;
	while (++x < size)
		free(list[x]);
	free(list);
	list = NULL;
}

void 	free_btree(t_btree *parent)
{
	if (parent == NULL)
		return ;
	free_btree(parent->left);
	free_btree(parent->right);
	free(parent);
}

int	main(int argc, char *argv[])
{
	t_btree	*root;
	t_btree *node;
	int	**list;
	int		x;
	int		btree_height;
	
	if (argc < 2)
		return (print_error_argument());
	list = arg_to_int(argc, argv);
	x = -1;
	printf ("\nList: {");
	while (++x < argc - 1)
	{
		printf("%d", *list[x]);
		if (x < argc - 2)
			printf(", ");
		else
			printf("}");
	}
	x = 0;
	root = btree_create_node(list[x]);
	if (root == NULL)
		return (print_error_malloc());
	while (++x < argc - 1)
	{
		node = btree_create_node(list[x]);
		if (node == NULL)
			return (print_error_malloc());
		insert_node(root, node);
	}
	printf("\n\nBinary Tree: \n\n");
	btree_height = -1;
	print_btree(root, 0, &btree_height);
	printf("Height of the tree is %d\n\n", btree_height);
	free_btree(root);
	free_list(list, argc - 1);
	return (0);
}