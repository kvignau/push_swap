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

void		bigmap(t_dbl **a, t_dbl **b, t_option option)
{
	while (!(list_rev_ok(*a)))
	{
		if ((*a)->tail->value == max_pile(*a))
		{
			ft_rot_pile(a);
			ft_printf("ra ");
		}
		if ((*a)->tail->prev && (*a)->tail->prev->value < (*a)->tail->value)
		{
			ft_swap_pile(a);
			ft_printf("sa ");
		}
		else// ((*a)->head->value < (*a)->tail->value)
		{
			ft_rev_rot_pile(a);
			ft_printf("rra ");
		}
	}
	option.v = 1;
	(*b)->head = NULL;
}