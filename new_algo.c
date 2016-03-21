/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:32:10 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/21 16:32:27 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			median_pile(t_dbl *lst)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		val;
	int		inf;

	tmp1 = lst->head;
	if (tmp1)
		tmp2 = tmp1->next;
	while (tmp1)
	{
		inf = 0;
		val = tmp1->value;
		while (tmp2)
		{
			if (tmp2->value < val)
				inf++;
			tmp2 = tmp2->next;
		}
		if (inf == lst->length / 2)
			return (val);
		tmp2 = lst->head;
		tmp1 = tmp1->next;
	}
	return (0);
}

void		div_pile(t_dbl **a, t_dbl **b)
{
	int		med;
	int		val;
	t_node	*tmp;

	med = median_pile(*a);
	val = (*a)->head->value;
	tmp = (*a)->tail;
	while (tmp && val != tmp->value)
	{
		if (tmp->value <= med)
			ft_push_pile(a, b);
		else
			ft_rev_rot_pile(a);
		tmp = (*a)->tail;
	}
	if (tmp && tmp->value < med)
			ft_push_pile(a, b);
}