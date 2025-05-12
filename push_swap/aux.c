/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:27:59 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/12 23:35:06 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_value(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

void	initial_push(t_list **stack_a, t_list **stack_b, int len)
{
	if (len >= 5)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap(stack_a, 'a');
		push(stack_a, stack_b, 'b');
		push(stack_a, stack_b, 'b');
	}
	else if (len == 4)
		push(stack_a, stack_b, 'b');
}

int	min_index(t_list *stack, unsigned int index)
{
	while (stack)
	{
		if (stack->index < index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	found_index(t_list *stack, unsigned int index)
{
	while (stack)
	{
		if (stack->index == index)
			return (1);
		stack = stack->next;
	}
	return (0);
}
