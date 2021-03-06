/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:14:30 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/23 20:01:31 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

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
	int				c;
	int				v;
	int				n;
	int				l;
}					t_option;

void				ft_initdbl(t_dbl **lst);
void				ft_lnew(t_node **node, int value);
void				ft_ldbladdfront(t_dbl **lst, t_node *new_elem);
void				ft_ldbldel(t_dbl **list);
int					ft_putelem(int i, int ac, char **av, t_dbl **a);
int					gestion_option(int *i,
					t_option *option, int ac, char **av);
int					ft_param(char **av, t_option *option,
					int *i, int j);
void				init_option(t_option *opt);
void				ft_affiche_pile(t_dbl *lst);
void				ft_affiche_pile_color(t_dbl *lst, int ok);
void				ft_affiche(t_dbl *a, t_dbl *b);
void				ft_affiche_color(t_dbl *a, t_dbl *b, int ok);
void				ft_rev_rot_pile(t_dbl **lst);
void				ft_rot_pile(t_dbl **lst);
void				ft_swap_pile(t_dbl **lst);
void				ft_push_pile(t_dbl **a, t_dbl **b);
void				ft_realloc_push_pile(t_dbl **a, t_dbl **b);
intmax_t			ft_atoi_imax(const char *str);
int					list_rev_ok(t_dbl *lst);
int					ft_min_pile(t_dbl *a, int *pos);
int					ft_max_pile(t_dbl *a, int *pos);
int					ft_error(char *str);
int					ft_print_error(t_dbl **a);
int					ft_same_nbr(t_dbl *lst);
int					ft_min(t_dbl *a);
int					max_pile(t_dbl *a);
int					val_medium(t_dbl *a);
void				smallmap(t_dbl **a, t_dbllist **lstactions);
void				push_swap(t_dbl **a, t_dbl **b, t_option option,
					t_dbllist **lstactions);
void				action_pile_a(t_dbl **a, int i, t_dbllist **lstactions);
void				action_pile_b(t_dbl **a, t_dbl **b, int nb_push,
					t_dbllist **lstactions);
int					median_pile(t_dbl *lst);
void				div_pile(t_dbl **a, t_dbl **b, t_dbllist **lstactions);
int					action_div(t_node *tmp, t_dbllist **lstactions,
					t_dbl **a, t_dbl **b);
void				action_ra(t_dbl **a, t_dbllist **lstactions);
int					sens_parcourt(t_dbl *a, int med);
void				push_swap2(t_dbl **a, t_dbl **b, t_option option,
					t_dbllist **lstactions);
void				action_fusion(t_dbl **a, int i, t_dbllist **lstactions);
int					verif_tri(t_dbl *lst, int *pos);
int					inf_med(t_dbl *a, int med);
int					nb_in_first_part(t_dbl *a, int med);
int					nb_in_sec_part(t_dbl *a, int med);
int					verif_tri_inv(t_dbl *lst);
void				ft_algo(t_dbl **a, t_dbl **b, t_dbllist **lstactions,
					t_option option);
void				ft_affiche_action(t_dbllist *lstactions);
void				ft_display_type(t_option option, t_dbllist *lstactions,
					t_dbl *a, t_dbl *b);

#endif
