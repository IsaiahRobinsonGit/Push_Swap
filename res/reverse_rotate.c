/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:05:31 by irobinso          #+#    #+#             */
/*   Updated: 2024/12/20 13:14:10 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Reverse rotate A (last element becomes first)
void	rra(t_stacks *stacks)
{
	int temp;
	int i;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	write(1, "rra\n", 4);
}

// Reverse rotate B (last element becomes first)
void	rrb(t_stacks *stacks)
{
	int temp;
	int i;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	write(1, "rrb\n", 4);
}

// rra and rrb at the same time
void	rrr(t_stacks *stacks)
{
	int temp;
	int i;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	temp = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	temp = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	write(1, "rrr\n", 4);
}
