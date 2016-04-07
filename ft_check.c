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
	if (option.l)
		ft_affiche(*a, *b);
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
			if (!(verif_tri_inv(*a) > (*a)->length / 6))
				div_pile(a, b, lstactions);
			push_swap(a, b, option, lstactions);
			push_swap2(a, b, option, lstactions);
		}
	}
}

void		action_ra(t_dbl **a, t_dbllist **lstactions)
{
	ft_rot_pile(a);
	ft_lstdbladd(lstactions, "ra", 3);
}
