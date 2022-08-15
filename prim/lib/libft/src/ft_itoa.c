/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:49:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:51:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int	ft_getsize(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		nb_carac;
	char	*str;

	nb_carac = ft_getsize(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((nb_carac + 1) * sizeof(char));
	if (!str)
		return (NULL);
	sign = (n < 0);
	n = n - 2 * n * (n < 0);
	if (sign == 1)
		str[0] = '-';
	str[nb_carac] = '\0';
	while (nb_carac - sign)
	{
		str[nb_carac - 1] = n % 10 + '0';
		n = n / 10;
		nb_carac--;
	}
	return (str);
}
