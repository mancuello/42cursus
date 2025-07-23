/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:04:18 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/14 18:29:41 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_list *stack, unsigned int index)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != index)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int		pos;

	pos = 0;
	while (*stack_b)
	{
		pos = get_position(*stack_b, find_max_index(*stack_b));
		if (pos <= stack_len(*stack_b) / 2)
		{
			while ((*stack_b)->index != find_max_index(*stack_b))
				rotate(stack_b, 'b');
		}
		else
		{
			while ((*stack_b)->index != find_max_index(*stack_b))
				reverse_rotate(stack_b, 'b');
		}
		push(stack_b, stack_a, 'a');
	}
}

void	to_stack_b(t_list **stack_a, t_list **stack_b, int chunk)
{
	unsigned int	min_index;
	unsigned int	limit;

	min_index = 0;
	limit = chunk;
	while (*stack_a)
	{
		if ((*stack_a)->index <= min_index)
		{
			push(stack_a, stack_b, 'b');
			min_index++;
		}
		else if ((*stack_a)->index <= limit)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			min_index++;
		}
		else
			rotate(stack_a, 'a');
		if (min_index == limit + 1)
			limit += chunk;
	}
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	int	chunk;

	chunk = 39;
	if (stack_len(*stack_a) <= 100)
		chunk = 16;
	to_stack_b(stack_a, stack_b, chunk);
	to_stack_a(stack_a, stack_b);
}
