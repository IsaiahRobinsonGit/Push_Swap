/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:35:48 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/24 14:15:32 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
}

void	error_exit(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

static int is_sorted(int argc, char **argv)
{
	int		i;
	long	prev;
	long	curr;

	if (argc <= 2)  // Program name + 1 number is always sorted
		return (1);

	i = 1;  // Start from 1 to skip program name
	prev = ft_atol(argv[i]);

	while (++i < argc)
	{
		curr = ft_atol(argv[i]);
		if (curr < prev)
			return (0);  // Not sorted
		prev = curr;
	}
	return (1);  // Sorted
}


int first_check(char **argv)
{
	int i = 1;  // Start from 1 to skip the program name
	int j;

	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')  // Check for empty string
			return (0);
		if (argv[i][j] == '-' || argv[i][j] == '+')  // Handle sign
			j++;
		if (!argv[i][j])  // If string is only '-' or '+'
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_stacks	stacks;// declare stacks structure

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;

	if(!check_numbers_int(argv))
		return (0); // INT_MAX or INT_MIN PASSED
	if (!first_check(argv))
	{
		printf("letter found\n");
		return (0);
	}
	if (is_sorted(argc, argv))
	{
		return (0);
	}
	if (argc < 2 || (!check_args(argc, argv, &stacks)))// check if the arguments are valid
		error_exit(&stacks);
	printf("\nmax size: %d\n\n", stacks.max_size);
	printf("Before sorting:\n");
	print_stacks(&stacks);// print the stacks
	sorting(&stacks);
	printf("After sorting:\n\n");
	print_stacks(&stacks);// print the stacks
	free_stacks(&stacks);// clean before exit
	return (0);
}
