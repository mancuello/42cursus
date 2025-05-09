/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:05:44 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/09 15:09:46 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	find_max_index(t_list *stack)
{
	unsigned int	max_index;

	max_index = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

void	single_rotations(int moves, t_list **stack, char x)
{
	while (moves != 0)
	{
		if (moves > 0)
		{
			rotate(stack, x);
			moves--;
		}
		else
		{
			reverse_rotate(stack, x);
			moves++;
		}
	}
}

static void	both_rotations(int *moves_a, int *moves_b,
	t_list **stack_a, t_list **stack_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		rotate_both(stack_a, stack_b, 1);
		(*moves_a)--;
		(*moves_b)--;
	}
	while (*moves_a < 0 && *moves_b < 0)
	{
		reverse_rotate_both(stack_a, stack_b, 1);
		(*moves_a)++;
		(*moves_b)++;
	}
}

void	do_rotations(int cheap, t_list **stack_a, t_list **stack_b)
{
	int				moves_a;
	int				moves_b;
	unsigned int	index_to_find;

	if (cheap == 0)
		index_to_find = find_max_index(*stack_b);
	index_to_find = cheap - 1;
	moves_a = moves_stack(*stack_a, (unsigned int)cheap);
	moves_b = moves_stack(*stack_b, index_to_find);
	both_rotations(&moves_a, &moves_b, stack_a, stack_b);
	single_rotations(moves_a, stack_a, 'a');
	single_rotations(moves_b, stack_b, 'b');
}
