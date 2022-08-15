/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:59:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:53:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (*(char *)little == '\0')
		return ((char *)big);
	size = ft_strlen(little);
	while ((ft_strlen((char *)(big + i)) >= size) && (i + size - 1 < len))
	{
		if (!ft_strncmp((char *)(big + i), little, size))
			return ((char *)big + i);
		else
			i++;
	}
	return (NULL);
}
