/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:03:14 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/03 15:03:17 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_affiche_file(t_file file)
{
	size_t	i;

	i = file.start;
	if (i == file.len)
		ft_printf("%d ", file.tab[i]);
	else
	{
		while (i < file.len)
		{
			ft_printf("%d ", file.tab[i]);
			i++;
		}
	}
	i = 0;
	while (i <= file.end && file.end < file.start)
	{
		ft_printf("%d ", file.tab[i]);
		i++;
	}
}
void		ft_rot_file(t_file *file)
{
	file->start = file->end;
	if (file->end == 0)
		file->end = file->len - 1;
	else
		file->end--;
}

void		ft_swap_file(t_file *file)
{
	int		c;
	size_t	x;

	c = file->tab[file->end];
	if (file->end == 0)
		x = file->len - 1;
	else
		x = file->end - 1;
	file->tab[file->end] = file->tab[x];
	file->tab[x] = c;
}

void		ft_pb_file(t_file *a, t_file *b)
{
	if (a->len != 0)
	{
		if (b->len != 0)
			b->end++;
		b->len++;
		b->tab[b->end] = a->tab[a->end];
		if (a->end == 0)
			a->end = a->len - 1;
		else
			a->end--;
		a->len--;
	}
}

int			main(int ac, char **av)
{
	t_file	a;
	t_file	b;
	int		i;

	i = 1;
	a.tab = (int *)malloc(sizeof(int) * (ac - 1));
	a.start = 0;
	a.len = ac - 1;
	a.end = a.len - 1;
	b.tab = (int *)malloc(sizeof(int) * (ac - 1));
	b.start = 0;
	b.end = 0;
	b.len = 0;
	while (i < ac)
	{
		a.tab[a.end - i + 1] = ft_atoi(av[i]);
		i++;
	}
	ft_affiche_file(a);
	ft_putstr("\n");

	ft_rot_file(&a);
	ft_affiche_file(a);
	ft_putstr("\n");

	// ft_swap_file(&a);
	// ft_affiche_file(a);
	// ft_putstr("\n");

	ft_pb_file(&a, &b);
	ft_affiche_file(a);
	ft_putstr("\n");
	ft_affiche_file(b);

	ft_putstr("\n");
	ft_pb_file(&b, &a);
	ft_affiche_file(a);
	ft_putstr("\n");
	ft_affiche_file(b);
	return (0);
}