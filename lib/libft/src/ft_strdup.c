/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 02:03:15 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/22 17:52:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(cpy + i) = *(s + i);
		i++;
	}
	*(cpy + i) = '\0';
	return (cpy);
}
