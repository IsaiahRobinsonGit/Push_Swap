/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:46:31 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 21:48:08 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_split(char **split_array)
{
	int	i;

	i = 0;
	if (!split_array)
		return ;
	while (split_array[i])
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}

static int	init_and_validate_stack(t_stacks *stacks, char **numbers, int count)
{
	int	i;

	stacks->stack_a = malloc(sizeof(int) * count);
	stacks->stack_b = malloc(sizeof(int) * count);
	if (!stacks->stack_a || !stacks->stack_b)
		return (0);
	i = 0;
	while (i < count)
	{
		if (!is_valid_number(numbers[i]))
		{
			free(stacks->stack_a);
			return (0);
		}
		stacks->stack_a[i] = ft_atol(numbers[i]);
		i++;
	}
	if (check_duplicates(stacks->stack_a, count))
	{
		free(stacks->stack_a);
		return (0);
	}
	stacks->size_a = count;
	stacks->size_b = 0;
	return (1);
}

int	check_numbers_int(char **numbers)
{
	int		i;
	long	num;

	i = 0;
	while (numbers[i])
	{
		num = ft_safe_atol(numbers[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			printf("error\n");
			exit(1);
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv, t_stacks *stacks)
{
	char	**numbers;
	int		num_count;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		num_count = count_numbers(argv[1]);
	}
	else if (argc > 2)
	{
		if (contains_space(argv + 1, argc - 1))
			return (0);
		numbers = argv + 1;
		num_count = argc - 1;
	}
	else
		return (0);
	if (!init_and_validate_stack(stacks, numbers, num_count))
		return (0);
	stacks->max_size = num_count;
	if (argc == 2)
		free_split(numbers);
	return (1);
}
