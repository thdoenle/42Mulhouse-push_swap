/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:51:09 by thdoenle          #+#    #+#             */
/*   Updated: 2023/01/06 16:38:09 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_opposite_instruction(int ins)
{
	if (ins == SS || ins == SA || ins == SB)
		return (ins);
	else if (ins == RA)
		return (RRA);
	else if (ins == RRA)
		return (RA);
	else if (ins == RB)
		return (RRB);
	else if (ins == RR)
		return (RRR);
	else if (ins == RRB)
		return (RB);
	else if (ins == RRR)
		return (RR);
	else if (ins == PA)
		return (PB);
	else if (ins == PB)
		return (PA);
	return (0);
}

int	simulate_exec(t_stack *a, t_stack *b, int *ins_tab, int iter)
{
	static const int	instructions[3] = {SA, RA, RRA};
	int					ins;

	ins = instructions[ins_tab[iter]];
	if (ins == get_opposite_instruction(ins_tab[iter + 1]))
		return (0);
	exec(ins, a, b);
	return (ins);
}

int	simulate(t_stack *a, t_stack *b, int *ins_tab, int iter)
{
	int	ins_num;

	if (!iter)
	{
		if (is_sorted(a, b))
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	iter--;
	ins_num = 0;
	while (ins_num < 3)
	{
		ins_tab[iter] = ins_num;
		ins_tab[iter] = simulate_exec(a, b, ins_tab, iter);
		if (ins_tab[iter])
		{
			if (simulate(a, b, ins_tab, iter) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			exec(get_opposite_instruction(ins_tab[iter]), a, b);
		}
		ins_num++;
	}
	return (EXIT_FAILURE);
}
