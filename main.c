/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <thdoenle@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:27:58 by thdoenle          #+#    #+#             */
/*   Updated: 2023/02/10 09:46:25 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	return (ERR);
}

long	ft_atoi(char **s)
{
	long	sign;
	long	n;
	long	max;

	max = 0x7fffffff;
	sign = 1;
	if (**s == '-')
	{
		sign = -1;
		max++;
		(*s)++;
	}
	else if (**s == '+')
		(*s)++;
	if (**s < '0' || **s > '9')
		return (TOO_BIG_NB);
	n = 0;
	while (**s >= '0' && **s <= '9')
	{
		n = n * 10 + (**s - '0');
		if (n > max)
			return (TOO_BIG_NB);
		(*s)++;
	}
	return (n * sign);
}

int	parse_args(int ac, char **av, t_stack *a)
{
	char	*s;

	while (ac)
	{
		s = *av;
		while (*s == ' ')
			s++;
		if (!*s)
			return (ERR);
		while (*s)
		{
			if (stack_add_back(a, lst_new_link(ft_atoi(&s))) == ERR)
				return (ERR);
			while (*s == ' ')
				s++;
		}
		av++;
		ac--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	a.first = NULL;
	a.last = NULL;
	b.first = NULL;
	b.last = NULL;
	if (parse_args(ac - 1, av + 1, &a) == ERR)
		return (error(&a));
	if (a.first != a.last)
	{
		if (index_stack_values(&a) == ERR)
			return (error(&a));
		sort(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
