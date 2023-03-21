/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:04:49 by thdoenle          #+#    #+#             */
/*   Updated: 2023/01/09 16:34:49 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stacks_same_dir(t_stacks *s, long a_i, long b_i, int rot_to_do)
{
	long	min;

	if (rot_to_do)
	{
		a_i = s->a_size - a_i;
		b_i = s->b_size - b_i;
		min = a_i;
		if (min > b_i)
			min = b_i;
		exec_write_ntimes(RRR, s, min);
		exec_write_ntimes(RRA, s, a_i - min);
		exec_write_ntimes(RRB, s, b_i - min);
	}
	else
	{
		min = a_i;
		if (min > b_i)
			min = b_i;
		exec_write_ntimes(RR, s, min);
		exec_write_ntimes(RA, s, a_i - min);
		exec_write_ntimes(RB, s, b_i - min);
	}
}

void	rotate_stacks(t_stacks *s)
{
	long	a_i;
	long	b_i;
	int		rot_to_do;

	b_i = best_index_in_b(s);
	a_i = dest_index(s->a->first, lst_get_val_at_index(s->b->first, b_i));
	rot_to_do = best_rot_to_do(s, a_i, b_i);
	if (rot_to_do == 0b00 || rot_to_do == 0b11)
		rotate_stacks_same_dir(s, a_i, b_i, rot_to_do);
	else if (rot_to_do == 0b01)
	{
		exec_write_ntimes(RA, s, a_i);
		exec_write_ntimes(RRB, s, s->b_size - b_i);
	}
	else
	{
		exec_write_ntimes(RRA, s, s->a_size - a_i);
		exec_write_ntimes(RB, s, b_i);
	}
}

void	move_min_at_top(t_stacks *s)
{
	t_lst	*a_lst;
	long	i;

	i = 0;
	a_lst = s->a->first;
	while (a_lst->n)
	{
		a_lst = a_lst->next;
		i++;
	}
	if (i <= s->a_size / 2)
		exec_write_ntimes(RA, s, i);
	else
		exec_write_ntimes(RRA, s, s->a_size - i);
}

void	general_sort(t_stack *a, t_stack *b)
{
	t_stacks	s;

	s.a = a;
	s.b = b;
	s.a_size = lst_size(a->first);
	s.b_size = 0;
	while (s.a_size > 2)
	{
		exec_write(PB, a, b);
		s.a_size--;
		s.b_size++;
	}
	while (b->first)
	{
		rotate_stacks(&s);
		exec_write(PA, a, b);
		s.a_size++;
		s.b_size--;
	}
	move_min_at_top(&s);
}
