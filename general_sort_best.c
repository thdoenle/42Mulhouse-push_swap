/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort_best.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:42:55 by thdoenle          #+#    #+#             */
/*   Updated: 2023/01/09 13:46:07 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	min_ins_nb(t_stacks *s, long b_n, long b_i)
{
	long	a_i;
	long	min;
	long	temp;

	a_i = dest_index(s->a->first, b_n);
	min = get_max(a_i, b_i);
	temp = get_max(s->a_size - a_i, s->b_size - b_i);
	if (min > temp)
		min = temp;
	temp = a_i + s->b_size - b_i;
	if (min > temp)
		min = temp;
	temp = s->a_size - a_i + b_i;
	if (min > temp)
		min = temp;
	return (min);
}

long	best_index_in_b(t_stacks *s)
{
	t_lst	*b_lst;
	long	i;
	long	best_i;
	long	min;
	long	temp_min;

	best_i = 0;
	min = min_ins_nb(s, s->b->first->n, 0);
	i = 1;
	b_lst = s->b->first->next;
	while (b_lst)
	{
		if (i < min || s->b_size - i < min)
			temp_min = min_ins_nb(s, b_lst->n, i);
		if (min > temp_min)
		{
			min = temp_min;
			best_i = i;
		}
		i++;
		b_lst = b_lst->next;
	}
	return (best_i);
}

int	best_rot_to_do(t_stacks *s, long a_i, long b_i)
{
	long	min;
	long	temp_min;
	int		res;

	min = get_max(a_i, b_i);
	res = 0b00;
	temp_min = get_max(s->a_size - a_i, s->b_size - b_i);
	if (min > temp_min)
	{
		min = temp_min;
		res = 0b11;
	}
	temp_min = a_i + s->b_size - b_i;
	if (min > temp_min)
	{
		min = temp_min;
		res = 0b01;
	}
	temp_min = s->a_size - a_i + b_i;
	if (min > temp_min)
	{
		min = temp_min;
		res = 0b10;
	}
	return (res);
}
