/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:24:10 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:52:34 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	nb_char;

	nb_char = 0;
	while (*str)
	{
		ft_putchar(*(str++));
		nb_char++;
	}
	return (nb_char);
}

int	ft_puthexa_min(unsigned int n)
{
	int	nb_char;

	nb_char = 0;
	if (n >= 16)
		nb_char += ft_puthexa_min(n / 16);
	n = n % 16;
	if (n < 10)
		nb_char += ft_putchar(n + '0');
	else
		nb_char += ft_putchar(n % 10 + 'a');
	return (nb_char);
}

int	ft_puthexa_maj(unsigned int n)
{
	int	nb_char;

	nb_char = 0;
	if (n >= 16)
		nb_char += ft_puthexa_maj(n / 16);
	n = n % 16;
	if (n < 10)
		nb_char += ft_putchar(n + '0');
	else
		nb_char += ft_putchar(n % 10 + 'A');
	return (nb_char);
}
