/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:31 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:52:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static	int	ft_power(int p)
{
	if (p == 0)
		return (1);
	return (10 * ft_power(p - 1));
}

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

void	ft_putnbr_fd(int n, int fd)
{
	int		nb_carac;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	nb_carac = ft_getsize(n);
	while (nb_carac)
	{
		ft_putchar_fd((n / ft_power(nb_carac - 1)) + '0', fd);
		n = n - (n / ft_power(nb_carac - 1) * ft_power(nb_carac - 1));
		nb_carac--;
	}
}
