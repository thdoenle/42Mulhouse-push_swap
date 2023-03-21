/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:23:30 by thdoenle          #+#    #+#             */
/*   Updated: 2022/12/20 13:16:38 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_lst	*temp;

	if (!from->first)
		return ;
	temp = from->first;
	from->first = from->first->next;
	if (!from->first)
		from->last = NULL;
	else
		from->first->prev = NULL;
	temp->next = to->first;
	if (!to->first)
		to->last = temp;
	else
		to->first->prev = temp;
	to->first = temp;
}

void	rotate(t_stack *stack)
{
	t_lst	*temp;

	if (stack->first == stack->last)
		return ;
	temp = stack->first;
	stack->first = temp->next;
	stack->first->prev = NULL;
	stack->last->next = temp;
	temp->prev = stack->last;
	temp->next = NULL;
	stack->last = temp;
}

void	reverse_rotate(t_stack *stack)
{
	t_lst	*temp;

	if (stack->first == stack->last)
		return ;
	temp = stack->last;
	stack->last = temp->prev;
	stack->last->next = NULL;
	stack->first->prev = temp;
	temp->next = stack->first;
	temp->prev = NULL;
	stack->first = temp;
}

void	swap(t_stack *stack)
{
	t_lst	*temp;

	if (stack->first == stack->last)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	temp->prev = stack->first;
	temp->next = stack->first->next;
	if (stack->first->next)
		stack->first->next->prev = temp;
	else
		stack->last = temp;
	stack->first->next = temp;
	stack->first->prev = NULL;
}
