/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:23:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:52:37 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putpointer(unsigned long int n)
{
	int	nb_char;

	nb_char = 0;
	if (n == 0)
		nb_char += ft_putstr("(nil)");
	else
	{
		nb_char += ft_putstr("0x");
		nb_char += ft_putpointerhexa(n);
	}
	return (nb_char);
}

int	ft_putitoa(int n)
{
	int		nb_char;

	nb_char = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		nb_char += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		nb_char += ft_putitoa(n / 10);
	n = n % 10;
	nb_char += ft_putchar(n + '0');
	return (nb_char);
}

int	ft_putunsigned(unsigned int n)
{
	int		nb_char;

	nb_char = 0;
	if (n >= 10)
		nb_char += ft_putitoa(n / 10);
	n = n % 10;
	nb_char += ft_putchar(n + '0');
	return (nb_char);
}

int	ft_putpointerhexa(unsigned long int n)
{
	int	nb_char;

	nb_char = 0;
	if (n >= 16)
		nb_char += ft_putpointerhexa(n / 16);
	n = n % 16;
	if (n < 10)
		nb_char += ft_putchar(n + '0');
	else
		nb_char += ft_putchar(n % 10 + 'a');
	return (nb_char);
}
