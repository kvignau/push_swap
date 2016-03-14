#include "push_swap.h"

int			ft_error(char *str)
{
	intmax_t	test;
	int		i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
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

int			main(int ac, char **av)
{
	t_dbl		*a;
	t_dbl		*b;
	t_node		*elem;
	int		i;
	int		pos;

	i = 1;
	ft_initdbl(&a);
	ft_initdbl(&b);
	while (i < ac)
	{
		if (!ft_error(av[i]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_lnew(&elem, ft_atoi(av[i]));
		ft_ldbladdfront(&a, elem);
		i++;
	}
	if (!ft_same_nbr(a))
	{
		ft_printf("Error\n");
		return (0);//free liste avant erreur
	}
	while((!list_rev_ok(a) || !list_ok(b)))// && b->tail->value < a->tail->value)
	{
		i = ft_min_pile(a, &pos);
		if (a->tail->prev && i == a->tail->prev->value)
		{
			ft_swap_pile(&a);
			ft_printf("sa ");
		}
		else if (pos > (int)a->length / 2)
		{
			while (a->tail->value != i)
			{
				ft_rev_rot_pile(&a);
				ft_printf("rra ");
			}
		}
		else
		{
			while (a->tail->value != i)
			{
				ft_rot_pile(&a);
				ft_printf("ra ");
			}
		}
		if ((!list_rev_ok(a) || !list_ok(b)))
		{
			ft_push_pile(&a, &b);
			ft_printf("pb \n");
		}
		ft_printf("\nliste a :");
		ft_affiche_pile(a);
		ft_printf("\nliste b :");
		ft_affiche_pile(b);
		ft_printf("\n");
	}
	while (b->length != 0)
	{
		ft_push_pile(&b, &a);
		ft_printf("pa ");
	}
	ft_printf("\nliste a :");
	ft_affiche_pile(a);
	ft_printf("\nliste b :");
	ft_affiche_pile(b);
	ft_printf("\n");
	return (0);
}
