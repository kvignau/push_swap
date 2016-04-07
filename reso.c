/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reso.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:16:13 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/18 11:16:30 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			max_pile(t_dbl *a)
{
	t_node	*tmp;
	int		max;

	tmp = a->head;
	max = tmp->value;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int			ft_min(t_dbl *a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a->head;
	while (i < a->length - 2)
	{
		if (tmp->value < a->tail->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void		smallmap(t_dbl **a, t_dbllist **lstactions)
{
	while (!(list_rev_ok(*a)))
	{
		if ((*a)->tail->value == max_pile(*a))
			action_ra(a, lstactions);
		else if ((*a)->tail->prev &&
			(*a)->tail->prev->value < (*a)->tail->value)
		{
			ft_swap_pile(a);
			ft_lstdbladd(lstactions, "sa", 2);
		}
		else
		{
			ft_rev_rot_pile(a);
			ft_lstdbladd(lstactions, "rra", 3);
		}
	}
}

void		div_pile(t_dbl **a, t_dbl **b, t_dbllist **lstactions)
{
	int		med;
	t_node	*tmp;

	tmp = (*a)->tail;
	med = action_div(tmp, lstactions, a, b);
	if (tmp && tmp->value < med && (!list_rev_ok(*a)))
	{
		ft_push_pile(a, b);
		ft_lstdbladd(lstactions, "pb", 3);
	}
}

int			action_div(t_node *tmp, t_dbllist **lstactions,
	t_dbl **a, t_dbl **b)
{
	int		med;
	int		val;

	val = (*a)->head->value;
	med = median_pile(*a);
	while (tmp && !(inf_med(*a, med)))
	{
		if (list_rev_ok(*a) && (*b)->tail &&
			(*a)->tail->value > max_pile(*b))
			break ;
		if (tmp->value < med)
		{
			ft_push_pile(a, b);
			ft_lstdbladd(lstactions, "pb", 3);
		}
		else if ((*a)->head->value < med)
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
