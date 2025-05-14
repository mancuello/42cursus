/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:16:32 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/14 15:15:58 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_list
{
	int				data;
	unsigned int	index;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(int n);
t_list			*parse_arg(char **argv);
int				stack_len(t_list *stack);
void			normalize_stack(t_list *stack);
void			radix_sort(t_list **stack_a, t_list **stack_b);
void			swap(t_list **stack, char x);
void			sswap(t_list **stack_a, t_list **stack_b);
void			push(t_list **src, t_list **dest, char x);
void			rotate(t_list **src, char x);
void			rotate_both(t_list **list_a, t_list **list_b, int i);
void			reverse_rotate(t_list **src, char x);
void			reverse_rotate_both(t_list **list_a, t_list **list_b, int i);
void			print_list(t_list *stack);
void			turkish_sort(t_list **stack_a, t_list **stack_b);
void			do_rotations(int cheap, t_list **stack_a, t_list **stack_b);
void			sort_stack(t_list **stack);
void			final_check(t_list **stack, char x);
void			single_rotations(int moves, t_list **stack, char x);
int				moves_stack(t_list *stack, unsigned int index);
int				extra_checks(t_list *stack_b, unsigned int index);
int				sorted(t_list *stack);
int				abs_value(int a);
void			free_all(t_list *stack);
unsigned int	find_max_index(t_list *stack);
int				reverse_sorted(t_list *stack);
void			sort_arr(int *arr, unsigned int len);
void			quick_sort(t_list **a, t_list **b);
void			initial_push(t_list **stack_a, t_list **stack_b, int len);
int				min_index(t_list *stack, unsigned int index);
int				found_index(t_list *stack, unsigned int index);
void			free_split(char **arr);

#endif