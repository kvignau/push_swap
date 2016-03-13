#include "push_swap.h"

int		main(int ac, char **av)
{
	t_dbl	*a;
	t_dbl	*b;
	t_node	*elem;
	int	i;
	int	pos;

	i = 1;
	ft_initdbl(&a);
	ft_initdbl(&b);
	while (i < ac)
	{
		ft_lnew(&elem, ft_atoi(av[i]));
		ft_ldbladdfront(&a, elem);
		i++;
	}
	while(!list_rev_ok(a) || !list_ok(b))
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
		ft_push_pile(&a, &b);
		ft_printf("pb \n");
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
