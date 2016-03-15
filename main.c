#include "push_swap.h"

int			ft_print_error(t_dbl **a)
{
	ft_printf("Error\n");
	ft_ldbldel(a);
	return (0);
}

int			ft_error(char *str)
{
	intmax_t	test;
	int		i;

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

int			ft_same_nbr(t_dbl *lst)
{
	t_node		*tmp;
	t_node		*tmp1;
	int		nb;

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

void		push_swap(t_dbl **a, t_dbl **b, t_option option)
{
	int		pos;
	int		i;
	int		tour;

	tour = 0;
	while((!list_rev_ok(*a) || !list_ok(*b)))// && b->tail->value < a->tail->value)
	{
		i = ft_min_pile(*a, &pos);
		if (tour != 0)
			ft_printf(" ");
		tour++;
		if ((*a)->tail->prev && i == (*a)->tail->prev->value)
		{
			ft_swap_pile(a);
			ft_printf("sa");
		}
		else if (pos > (int)(*a)->length / 2)
		{
			while ((*a)->tail->value != i)
			{
				ft_rev_rot_pile(a);
				ft_printf("rra");
			}
		}
		else
		{
			while ((*a)->tail->value != i)
			{
				ft_rot_pile(a);
				ft_printf("ra");
			}
		}
		if ((!list_rev_ok(*a) || !list_ok(*b)))
		{
			ft_push_pile(a, b);
			ft_printf("pb");
		}
		if (option.b)
		{
			if (option.c)
				ft_affiche_color(*a, *b, 0);
			ft_affiche(*a, *b);
		}
	}
	while ((*b)->length != 0)
	{
		ft_push_pile(b, a);
		ft_printf("pa ");
	}
}

int		ft_putelem(int i, int ac, char **av, t_dbl **a)
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
	return (1);
}

int			gestion_option(int *i, t_option *option, int ac, char **av)
{
	int		j;

	j = 0;
	if (ac > 2)
	{
		if (av[*i][j] && av[*i][j] == '-')
		{
			j++;
			while (av[*i][j])
			{	
				if (av[*i][j] == 'c' && option->c == 0)
					option->c = 1;
				else if (av[*i][j] == 'b' && option->b == 0)
					option->b = 1;
				else
					ft_printf("Options valables: \nb -> affichage listes intermediaires\nc -> ajout couleur aux listes");
				(*i)++;
			}
		}
		return (1);
	}
	else
		return (0);
}

void		init_option(t_option *opt)
{
	opt->c = 0;
	opt->b = 0;
}

int			main(int ac, char **av)
{
	t_dbl		*a;
	t_dbl		*b;
	int			i;
	t_option	option;

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
	push_swap(&a, &b, option);
	if (option.c)
		ft_affiche_color(a, b, 1);
	else
		ft_affiche(a, b);
	ft_ldbldel(&a);
	ft_ldbldel(&b);
	return (0);
}
