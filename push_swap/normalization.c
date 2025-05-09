/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:58:43 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/08 18:36:56 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static int	*create_arr(t_list	*stack)
{
	int	*arr;
	int	i;
	int	len;

	len = stack_len(stack);
	arr = malloc(sizeof(int) * (len + 1));
	if (!arr)
	{
		perror("Fallo en la asignacion de memoria");
		return (0);
	}
	arr[len] = 0;
	i = 0;
	while (i < len)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
	return (arr);
}

static void	sort_arr(int *arr, unsigned int len)
{
	int				temp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < (len - 1))
	{
		while (j < (len - 1) - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static int	get_index(int *arr, int data, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_list *stack)
{
	unsigned int	len;
	int				*arr;

	len = stack_len(stack);
	arr = create_arr(stack);
	if (!arr)
		return ;
	sort_arr(arr, len);
	while (stack)
	{
		stack->index = get_index(arr, stack->data, len);
		stack = stack->next;
	}
	free(arr);
}
