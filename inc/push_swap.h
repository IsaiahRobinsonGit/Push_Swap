/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:37:08 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/24 13:59:22 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libraries/libft/libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;// size of the stack
	int	size_b;// size of the stack
	int	max_size;// maximum size of the stack
}	t_stacks;

//---functions---//

int		check_args(int argc, char **argv, t_stacks *stacks);

long	ft_atol(const char *str);

void	free_stacks(t_stacks *stacks);

void	print_stacks(t_stacks *stacks);

void	radix_sort(t_stacks *stacks);

int		sorting(t_stacks *stacks);

int		check_numbers_int(char **numbers);


//int		limit_check(int argc, char **argv)

//---stack manipulation operations---//

//--reverse rotate--//
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//--rotate--//
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//--swap--/
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

//--push--//
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

#endif
