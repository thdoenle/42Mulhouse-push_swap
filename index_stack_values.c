/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:57:13 by thdoenle          #+#    #+#             */
/*   Updated: 2022/12/19 21:28:50 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	allocate_indexed_stack(t_stack *stack, t_stack *new)
{
	t_lst	*ptr;
	t_lst	**new_ptr;
	t_lst	*prev;

	prev = NULL;
	new_ptr = &(new->first);
	ptr = stack->first;
	while (ptr)
	{
		*new_ptr = malloc(sizeof(**new_ptr));
		if (!*new_ptr)
			return (free_stack(new));
		(*new_ptr)->prev = prev;
		ptr = ptr->next;
		prev = *new_ptr;
		new_ptr = &((*new_ptr)->next);
	}
	*new_ptr = NULL;
	new->last = prev;
	return (0);
}

long	set_next_index(long i, t_lst *ptr, t_lst *new_ptr)
{
	t_lst	*min_ptr;
	t_lst	*min_new_ptr;

	min_ptr = ptr;
	min_new_ptr = new_ptr;
	while (ptr)
	{
		if (min_ptr->n > ptr->n)
		{
			min_ptr = ptr;
			min_new_ptr = new_ptr;
		}
		ptr = ptr->next;
		new_ptr = new_ptr->next;
	}
	if (min_ptr->n == TOO_BIG_NB)
		return (-1);
	min_ptr->n = TOO_BIG_NB;
	min_new_ptr->n = i;
	return (i + 1);
}

int	index_stack_values(t_stack *stack)
{
	t_stack	new;
	long	i;

	if (allocate_indexed_stack(stack, &new) == ERR)
		return (free_stack(stack));
	i = 0;
	while (i > -1)
		i = set_next_index(i, stack->first, new.first);
	free_stack(stack);
	*stack = new;
	return (0);
}
