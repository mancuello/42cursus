/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:29:24 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/27 15:30:06 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int n)
{
	t_list *head;

	head = malloc(sizeof(t_list));
	if (!head)
		perror("Fallo en la asignacion de memoria");
	head->data = n;
	head->index = 0;
	head->next = NULL;
	return (head);
}

void	swap(t_list *stack)
{
	int	temp;

	temp = 0;
	if (stack && stack->next)
	{
		temp = stack->data;
		stack->data = stack->next->data;
		stack->next->data = temp;
	}
}

void	sswap(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	rotate(t_list **src)
{
	t_list *first;
	t_list *last;

	if (!*src || !(*src)->next)
		return ;
	first = *src;
	*src = first->next;
	last = *src;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rotate_both(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
}

void	reverse_rotate(t_list **src)
{
	t_list *last;

	if (!*src || !(*src)->next)
		return ;
	last = *src;
	while (last->next->next)
		last = last->next;
	last->next->next = *src;
	*src = last->next;
	last->next = NULL;	
}

void	reverse_rotate_both(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
}