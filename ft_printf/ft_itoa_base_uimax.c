/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uimax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <kvignau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:03:38 by kvignau           #+#    #+#             */
/*   Updated: 2016/02/12 11:41:22 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_nbrlen_uimax(uintmax_t n, size_t base)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static void			ft_base_uimax(size_t len, char **str, size_t base,
		uintmax_t nb)
{
	while (nb != 0)
	{
		len--;
		if (base >= 10 && nb % base >= 10)
		{
			(*str)[len] = (nb % base) + 87;
		}
		else
		{
			(*str)[len] = (nb % base) + 48;
		}
		nb = nb / base;
	}
}

char				*ft_itoa_base_uimax(uintmax_t n, size_t base)
{
	char			*str;
	size_t			len;

	len = ft_nbrlen_uimax(n, base);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	else
	{
		ft_base_uimax(len, &str, base, n);
	}
	return (str);
}
