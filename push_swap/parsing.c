/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:52:07 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/13 16:56:58 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	safe_atoi(char *arg, int *number)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!arg || !*arg)
		return (0);
	if (*arg == '-' || *arg == '+')
		if (*arg++ == '-')
			sign = -1;
	if (!*arg)
		return (0);
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		result = result * 10 + (*arg - '0');
		arg++;
	}
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && result < INT_MIN))
		return (0);
	*number = result * sign;
	return (1);
}

void	free_all(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

static int	repeated(t_list *stack)
{
	t_list	*copy;
	t_list	*head;

	head = stack;
	copy = stack->next;
	while (head)
	{
		copy = head->next;
		while (copy)
		{
			if (head->data == copy->data)
				return (1);
			copy = copy->next;
		}
		head = head->next;
	}
	return (0);
}

static t_list	*create_stack(char **argv)
{
	int		number;
	int		i;
	t_list	*stack_a;
	t_list	*head_dir;

	i = 1;
	while (argv[i])
	{
		ft_printf("Parseando argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	i = 0;
	while (argv[++i])
	{
		if (!safe_atoi(argv[i], &number))
			return (write(2, "Error\n", 6), NULL);
		if (i == 1)
		{
			head_dir = ft_lstnew(number);
			stack_a = head_dir;
		}
		else
		{
			stack_a->next = ft_lstnew(number);
			stack_a = stack_a->next;
		}
	}
	stack_a = head_dir;
	return (stack_a);
}

t_list	*parse_arg(char **argv)
{
	t_list			*stack_a;

	stack_a = create_stack(argv);
	if (!stack_a)
		return (NULL);
	if (repeated(stack_a))
		return (write(2, "Error\n", 6), free_all(stack_a), NULL);
	return (stack_a);
}
