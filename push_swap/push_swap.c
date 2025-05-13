/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:48:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/13 14:55:58 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_list **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, 'a');
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = parse_arg(argv);
	if (!stack_a)
		return (1);
	normalize_stack(stack_a);
	len = stack_len(stack_a);
	if (len == 2)
		short_sort(&stack_a);
	else if (len <= 10)
		turkish_sort(&stack_a, &stack_b);
	else
		quick_sort(&stack_a, &stack_b);
	free_all(stack_a),
	free_all(stack_b);
	return (0);
}
