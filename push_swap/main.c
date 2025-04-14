/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:48:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/14 11:54:34 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_b;
	void	*head_dir;
	unsigned int	i = 1;

	if (argc == 1)
		return (1);
	else
	{
		while (argv[i])
		{
			stack_b = ft_lstnew(ft_atoi(argv[i++]));
			if (i == 2)
				head_dir = stack_b;
			stack_b = stack_b->next;
		}
		stack_b = head_dir;
	}
	return (0);
}
