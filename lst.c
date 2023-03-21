/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:39:02 by thdoenle          #+#    #+#             */
/*   Updated: 2022/12/20 11:46:08 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lst_new_link(long val)
{
	t_lst	*new;

	if (val == TOO_BIG_NB)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->n = val;
	return (new);
}

long	lst_size(t_lst *lst)
{
	long	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
