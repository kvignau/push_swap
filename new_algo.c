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

int			inf_med(t_dbl *a, int med)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->value < med)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			nb_in_firt_part(t_dbl *a, int med)
{
	t_node	*tmp;
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	tmp = a->head;
	while (i <= a->length / 2)
	{
		if (tmp->value < med)
			cpt++;
		tmp = tmp->next;
		i++;
	}
	return (cpt);
}

int			nb_in_sec_part(t_dbl *a, int med)
{
	t_node	*tmp;
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	tmp = a->head;
	while (i > a->length / 2)
	{
		if (tmp->value < med)
			cpt++;
		tmp = tmp->next;
		i++;
	}
	return (cpt);
}

void		div_pile2(t_dbl **a, t_dbl **b, t_dbllist **lstactions)
{
	int		med;
	int		val;
	t_node	*tmp;
	int		sens_parc;

	sens_parc = 0;
	if (nb_in_firt_part(*a, med) > nb_in_sec_part(*a, med))
		sens_parc++;
	med = median_pile(*a);
	val = (*a)->head->value;
	tmp = (*a)->tail;
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
		else if (sens_parc)
		{
			ft_rev_rot_pile(a);
			ft_lstdbladd(lstactions, "rra", 4);
		}
		else
		{
			ft_rot_pile(a);
			ft_lstdbladd(lstactions, "ra", 3);
		}
		tmp = (*a)->tail;
	}
	if (tmp && tmp->value < med && (!list_rev_ok(*a)))
	{
		ft_push_pile(a, b);
		ft_lstdbladd(lstactions, "pb", 3);
	}
}
