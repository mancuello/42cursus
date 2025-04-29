/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:48:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/28 21:28:31 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_list(t_list *stack)
{
	while (stack)
	{
		ft_printf("%i", stack->index);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*head_dir;
	unsigned int	i = 1;
	
	if (argc == 1)
	{
		return (1);
	}
	else
	{
		while (argv[i])
		{
			if (i == 1)
			{
				head_dir = ft_lstnew(atoi(argv[i++]));
				stack_a = head_dir;
			}
			else
			{
				stack_a->next = ft_lstnew(atoi(argv[i++]));
				stack_a = stack_a->next;
			}
		}
		stack_a = head_dir;
		normalize_stack(stack_a);
		//print_list(stack_a);
		radix_sort(&stack_a, &stack_b);
	}
	return (0);
}
