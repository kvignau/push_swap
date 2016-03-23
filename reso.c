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

void		smallmap(t_dbl **a, int *nboperation)
{
	while (!(list_rev_ok(*a)))
	{
		if ((*a)->tail->value == max_pile(*a))
		{
			ft_rot_pile(a);
			ft_printf("ra ");
			(*nboperation)++;
		}
		else if ((*a)->tail->prev && (*a)->tail->prev->value < (*a)->tail->value)
		{
			ft_swap_pile(a);
			ft_printf("sa ");
			(*nboperation)++;
		}
		else
		{
			ft_rev_rot_pile(a);
			ft_printf("rra ");
			(*nboperation)++;
		}
	}
}