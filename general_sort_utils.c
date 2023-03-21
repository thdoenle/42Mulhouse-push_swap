/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:16:45 by thdoenle          #+#    #+#             */
/*   Updated: 2023/01/09 13:46:22 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_write_ntimes(int ins, t_stacks *s, long nb)
{
	while (nb > 0)
	{
		exec_write(ins, s->a, s->b);
		nb--;
	}
}

long	lst_get_val_at_index(t_lst *lst, long i)
{
	long	cur_i;

	cur_i = 0;
	while (lst)
	{
		if (cur_i == i)
			return (lst->n);
		cur_i++;
		lst = lst->next;
	}
	return (ERR);
}

long	dest_index(t_lst *lst, long n)
{
	long	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		if ((lst->n < n && lst->next->n > n)
			|| (lst->n > lst->next->n && (n > lst->n || n < lst->next->n)))
			return (i);
		lst = lst->next;
		i++;
	}
	return (0);
}

long	get_max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}
