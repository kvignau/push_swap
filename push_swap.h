/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:14:30 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/03 14:27:03 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef	struct		s_node
{
	int				content;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_node;

typedef	struct		s_lst
{
	t_elem			*tail;
	t_elem			*head;
}					t_lst;

void				ft_linit(t_lst **list);
void				ft_ladd(t_lst **list, int content,\
					size_t cont_size);
void				ft_lnew(t_lst **list);
void				ft_ldel(t_lst **list);
void				ft_laddfront(t_lst **list, int content,\
					size_t cont_size);