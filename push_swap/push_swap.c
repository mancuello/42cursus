/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:48:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/14 15:16:46 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_list **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, 'a');
}

static void	choose_alg(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len == 2)
		short_sort(stack_a);
	else if (len <= 10)
		turkish_sort(stack_a, stack_b);
	else if (len > 10 && len < 900)
		quick_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	stack_b = NULL;
	stack_a = parse_arg(args);
	if (!stack_a)
	{
		if (argc == 2)
			free_split(args);
		return (1);
	}
	normalize_stack(stack_a);
	choose_alg(&stack_a, &stack_b);
	free_all(stack_a),
	free_all(stack_b);
	if (argc == 2)
		free_split(args);
	return (0);
}
