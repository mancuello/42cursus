/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:03:55 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/09 17:37:06 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_value(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

int	sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	reverse_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->index < stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	moves_stack(t_list *stack, unsigned int index)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack;
	while (stack)
	{
		if (stack->index == index)
			break ;
		i++;
		stack = stack->next;
	}
	if (i > (stack_len(temp) / 2))
		i -= stack_len(temp);
	return (i);
}

void	final_check(t_list **stack, char x)
{
	unsigned int	last;
	unsigned int	first;
	t_list			*copy;

	copy = *stack;
	last = 0;
	first = (*stack)->index;
	while (copy)
	{
		last = (copy)->index;
		copy = (copy)->next;
	}
	if (x == 'a')
	{
		if (first > last)
			reverse_rotate(stack, 'a');
	}
	else if ( x == 'b')
	{
		if  (first < last)
			rotate(stack, 'b');
	}
}

void	sort_stack(t_list **stack)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && b < c && a < c)
		swap(stack, 'a');
	else if (a > b && b > c)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (a > b && b < c && a > c)
	{
		rotate(stack, 'a');
	}
	else if (a < b && b > c && a < c)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, 'a');
}
