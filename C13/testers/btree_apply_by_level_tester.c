#include "../includes/tuligma_C13.h"

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}


void	print_level(void *item, int current_level, int is_first)
{
	printf("Item:   	|%s|\n", (char *)item);
	printf("Level:		|%d|\n", current_level);
	printf("Element:	|%d|	<-- 1 if first element else if 0 then not\n", is_first);
	printf("Item after:   	|%s|\n\n", ft_strupcase(item));
}

int	ft_strcmp(void *data1, void *data2)
{
	char	*s1;
	char	*s2;

	s1 = (char *)data1;
	s2 = (char *)data2;
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	print_traversal(void *item)
{
	printf("\"%s\" -> ", (char *)item);
}

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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

void	print_btree(t_btree *root, int level, int *height)
{
	if (root == NULL)
        return ;
	printf("           |level:%d|\n", level);
    printf("           |Root: %s|\n", (char *)root->item);
	printf("          /            \\\n");
    if (root->left != NULL)
		printf("|Left:	%s|", (char *)root->left->item);
	else
        printf("|Left:  X|");
	
	if (root->right != NULL)
		printf("         |Right: %s|\n\n", (char *)root->right->item);
	else
		printf("	     |Right: X|\n\n");
	printf("\n");
	print_btree(root->left, level + 1, height);
	print_btree(root->right, level + 1, height);
	if (level > *height)
		*height = level;
}

char	**arg_to_malloc(int argc, char *argv[])
{
	char	**arr;
	int		x;

	arr = (char **)malloc(sizeof(char *) * (argc));
	if (arr == NULL)
		return (NULL);
	x = -1;
	while (++x < argc - 1)
	{
		arr[x] = ft_strdup(argv[x + 1]);
		if (arr[x] == NULL)
		{
			while (x > 0)
				free(arr[x--]);
			free(arr);
			return (NULL);
		}
	}
	arr[x] = NULL;
	return (arr);
}

void	free_list(char	**list, int size)
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
	void	*search;
	char	**list;
	int		x;
	int		btree_height;
	
	if (argc < 2)
		return (print_error_argument());
	list = arg_to_malloc(argc, argv);
	if (list == NULL)
		return (print_error_malloc());
	x = -1;
	printf ("\nList: {");
	while (list[++x] != NULL)
	{
		printf("\"%s\"", list[x]);
		if (list[x] != NULL)
			printf(", ");
		else
			printf("}");
	}
	x = -1;
	root = NULL;
	while (list[++x] != NULL)
	{	
		btree_insert_data(&root, list[x], ft_strcmp);
		if (root == NULL)
		{
			free_btree(root);
			return (print_error_malloc());
		}
	}
	printf("\n\nBinary Tree: \n\n");
	btree_height = -1;
	print_btree(root, 0, &btree_height);
	printf("Height of the tree is %d\n\n", btree_height);
	printf("Prefix Traversal: ");
	btree_apply_prefix(root, &print_traversal);
	printf("\nInfix Traversal:  ");
	btree_apply_infix(root, &print_traversal);
	printf("\nSuffix Traversal: ");
	btree_apply_suffix(root, &print_traversal);
	printf("\n\nSearching for item \"%s\"\n", "log");
	search = NULL;
	search = btree_search_item(root, (void *)"log", ft_strcmp);
	if (search == NULL)
		printf("\nNot found! %s\n\n", (char *)search);
	else
		printf("\nFound! %s\n\n", (char *)search);
	btree_apply_by_level(root, &print_level);
	free_btree(root);
	free_list(list, argc - 1);
	return (0);
}