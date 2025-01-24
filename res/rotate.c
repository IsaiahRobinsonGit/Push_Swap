/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:09:38 by irobinso          #+#    #+#             */
/*   Updated: 2024/12/20 13:14:27 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Rotate stack A (first element becomes last)
void	ra(t_stacks *stacks)
{
	int temp;
	int i;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
	write(1, "ra\n", 3);
}

// Rotate stack B (first element becomes last)
void	rb(t_stacks *stacks)
{
	int temp;
	int i;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
	write(1, "rb\n", 3);
}

// ra and rb at the same time
void	rr(t_stacks *stacks)
{
	int temp;
	int i;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	temp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
	temp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
	write(1, "rr\n", 3);
}
