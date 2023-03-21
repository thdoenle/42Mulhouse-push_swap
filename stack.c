/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:29:49 by thdoenle          #+#    #+#             */
/*   Updated: 2022/12/15 16:47:20 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_has_val(t_stack *stack, int val)
{
	t_lst	*lst;

	lst = stack->first;
	while (lst)
	{
		if (lst->n == val)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	stack_add_back(t_stack *stack, t_lst *link)
{
	if (!link)
		return (ERR);
	if (stack_has_val(stack, link->n))
	{
		free(link);
		return (ERR);
	}
	if (stack->last)
		stack->last->next = link;
	link->prev = stack->last;
	stack->last = link;
	if (!stack->first)
		stack->first = link;
	return (0);
}

int	free_stack(t_stack *stack)
{
	t_lst	*next;

	while (stack->first)
	{
		next = stack->first->next;
		free(stack->first);
		stack->first = next;
	}
	stack->last = NULL;
	return (ERR);
}
