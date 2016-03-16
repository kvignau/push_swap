/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:58:27 by kvignau           #+#    #+#             */
/*   Updated: 2016/01/26 14:58:30 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ldbldel(t_dbl **list)
{
	t_node		*tmp;

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
