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

//algo OK modifier dans new_algo

void		action_pile(t_dbl **a, int tour, int *nboperation, int i)
{
	int		pos;

	i = ft_min_pile(*a, &pos);
	if ((*a)->tail->prev && i == (*a)->tail->prev->value)
	{
		ft_swap_pile(a);
		ft_printf("sa");
		if (tour != 0)
			ft_printf(" ");
		(*nboperation)++;
	}
	else if (pos > (int)(*a)->length / 2)
	{
		while ((*a)->tail->value != i)
		{
			ft_rot_pile(a);
			ft_printf("ra");
			(*nboperation)++;
			if (tour != 0)
				ft_printf(" ");
		}
	}
	else
	{
		while ((*a)->tail->value != i)
		{
			ft_rev_rot_pile(a);
			ft_printf("rra");
			(*nboperation)++;
			if (tour != 0)
				ft_printf(" ");
		}
	}
}

void		push_pile_a(t_dbl **a, t_dbl **b, int *nboperation)
{
	int		tour;

	tour = 0;
	while ((*b)->length != 0)
	{
		ft_push_pile(b, a);
		if (tour != 0)
			ft_printf(" ");
		ft_printf("pa");
		(*nboperation)++;
		tour++;
	}
}

void		mediummap_swap(t_dbl **a, t_dbl **b, t_option option, int *nboperation)
{
	int		i;
	int		tour;

	tour = 0;
	while ((!list_rev_ok(*a) || !list_ok(*b)))// && b->tail->value < a->tail->value)
	{
		tour++;
		action_pile(a, tour, nboperation, i);
		if ((!list_rev_ok(*a) || !list_ok(*b)))
		{
			ft_push_pile(a, b);
			ft_printf("pb");
			(*nboperation)++;
			if (tour != 0)
				ft_printf(" ");
		}
		if (option.v)
		{
			if (option.c)
				ft_affiche_color(*a, *b, 0);
			else
				ft_affiche(*a, *b);
		}
	}
	push_pile_a(a, b, nboperation);
}
