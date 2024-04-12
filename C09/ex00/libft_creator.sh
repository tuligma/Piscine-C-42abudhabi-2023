#!/bin/bash

# assign functions file into a variable
source_file=("ft_putchar.c" "ft_swap.c" "ft_putstr.c" "ft_strlen.c" "ft_strcmp.c")

# compile to generate object file using for loop
for file in "${source_file[@]}"; do
	cc -Wall -Wextra -Werror -c "$file"
done

# create the library by archiving the object files
ar rcs libft.a *.o
 
# remove the object files
rm -f *.o

echo "libft.a library has been created successfully"