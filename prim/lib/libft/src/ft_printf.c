/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:24:10 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:52:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		nb_char;
	int		i;

	nb_char = 0;
	i = 0;
	va_start(ptr, format);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
			nb_char += ft_checkspecifier(*(format + i++ + 1), ptr);
		else
			nb_char += ft_putchar(*(format + i));
		i++;
	}
	return (nb_char);
}

int	ft_checkspecifier(int c, va_list ptr)
{
	int		nb_char;

	nb_char = 0;
	if (c == 'c')
		nb_char += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		nb_char += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		nb_char += ft_putpointer(va_arg(ptr, unsigned long int));
	else if (c == 'd')
		nb_char += ft_putitoa(va_arg(ptr, int));
	else if (c == 'i')
		nb_char += ft_putitoa(va_arg(ptr, int));
	else if (c == 'u')
		nb_char += ft_putunsigned(va_arg(ptr, unsigned int));
	else if (c == 'x')
		nb_char += ft_puthexa_min(va_arg(ptr, unsigned int));
	else if (c == 'X')
		nb_char += ft_puthexa_maj(va_arg(ptr, unsigned int));
	else if (c == '%')
		nb_char += ft_putchar('%');
	return (nb_char);
}
