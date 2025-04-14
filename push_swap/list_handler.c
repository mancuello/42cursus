/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:29:24 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/14 11:45:01 by mcuello          ###   ########.fr       */
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
	head->next = NULL;
	return (head);
}