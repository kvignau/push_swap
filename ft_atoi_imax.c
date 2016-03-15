/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_imax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:09:07 by kvignau           #+#    #+#             */
/*   Updated: 2016/03/15 10:10:48 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

intmax_t		ft_atoi_imax(const char *str)
{
	int			i;
	int			neg;
	intmax_t	nb;

	i = 0;
	neg = 0;
	nb = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			nb = (nb * 10) + (str[i] - '0');
		else
			return (neg != 0 ? (nb * -1) : (nb));
		i++;
	}
	return (neg != 0 ? (nb * -1) : (nb));
}
