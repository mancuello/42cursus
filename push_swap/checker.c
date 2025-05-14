/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:00:11 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/14 15:27:42 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_sort(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(stack_a, 'x');
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(stack_b, 'x');
	else if (ft_strcmp(line, "ss\n") == 0)
		sswap(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		push(stack_b, stack_a, 'x');
	else if (ft_strcmp(line, "pb\n") == 0)
		push(stack_a, stack_b, 'x');
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(stack_a, 'x');
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(stack_b, 'x');
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_both(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(stack_a, 'x');
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(stack_b, 'x');
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate_both(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

int	process_stdin(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!do_sort(line, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			free(line);
			free_all(*stack_a);
			free_all(*stack_b);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static void	check_sorted(t_list *stack_a, t_list *stack_b)
{
	if (sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	if (argc == 2)
		free_split(args);
	normalize_stack(stack_a);
	if (!process_stdin(&stack_a, &stack_b))
		return (1);
	check_sorted(stack_a, stack_b);
	free_all(stack_a);
	free_all(stack_b);
	return (0);
}
