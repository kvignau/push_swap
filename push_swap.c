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

// void		ft_swap_file(t_file *file)
// {
// 	int		c;
// 	size_t	x;

// 	c = file->tab[file->end];
// 	if (file->end == 0)
// 		x = file->len - 1;
// 	else
// 		x = file->end - 1;
// 	file->tab[file->end] = file->tab[x];
// 	file->tab[x] = c;
// }

void		ft_pb_pile(t_dbl **a, t_dbl **b)
{
	t_node	*tmp;

	if ((*a)->length == 0)
		return ;
	tmp = (*a)->tail->prev;
	if (!(*b)->tail)
	{
		(*b)->head = (*a)->tail;
		(*b)->tail = (*a)->tail;
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
		return ;
	}
	(*a)->length--;
	(*b)->length++;
}

int			main(int ac, char **av)
{
	t_dbl	*a;
	t_dbl	*b;
	t_node	*elem;
	int		i;

	i = 1;
	ft_initdbl(&a);
	ft_initdbl(&b);
	while (i < ac)
	{
		ft_lnew(&elem, ft_atoi(av[i]));
		ft_ldbladdfront(&a, elem);
		i++;
	}
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");

	ft_rot_pile(&a);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");
	
	ft_rot_pile(&a);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");
	
	ft_rot_pile(&a);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");

	ft_rot_pile(&a);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");

	// // ft_swap_file(&a);
	// // ft_affiche_file(a);
	// // ft_putstr("\n");

	ft_pb_pile(&a, &b);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");
	ft_printf("liste b : ");
	ft_affiche_pile(b);
	ft_putstr("\n");
	ft_pb_pile(&a, &b);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");
	ft_printf("liste b : ");
	ft_affiche_pile(b);
	ft_putstr("\n");
	ft_pb_pile(&a, &b);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");
	ft_printf("liste b : ");
	ft_affiche_pile(b);
	ft_putstr("\n");
	// ft_pb_pile(&a, &b);
	ft_pb_pile(&b, &a);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");
	ft_printf("liste b : ");	
	ft_affiche_pile(b);
	ft_putstr("\n");

	ft_pb_pile(&b, &a);
	ft_printf("liste a : ");
	ft_affiche_pile(a);
	ft_putstr("\n");
	ft_printf("liste b : ");
	ft_affiche_pile(b);

	// ft_putstr("\n");
	// ft_pb_file(&b, &a);
	// ft_affiche_file(a);
	// ft_putstr("\n");
	// ft_affiche_file(b);
	return (0);
}