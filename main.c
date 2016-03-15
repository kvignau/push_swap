#include "push_swap.h"

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

void		push_swap(t_dbl **a, t_dbl **b)
{
	int		pos;
	int		i;

	while((!list_rev_ok(*a) || !list_ok(*b)))// && b->tail->value < a->tail->value)
	{
		i = ft_min_pile(*a, &pos);
		if ((*a)->tail->prev && i == (*a)->tail->prev->value)
		{
			ft_swap_pile(a);
			ft_printf("sa ");
		}
		else if (pos > (int)(*a)->length / 2)
		{
			while ((*a)->tail->value != i)
			{
				ft_rev_rot_pile(a);
				ft_printf("rra ");
			}
		}
		else
		{
			while ((*a)->tail->value != i)
			{
				ft_rot_pile(a);
				ft_printf("ra ");
			}
		}
		if ((!list_rev_ok(*a) || !list_ok(*b)))
		{
			ft_push_pile(a, b);
			ft_printf("pb \n");
		}
		ft_affiche_color(*a, *b, 0);
		ft_affiche(*a, *b);
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
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_lnew(&elem, ft_atoi(av[i]));
		ft_ldbladdfront(a, elem);
		i++;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_dbl		*a;
	t_dbl		*b;
	int			i;
	int			option;

	option = 0;
	i = 1;
	if (ac > 2)
	{
		if (ft_strcmp(av[1], "-v") == 0)
		{
			option = 1;
			i++;
		}
	}
	else
		return (0);
	ft_initdbl(&a);
	ft_initdbl(&b);
	if (!ft_putelem(i, ac, av, &a))
		return (0);
	if (!ft_same_nbr(a))
	{
		ft_printf("Error\n");
		return (0);//free liste avant erreur
	}
	push_swap(&a, &b);
	ft_affiche_color(a, b, 1);
	ft_affiche(a, b);
	return (0);
}
