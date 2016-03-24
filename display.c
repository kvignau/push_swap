/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:54:51 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/17 16:55:10 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_affiche_pile_color(t_dbl *lst, int ok)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	if (!lst->head)
		return ;
	tmp = lst->head;
	while (tmp->next)
	{
		if (ok)
			ft_printf("{green}%d{eoc} ", tmp->value);
		else
			ft_printf("{red}%d{eoc} ", tmp->value);
		tmp = tmp->next;
	}
	if (ok)
		ft_printf("{green}%d{eoc}\0", tmp->value);
	else
		ft_printf("{red}%d{eoc}\0", tmp->value);
}

void		ft_affiche_pile(t_dbl *lst)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	if (!lst->head)
		return ;
	tmp = lst->head;
	while (tmp->next)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("%d", tmp->value);
}

void		ft_affiche_color(t_dbl *a, t_dbl *b, int ok)
{
	ft_printf("liste a :");
	ft_affiche_pile_color(a, ok);
	ft_printf("\nliste b :");
	ft_affiche_pile_color(b, ok);
	ft_printf("\n");
}

void		ft_affiche(t_dbl *a, t_dbl *b)
{
	ft_printf("liste a :");
	ft_affiche_pile(a);
	ft_printf("\nliste b :");
	ft_affiche_pile(b);
	ft_printf("\n");
}

void		ft_affiche_action(t_dbllist *lstactions)
{
	t_elem	*tmp;

	tmp = lstactions->head;
	if (!tmp)
		return ;
	ft_putstr("\n");
	while (tmp->next)
	{
		ft_printf("%s ", tmp->content);
		tmp = tmp->next;
	}
	if (tmp)
		ft_printf("%s", tmp->content);
	ft_putstr("\n");
	ft_putstr("\n");
}