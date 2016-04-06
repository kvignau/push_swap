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

int			sens_parcourt(t_dbl *a, int med)
{
	if (nb_in_firt_part(a, med) > nb_in_sec_part(a, med))
		return (1);
	return (0);
}
