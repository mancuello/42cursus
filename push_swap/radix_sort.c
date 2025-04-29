/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:20:56 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/28 22:08:32 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_mayor(t_list *stack)
{
	unsigned int	mayor;

	mayor = 0;
	while (stack)
	{
		if (stack->index > mayor)
			mayor = stack->index;
		stack = stack->next;
	}
	return (mayor);
}

unsigned int bits_quantity(unsigned int max)
{
    unsigned int bits ;
	
	bits = 0;
    while (max > 0)
    {
        bits++;
        max /= 2;
    }
    return bits;
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	unsigned int	max;
	unsigned int	i;
	unsigned int	len;
	unsigned int	j;
	unsigned int	bits;

	len = stack_len(*stack_a);
	max = find_mayor(*stack_a);
	bits = bits_quantity(max);
	j = 0;
	i = 0;
	while (i < bits)
	{
		while (j < len)
		{
			if (((*stack_a)->index >> i) & 1)
			{
				rotate(stack_a);
				write(1, "ra\n", 3);
			}
			else
			{
				push(stack_a, stack_b);
				write(1, "pb\n", 3);
			}
			j++;
		}
		while (*stack_b)
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
		}
		j = 0;
		i++;
	}
}
