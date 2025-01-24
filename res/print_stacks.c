/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:52:15 by irobinso          #+#    #+#             */
/*   Updated: 2024/12/21 11:27:29 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Add this function to print both stacks (can be in push_swap.c or a new file)
void	print_stacks(t_stacks *stacks)
{
	int i;
	int max_size;

	max_size = (stacks->size_a > stacks->size_b) ?
				stacks->size_a : stacks->size_b;
	write(1, "\n", 1);
	write(1, "Stack A  Stack B\n", 17);
	write(1, "-------------------\n", 20);
	i = 0;
	while (i < max_size)
	{
		if (i < stacks->size_a)
			printf("%-7d ", stacks->stack_a[i]);
		else
			printf("		");
		if (i < stacks->size_b)
			printf("%d", stacks->stack_b[i]);
		printf("\n");
		i++;
	}
	write(1, "-------------------\n\n\n", 22);
}
