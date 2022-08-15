/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:23:21 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/15 15:35:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		n;
	int		sign;

	n = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || (*nptr == ' '))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
		sign = sign * (-2 * (*(nptr++) == '-') + 1);
	while (*nptr >= '0' && *nptr <= '9')
		n = n * 10 + *(nptr++) - '0';
	while (*nptr)
		nptr++;
	return (sign * n);
}
