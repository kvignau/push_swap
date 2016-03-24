/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:56:11 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/17 16:56:25 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_min_pile(t_dbl *a, int *pos)
{
	t_node	*tmp;
	int		min;
	int		cpt;

	tmp = a->head;
	cpt = 1;
	min = tmp->value;
	(*pos) = 1;
	tmp = tmp->next;
	while (tmp)
	{
		cpt++;
		if (tmp->value < min)
		{
			min = tmp->value;
			(*pos) = cpt;
		}
		tmp = tmp->next;
	}
	return (min);
}

int			ft_max_pile(t_dbl *a, int *pos)
{
	t_node	*tmp;
	int		max;
	int		cpt;

	tmp = a->head;
	cpt = 0;
	max = tmp->value;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			*pos = cpt;
		}
		cpt++;
		tmp = tmp->next;
	}
	return (max);
}

int			list_ok(t_dbl *lst)
{
	t_node	*tmp;

	if (lst->length == 0)
		return (1);
	tmp = lst->head;
	while (tmp->next)
	{
		if (tmp->value >= tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			list_rev_ok(t_dbl *lst)
{
	t_node	*tmp;

	if (lst->length == 0)
		return (1);
	tmp = lst->head;
	while (tmp->next)
	{
		if (tmp->value <= tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			verif_tri(t_dbl *lst, int *pos)
{
	t_node	*tmp;

	*pos = 0;
	if (lst->length == 0)
		return (1);
	tmp = lst->head;
	while (tmp->next)
	{
		if (tmp->value <= tmp->next->value)
		{
			(*pos)++;
			return (0);
		}
		(*pos)++;
		tmp = tmp->next;
	}
	return (1);
}

int			verif_tri_inv(t_dbl *lst)
{
	t_node	*tmp;
	int		pos;
	int		max;

	pos = 0;
	max = 0;
	if (lst->length == 0)
		return (pos);
	tmp = lst->head;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
		{
			pos++;
		}
		else
		{
			if (max < pos)
				max = pos;
			pos = 0;
		}
		tmp = tmp->next;
	}
	return (pos);
}
