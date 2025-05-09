/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:23:25 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/08 22:25:38 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **src, char x)
{
	t_list	*first;
	t_list	*last;

	if (!*src || !(*src)->next)
		return ;
	first = *src;
	*src = first->next;
	last = *src;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (x == 'a')
		write(1, "ra\n", 3);
	else if (x == 'b')
		write(1, "rb\n", 3);
}

void	rotate_both(t_list **list_a, t_list **list_b, int i)
{
	rotate(list_a, 0);
	rotate(list_b, 0);
	if (i)
		write(1, "rr\n", 3);
}

void	reverse_rotate(t_list **src, char x)
{
	t_list	*prev;
	t_list	*last;

	if (!src || !*src || !(*src)->next)
		return ;
	prev = NULL;
	last = *src;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *src;
	*src = last;
	if (x == 'a')
		write(1, "rra\n", 4);
	else if (x == 'b')
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_list **list_a, t_list **list_b, int i)
{
	reverse_rotate(list_a, 'x');
	reverse_rotate(list_b, 'x');
	if (i)
		write(1, "rrr\n", 4);
}
