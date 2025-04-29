/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:16:32 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/28 20:50:25 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				data;
	unsigned int	index;
	struct s_list	*next;
}	t_list;

void	normalize_stack(t_list *stack);
int		stack_len(t_list *stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **src);
t_list	*ft_lstnew(int n);
void	print_list(t_list *stack);



#endif