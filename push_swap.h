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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/includes/libft.h"
#include "libft/ft_printf/includes/ft_printf.h"

typedef	struct		s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef	struct		s_dbl
{
	size_t			length;
	t_node			*tail;
	t_node			*head;
}					t_dbl;

void		ft_initdbl(t_dbl **lst);
void		ft_lnew(t_node **node, int value);
void		ft_ldbladdfront(t_dbl **lst, t_node *new_elem);
void		ft_affiche_pile(t_dbl *lst);
void		ft_rev_rot_pile(t_dbl **lst);
void		ft_rot_pile(t_dbl **lst);
void		ft_swap_pile(t_dbl **lst);
void		ft_push_pile(t_dbl **a, t_dbl **b);
int			list_ok(t_dbl *lst);
int			list_rev_ok(t_dbl *lst);
int			ft_min_pile(t_dbl *a, int *pos);
intmax_t		ft_atoi_imax(const char *str);
int			ft_error(char *str);

#endif
