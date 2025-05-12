/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:41:08 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/10 13:45:11 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list *stack)
{
	int	max_bits;
	int	max_index;

	max_bits = 0;
	max_index = stack_len(stack) - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	len;
	int	max_bits;

	i = 0;
	len = stack_len(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < len)
		{
			if (((*stack_a)->index >> i) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a');
		i++;
	}
}
