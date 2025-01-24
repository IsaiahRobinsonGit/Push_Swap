/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:36:33 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/08 23:36:09 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//find the minimum number in the stack
static int find_min(int *stack, int size)
{
	int min;
	int i;

	i = 0;
	min = stack[i];
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

// if there is only 2 numbers and the one before is bigger, swap.
int	sort_two(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
	{
		printf("sa\n");
		sa(stacks);
	}
	return (1);
}

//sort 3 numbers
int	sort_three(t_stacks *stacks)
{
	int a = stacks->stack_a[0];
	int b = stacks->stack_a[1];
	int c = stacks->stack_a[2];

	if (a > b && b < c && a < c)// 2 1 3
		sa(stacks);// swap first 2 elems
	else if (a > b && b > c)// 3 2 1
	{
		sa(stacks);// swap first 2 elems // 2 3 1
		rra(stacks);// bottom value goes to the top
	}
	else if (a > b && b < c && a > c)// 3 1 2
		ra(stacks);// top goes to bottom
	else if (a < b && b > c && a < c)// 1 3 2
	{
		sa(stacks);// swap first 2 elems // 3 1 2
		ra(stacks);// top goes to bottom
	}
	else if (a < b && b > c && a > c)// 2 3 1
		rra(stacks);// bottom goes to top
	return (1);
}

//sort 4 numbers
void sort_four(t_stacks *stacks)
{
	int min;
	int i;

	i = 0;
	min = find_min(stacks->stack_a, stacks->size_a);
	while (stacks->stack_a[0] != min)
	{
		if (i > stacks->size_a / 2)
			rra(stacks);
		else
			ra(stacks);
		i++;
	}
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

//sort 5 numbers
void sort_five(t_stacks *stacks)
{
	int min;
	int i;

	i = 0;
	min = find_min(stacks->stack_a, stacks->size_a);
	while (stacks->stack_a[0] != min)
	{
		if (i > stacks->size_a / 2)
			rra(stacks);
		else
			ra(stacks);
		i++;
	}
	pb(stacks);
	sort_four(stacks);
	pa(stacks);
}

static void radix_util(t_stacks *stacks, int bit_pos)
{
	int i;
	int size;

	i = 0;
	size = stacks->size_a;
	while (i < size)
	{
		if ((stacks->stack_a[0] >> bit_pos) & 1)
			ra(stacks);
		else
			pb(stacks);
		i++;
	}
	while (stacks->size_b)
		pa(stacks);
}

static int find_max(int *stack, int size)
{
	int max;
	int i;

	i = 0;
	max = stack[i];
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

void radix_sort(t_stacks *stacks)
{
	int max_bits;
	int max_num;
	int i;

	i = 0;
	max_num = find_max(stacks->stack_a, stacks->size_a);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		radix_util(stacks, i);
		i++;
	}
}

int	sorting(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		sort_two(stacks);
	if (stacks->size_a == 3)
		sort_three(stacks);
	if (stacks->size_a == 4)
		sort_four(stacks);
	if (stacks->size_a == 5)
		sort_five(stacks);
	if (stacks->size_a > 5)
		radix_sort(stacks);
	return (1);
}
