/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:03:14 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/03 15:03:17 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rot_pile(t_dbl **lst)
{
	t_node	*tmp;

	if ((*lst)->length <= 1)
		return ;
	tmp = (*lst)->tail->prev;
	(*lst)->tail->prev = NULL;
	(*lst)->tail->next = (*lst)->head;
	(*lst)->head->prev = (*lst)->tail;
	(*lst)->head = (*lst)->tail;
	(*lst)->tail = tmp;
	(*lst)->tail->next = NULL;
}

void		ft_rev_rot_pile(t_dbl **lst)
{
	t_node	*tmp;

	if ((*lst)->length <= 1)
		return ;
	tmp = (*lst)->head->next;
	(*lst)->head->next = NULL;
	(*lst)->head->prev = (*lst)->tail;
	(*lst)->tail->next = (*lst)->head;
	(*lst)->tail = (*lst)->head;
	(*lst)->head = tmp;
	(*lst)->head->prev = NULL;
}

void		ft_swap_pile(t_dbl **lst)
{
	t_node	*tmp;
	int		n;

	n = 0;
	tmp = NULL;
	if ((*lst)->length <= 1)
		return ;
	n = (*lst)->tail->value;
	(*lst)->tail->value = (*lst)->tail->prev->value;
	(*lst)->tail->prev->value = n;
}

void		ft_push_pile(t_dbl **a, t_dbl **b)
{
	t_node	*tmp;

	if ((*a)->length == 0)
		return ;
	tmp = (*a)->tail->prev;
	if (!(*b)->tail)
	{
		(*b)->head = (*a)->tail;
		(*b)->tail = (*a)->tail;
		(*b)->tail->prev = NULL;
	}
	else
	{
		(*b)->tail->next = (*a)->tail;
		(*a)->tail->prev = (*b)->tail;
		(*b)->tail = (*a)->tail;
	}
	(*a)->tail = tmp;
	if ((*a)->length > 1)
		(*a)->tail->next = NULL;
	else
	{
		(*a)->tail = NULL;
		(*a)->head = NULL;
	}
	(*a)->length--;
	(*b)->length++;
}

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
