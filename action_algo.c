/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:00:43 by kvignau           #+#    #+#             */
/*   Updated: 2016/04/05 14:01:09 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		action_pile_a(t_dbl **a, int i, t_dbllist **lstactions)
{
	int		pos;

	pos = 0;
	i = ft_min_pile(*a, &pos);
	if ((*a)->tail->prev && i == (*a)->tail->prev->value)
	{
		ft_swap_pile(a);
		ft_lstdbladd(lstactions, "sa", 3);
	}
	else if (pos > (int)(*a)->length / 2)
	{
		while ((*a)->tail->value != i)
		{
			ft_rot_pile(a);
			ft_lstdbladd(lstactions, "ra", 3);
		}
	}
	else
	{
		while ((*a)->tail->value != i)
		{
			ft_rev_rot_pile(a);
			ft_lstdbladd(lstactions, "rra", 4);
		}
	}
}

void		action_pile_b(t_dbl **a, t_dbl **b, int nb_push,
	t_dbllist **lstactions)
{
	while (nb_push >= 1)
	{
		ft_push_pile(b, a);
		ft_lstdbladd(lstactions, "pa", 3);
		nb_push--;
	}
}

void		push_swap(t_dbl **a, t_dbl **b, t_option option,
	t_dbllist **lstactions)
{
	int		i;
	int		nb_push;

	nb_push = 0;
	while (!list_rev_ok(*a))
	{
		action_pile_a(a, i, lstactions);
		if (!list_rev_ok(*a))
		{
			ft_push_pile(a, b);
			ft_lstdbladd(lstactions, "pb", 3);
			nb_push++;
		}
		if (option.v)
		{
			if (option.c)
				ft_affiche_color(*a, *b, 0);
			else
				ft_affiche(*a, *b);
		}
	}
	action_pile_b(a, b, nb_push, lstactions);
}

void		push_swap2(t_dbl **a, t_dbl **b, t_option option,
	t_dbllist **lstactions)
{
	int		i;

	while ((*b)->length != 0)
	{
		action_fusion(b, i, lstactions);
		ft_push_pile(b, a);
		push_swap(a, b, option, lstactions);
		ft_lstdbladd(lstactions, "pa", 3);
		if (option.v)
		{
			if (option.c)
				ft_affiche_color(*a, *b, 0);
			else
				ft_affiche(*a, *b);
		}
	}
}

void		action_fusion(t_dbl **b, int i, t_dbllist **lstactions)
{
	int		pos;

	i = ft_max_pile(*b, &pos);
	if ((*b)->tail->prev && i == (*b)->tail->prev->value)
	{
		ft_swap_pile(b);
		ft_lstdbladd(lstactions, "sb", 3);
	}
	else if (pos > (int)(*b)->length / 2)
	{
		while ((*b)->tail->value != i)
		{
			ft_rot_pile(b);
			ft_lstdbladd(lstactions, "rb", 3);
		}
	}
	else
	{
		while ((*b)->tail->value != i)
		{
			ft_rev_rot_pile(b);
			ft_lstdbladd(lstactions, "rrb", 4);
		}
	}
}
