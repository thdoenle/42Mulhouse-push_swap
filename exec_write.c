/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:16:15 by thdoenle          #+#    #+#             */
/*   Updated: 2022/12/20 13:20:39 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec(int ins, t_stack *a, t_stack *b)
{
	if (ins == SA || ins == SS)
		swap(a);
	else if (ins == RA || ins == RR)
		rotate(a);
	else if (ins == RRA || ins == RRR)
		reverse_rotate(a);
	else if (ins == PA)
		push(b, a);
	if (ins == SB || ins == SS)
		swap(b);
	else if (ins == RB || ins == RR)
		rotate(b);
	else if (ins == RRB || ins == RRR)
		reverse_rotate(b);
	else if (ins == PB)
		push(a, b);
}

void	write_instruction(int ins)
{
	if (ins & FOURTH_BYTE_MASK)
		write(1, &ins, 4);
	else
		write(1, &ins, 3);
}

void	exec_write(int ins, t_stack *a, t_stack *b)
{
	exec(ins, a, b);
	write_instruction(ins);
}
