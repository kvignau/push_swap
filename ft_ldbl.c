/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldbl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:07:33 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/17 17:07:36 by kvignau          ###   ########.fr       */
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

void		ft_lnew(t_node **node, int value)
{
	*node = (t_node *)malloc(sizeof(t_node));
	if (*node == NULL)
		return ;
	(*node)->value = value;
	(*node)->prev = NULL;
	(*node)->next = NULL;
}

void		ft_ldbladdfront(t_dbl **lst, t_node *new_elem)
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

void		ft_ldbldel(t_dbl **list)
{
	t_node	*tmp;

	tmp = NULL;
	while ((*list)->head != NULL)
	{
		tmp = (*list)->head->next;
		free((*list)->head);
		(*list)->head = tmp;
	}
	(*list)->tail = NULL;
	(*list)->head = NULL;
	free(*list);
}

int			ft_putelem(int i, int ac, char **av, t_dbl **a)
{
	t_node	*elem;

	while (i < ac)
	{
		if (!ft_error(av[i]))
			return (ft_print_error(a));
		ft_lnew(&elem, ft_atoi(av[i]));
		ft_ldbladdfront(a, elem);
		i++;
	}
	if ((*a)->length == 0)
		return (0);
	return (1);
}
