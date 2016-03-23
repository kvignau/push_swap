/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:07:01 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/17 17:07:05 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			gestion_option(int *i, t_option *option, int ac, char **av)
{
	int		j;

	j = 0;
	if (ac >= 2)
	{
		if (av[*i][j] && av[*i][j] == '-')
		{
			j++;
			if (!ft_isalpha(av[*i][j]))
				return (1);
			while (av[*i][j])
			{
				if (av[*i][j] == 'c' && option->c == 0)
					option->c = 1;
				else if (av[*i][j] == 'v' && option->v == 0)
					option->v = 1;
				else if (av[*i][j] == 'n' && option->n == 0)
					option->n = 1;
				else
				{
					ft_printf("Options valables: \nv -> affichage listes");
					ft_printf("intermediaires \nc -> ajout couleur aux listes");
					ft_printf("\nn -> nb opérations\n");
					return (0);
				}
				j++;
			}
			(*i)++;
		}
		return (1);
	}
	else
		return (0);
}

void		init_option(t_option *opt)
{
	opt->c = 0;
	opt->v = 0;
	opt->n = 0;
}

int			main(int ac, char **av)
{
	t_dbl		*a;
	t_dbl		*b;
	int			i;
	t_option	option;
	int			nboperation;

	nboperation = 0;
	init_option(&option);
	i = 1;
	if (!gestion_option(&i, &option, ac, av))
		return (0);
	ft_initdbl(&a);
	ft_initdbl(&b);
	if (!ft_putelem(i, ac, av, &a))
		return (0);
	if (!ft_same_nbr(a))
		return (ft_print_error(&a));
	ft_affiche(a, b);
	if (!verif_tri(a, &i))
	{
		if (a->length >= 2 && i == a->length - 1 && ft_min(a))
		{
			ft_swap_pile(&a);
			ft_printf("sa ");
			nboperation++;
		}
		else
		{
			div_pile(&a, &b, &nboperation);
			push_swap(&a, &b, option, &nboperation);
			push_swap2(&a, &b, option, &nboperation);
		}
	}
	if (option.n)
		ft_printf("\n\n[{cyan}nb operation : %d{eoc}]\n", nboperation);
	if (option.c)
		ft_affiche_color(a, b, 1);
	else
		ft_affiche(a, b);
	ft_ldbldel(&a);
	return (0);
}
