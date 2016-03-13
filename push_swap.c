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

void		ft_initdbl(t_dbl **lst)
{
	*lst = (t_dbl *)malloc(sizeof(t_dbl));
	if (*lst == NULL)
		return ;
	else
	{
		(*lst)->length = 0;
		(*lst)->tail = NULL;
		(*lst)->head = NULL;
	}
}

void		ft_lnew(t_node **node,int value)
{
	*node = (t_node *)malloc(sizeof(t_node));
	if (*node == NULL)
		return ;
	(*node)->value = value;
	(*node)->prev = NULL;
	(*node)->next = NULL;
}

void	ft_ldbladdfront(t_dbl **lst, t_node *new_elem)
{
	if ((*lst)->tail == NULL)
		(*lst)->tail = new_elem;
	else
	{
		(*lst)->head->prev = new_elem;
		new_elem->prev = NULL;
		new_elem->next = (*lst)->head;
	}
	(*lst)->head = new_elem;
	(*lst)->length++;
}

void		ft_affiche_pile(t_dbl *lst)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	tmp = lst->head;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
}

void		ft_rev_rot_pile(t_dbl **lst)
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

void		ft_rot_pile(t_dbl **lst)
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
		ft_initdbl(a);
		(*b)->length++;
		return ;
	}
	(*a)->length--;
	(*b)->length++;
}

int			ft_min_pile(t_dbl *a, int *pos)
{
	t_node	*tmp;
	int		min;
	int		cpt;

	tmp = a->head;
	cpt = 0;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			*pos = cpt;
		}
		cpt++;
		tmp = tmp->next;
	}
	return (min);
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
