/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:42:37 by thdoenle          #+#    #+#             */
/*   Updated: 2023/01/08 09:25:33 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	t_lst	*ptr;

	if (b->first)
		return (0);
	ptr = a->first;
	while (ptr->next && ptr->n == ptr->next->n - 1)
		ptr = ptr->next;
	if (ptr->next)
		return (0);
	return (1);
}

int	brute_force_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	inst[20];

	i = 0;
	while (i < 20)
	{
		inst[i] = 0;
		if (simulate(a, b, inst, i) == EXIT_SUCCESS)
		{
			while (i > 0)
			{
				i--;
				write_instruction(inst[i]);
			}
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

void	sort(t_stack *a, t_stack *b)
{
	if (brute_force_sort(a, b) == EXIT_FAILURE)
	{
		general_sort(a, b);
	}
}
