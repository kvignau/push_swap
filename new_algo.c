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

void		div_pile(t_dbl **a, t_dbl **b, int *nboperation)
{
	int		med;
	int		val;
	t_node	*tmp;

	med = median_pile(*a);
	val = (*a)->head->value;
	tmp = (*a)->tail;
	while (tmp && val != tmp->value)
	{
		if (tmp->value < med)
		{
			ft_push_pile(a, b);
			(*nboperation)++;
		}
		else
		{
			ft_rev_rot_pile(a);
			(*nboperation)++;
		}
		tmp = (*a)->tail;
	}
	if (tmp && tmp->value < med)
	{
			ft_push_pile(a, b);
			(*nboperation)++;
	}
}

void		action_pile_a(t_dbl **a, int tour, int *nboperation, int i)
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
			ft_rev_rot_pile(a);
			ft_printf("rra");
			(*nboperation)++;
			if (tour != 0)
				ft_printf(" ");
		}
	}
	else
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
}

void		action_pile_b(t_dbl **a, t_dbl **b, int *nboperation, int nb_push)
{
	int		tour;

	tour = 0;
	while (nb_push != 0)
	{
		ft_push_pile(b, a);
		if (tour != 0)
			ft_printf(" ");
		ft_printf("pa");
		(*nboperation)++;
		tour++;
		nb_push--;
	}
}

// void		fusion(t_dbl **a, t_dbl **b, int *nboperation)
// {
// 	int		tour;

// 	tour = 0;
// 	while ((*b)->length != 0)
// 	{
// 		ft_push_pile(b, a);
// 		if (tour != 0)
// 			ft_printf(" ");
// 		ft_printf("pa");
// 		(*nboperation)++;
// 		tour++;
// 	}
// }

void		push_swap(t_dbl **a, t_dbl **b, t_option option, int *nboperation)
{
	int		i;
	int		tour;
	int		nb_push;

	tour = 0;
	nb_push = 0;
	while (!list_rev_ok(*a))// && b->tail->value < a->tail->value)
	{
		tour++;
		action_pile_a(a, tour, nboperation, i);
		if (!list_rev_ok(*a))
		{
			ft_push_pile(a, b);
			ft_printf("pb");
			(*nboperation)++;	
			nb_push++;
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
	action_pile_b(a, b, nboperation, nb_push);
}

void		push_swap2(t_dbl **a, t_dbl **b, t_option option, int *nboperation)
{
	int		i;
	int		tour;
	int		nb_push;

	tour = 0;
	nb_push = 0;
	while ((*b)->length != 0)// && b->tail->value < a->tail->value)
	{
		tour++;
		action_fusion(b, tour, nboperation, i);
		ft_push_pile(b, a);
		ft_printf("pa");
		(*nboperation)++;
			if (tour != 0)
				ft_printf(" ");
		if (option.v)
		{
			if (option.c)
				ft_affiche_color(*a, *b, 0);
			else
				ft_affiche(*a, *b);
		}
	}
}

void		action_fusion(t_dbl **b, int tour, int *nboperation, int i)
{
	int		pos;

	i = ft_max_pile(*b, &pos);
	if ((*b)->tail->prev && i == (*b)->tail->prev->value)
	{
		ft_swap_pile(b);
		ft_printf("sb");
		if (tour != 0)
			ft_printf(" ");
		(*nboperation)++;
	}
	else if (pos > (int)(*b)->length / 2)
	{
		while ((*b)->tail->value != i)
		{
			ft_rev_rot_pile(b);
			ft_printf("rrb");
			(*nboperation)++;
			if (tour != 0)
				ft_printf(" ");
		}
	}
	else
	{
		while ((*b)->tail->value != i)
		{
			ft_rot_pile(b);
			ft_printf("rb");
			(*nboperation)++;
			if (tour != 0)
				ft_printf(" ");
		}
	}
}
