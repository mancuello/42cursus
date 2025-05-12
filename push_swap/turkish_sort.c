/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:10:19 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/12 23:31:24 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extra_checks(t_list *stack_b, unsigned int index)
{
	int	i;
	int	moves;

	moves = 0;
	if (min_index(stack_b, index))
		return (0);
	else
	{
		i = 1;
		while (!found_index(stack_b, index - i))
			i++;
		moves = moves_stack(stack_b, index - i);
		if (moves > stack_len(stack_b) / 2)
			moves -= stack_len(stack_b);
		return (moves);
	}
}

static int	exec_total_moves(t_list *stack_a, t_list *stack_b, int moves_a)
{
	int	moves_b;
	int	total_moves;

	if (stack_a->index == 0)
		moves_b = moves_stack(stack_b, find_max_index(stack_b)) + 1;
	else
		moves_b = extra_checks(stack_b, stack_a->index);
	if (moves_a > (stack_len(stack_a) / 2))
		moves_a -= stack_len(stack_a);
	total_moves = abs_value(moves_a) + abs_value(moves_b);
	return (total_moves);
}

static int	find_cheap(t_list *stack_a, t_list *stack_b)
{
	int		moves_a;
	int		total_moves;
	int		prev_moves;
	int		cheap;
	t_list	*temp;

	cheap = 0;
	prev_moves = 1000;
	moves_a = -1;
	temp = stack_a;
	while (temp)
	{
		moves_a++;
		total_moves = exec_total_moves(stack_a, stack_b, moves_a);
		if (total_moves < prev_moves)
		{
			prev_moves = total_moves;
			cheap = temp->index;
		}
		temp = temp->next;
	}
	return (cheap);
}

static void	to_stack_a(t_list **stack_a, t_list **stack_b)
{
	unsigned int	valor;

	while (*stack_b)
	{
		if ((*stack_b)->index > find_max_index(*stack_a))
			push(stack_b, stack_a, 'a');
		else
		{
			valor = (*stack_b)->index;
			single_rotations(moves_stack(*stack_a, valor + 1),
				stack_a, 'a');
			push(stack_b, stack_a, 'a');
		}
	}
}

void	turkish_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	cheap;

	len = stack_len(*stack_a);
	if (sorted(*stack_a))
		return ;
	initial_push(stack_a, stack_b, len);
	while (stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index > find_max_index(*stack_b))
			push(stack_a, stack_b, 'b');
		else
		{
			cheap = find_cheap(*stack_a, *stack_b);
			do_rotations(cheap, stack_a, stack_b);
			push(stack_a, stack_b, 'b');
			while (!reverse_sorted(*stack_b))
				final_check(stack_b, 'b');
		}
	}
	sort_stack(stack_a);
	to_stack_a(stack_a, stack_b);
	while (!sorted(*stack_a))
		rotate(stack_a, 'a');
}
