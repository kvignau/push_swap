/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:35:31 by kvignau           #+#    #+#             */
/*   Updated: 2016/04/06 10:36:00 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_algo(t_dbl **a, t_dbl **b, t_dbllist **lstactions,
	t_option option)
{
	int		i;

	i = 0;
	if (!verif_tri(*a, &i))
	{
		if (((*a)->length >= 2 && i == (*a)->length - 1 && ft_min(*a)))
		{
			ft_swap_pile(a);
			ft_lstdbladd(lstactions, "sa", 3);
		}
		else if ((*a)->length == 3)
			smallmap(a, lstactions);
		else
		{
			if (verif_tri_inv(*a) > (*a)->length / 6)
				div_pile2(a, b, lstactions);
			else
				div_pile(a, b, lstactions);
			push_swap(a, b, option, lstactions);
			push_swap2(a, b, option, lstactions);
		}
	}
}

void		div_pile2(t_dbl **a, t_dbl **b, t_dbllist **lstactions)
{
	int		med;
	t_node	*tmp;

	tmp = (*a)->tail;
	med = action_div2(tmp, lstactions, a, b);
	if (tmp && tmp->value < med && (!list_rev_ok(*a)))
	{
		ft_push_pile(a, b);
		ft_lstdbladd(lstactions, "pb", 3);
	}
}

int			action_div2(t_node *tmp, t_dbllist **lstactions,
	t_dbl **a, t_dbl **b)
{
	int		med;
	int		val;

	med = median_pile(*a);
	val = (*a)->head->value;
	while (tmp && inf_med(*a, med))
	{
		if (list_rev_ok(*a) && (*b)->tail &&
			(*a)->tail->value > max_pile(*b))
			break ;
		if (tmp->value < med)
		{
			ft_push_pile(a, b);
			ft_lstdbladd(lstactions, "pb", 3);
		}
		else if (sens_parcourt(*a, med))
		{
			ft_rev_rot_pile(a);
			ft_lstdbladd(lstactions, "rra", 4);
		}
		else
			action_ra(a, lstactions);
		tmp = (*a)->tail;
	}
	return (med);
}

void		action_ra(t_dbl **a, t_dbllist **lstactions)
{
	ft_rot_pile(a);
	ft_lstdbladd(lstactions, "ra", 3);
}
