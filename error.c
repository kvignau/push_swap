/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:59:13 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/17 16:59:30 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_print_error(t_dbl **a)
{
	write(2, "Error\n", 6);
	ft_ldbldel(a);
	return (0);
}

int				ft_error(char *str)
{
	intmax_t	test;
	int			i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (!str[1] || !ft_isdigit(str[1]))
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	test = ft_atoi_imax(str);
	i = test;
	if (test != i)
		return (0);
	return (1);
}

int				ft_same_nbr(t_dbl *lst)
{
	t_node		*tmp;
	t_node		*tmp1;
	int			nb;

	tmp = lst->head->next;
	tmp1 = lst->head;
	while (tmp1->next)
	{
		nb = tmp1->value;
		while (tmp)
		{
			if (tmp->value == nb)
				return (0);
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
		tmp = tmp1->next;
	}
	return (1);
}
