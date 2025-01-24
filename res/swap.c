/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:12:36 by irobinso          #+#    #+#             */
/*   Updated: 2024/12/20 13:14:51 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swap first two elements of stack A
void	sa(t_stacks *stacks)
{
	int temp;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	write(1, "sa\n", 3);
}

// Swap first two elements of stack B
void	sb(t_stacks *stacks)
{
	int temp;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
	write(1, "sb\n", 3);
}

// sa and sb at the same time
void	ss(t_stacks *stacks)
{
	int temp;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
	write(1, "ss\n", 3);
}
