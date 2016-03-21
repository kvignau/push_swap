/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:14:30 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/15 10:10:07 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

typedef	struct		s_option
{
	int		c;
	int		v;
	int		n;
}					t_option;

void			ft_initdbl(t_dbl **lst);
void			ft_lnew(t_node **node, int value);
void			ft_ldbladdfront(t_dbl **lst, t_node *new_elem);
void			ft_ldbldel(t_dbl **list);
int				ft_putelem(int i, int ac, char **av, t_dbl **a);

int				gestion_option(int *i,
				t_option *option, int ac, char **av);
void			init_option(t_option *opt);

void			ft_affiche_pile(t_dbl *lst);
void			ft_affiche_pile_color(t_dbl *lst, int ok);
void			ft_affiche(t_dbl *a, t_dbl *b);
void			ft_affiche_color(t_dbl *a, t_dbl *b, int ok);

void			ft_rev_rot_pile(t_dbl **lst);
void			ft_rot_pile(t_dbl **lst);
void			ft_swap_pile(t_dbl **lst);
void			ft_push_pile(t_dbl **a, t_dbl **b);

void			push_swap(t_dbl **a, t_dbl **b, t_option option);
void			action_pile_a(t_dbl **a, int tour, int *nboperation, int i);
void			action_pile_b(t_dbl **a, t_dbl **b, int *nboperation);

intmax_t		ft_atoi_imax(const char *str);

int				list_ok(t_dbl *lst);
int				list_rev_ok(t_dbl *lst);
int				ft_min_pile(t_dbl *a, int *pos);

int				ft_error(char *str);
int				ft_print_error(t_dbl **a);
int				ft_same_nbr(t_dbl *lst);

//nouvel algo
int			ft_min(t_dbl *a);
int			max_pile(t_dbl *a);
int			val_medium(t_dbl *a);
void		bigmap(t_dbl **a, t_dbl **b, t_option opion);

//newalgo
int			median_pile(t_dbl *lst);
void		div_pile(t_dbl **a, t_dbl **b);

#endif
