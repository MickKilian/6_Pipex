/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:31:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/06 03:04:56 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	length;

	if (s != NULL && f != NULL)
	{
		i = 0;
		length = ft_strlen(s);
		while (i < length)
			(*f)(i++, s++);
	}
}

/*void	ft_rot13(unsigned int i, char *str)
{
	str[i] = (str[i] - 'a' + 13) % 26 + 'a';
}

int	main(int argc, char **argv)
{
	char	*str;

	str = argv[1];
	(void)argc;
	ft_striteri(str, (&ft_roti));
	printf(" -> %s\n", str);
	return (0);
}*/
