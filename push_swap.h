/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:00:20 by thdoenle          #+#    #+#             */
/*   Updated: 2023/01/09 16:35:56 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ERR -1
# define TOO_BIG_NB 0x100000000

typedef struct s_lst
{
	struct s_lst	*prev;
	struct s_lst	*next;
	long			n;
}	t_lst;

typedef struct s_stack
{
	t_lst	*first;
	t_lst	*last;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	long	a_size;
	long	b_size;
}	t_stacks;

enum
{
	SA = 0x0a6173,
	SB = 0x0a6273,
	SS = 0x0a7373,
	PA = 0x0a6170,
	PB = 0x0a6270,
	RA = 0x0a6172,
	RB = 0x0a6272,
	RR = 0x0a7272,
	RRA = 0x0a617272,
	RRB = 0x0a627272,
	RRR = 0x0a727272,
	FOURTH_BYTE_MASK = 0xff << 030,
};

t_lst	*lst_new_link(long val);
long	lst_size(t_lst *lst);
int		stack_add_back(t_stack *stack, t_lst *link);
int		free_stack(t_stack *stack);

void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);
void	exec(int ins, t_stack *a, t_stack *b);
void	write_instruction(int ins);
void	exec_write(int ins, t_stack *a, t_stack *b);

int		index_stack_values(t_stack *stack);
int		is_sorted(t_stack *a, t_stack *b);
int		simulate(t_stack *a, t_stack *b, int *ins, int iter);
void	sort(t_stack *a, t_stack *b);
void	general_sort(t_stack *a, t_stack *b);

void	exec_write_ntimes(int ins, t_stacks *s, long nb);
long	lst_get_val_at_index(t_lst *lst, long i);
long	dest_index(t_lst *lst, long n);
long	get_max(long a, long b);
long	best_index_in_b(t_stacks *s);
int		best_rot_to_do(t_stacks *s, long a_i, long b_i);

#endif
