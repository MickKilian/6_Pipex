/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 04:12:20 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:53:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*(dest + j) && size - j)
		j++;
	i = 0;
	while (*(src + i))
	{
		if (i + j + 1 < size)
			*(dest + j + i) = *(src + i);
		i++;
	}	
	if (i + j < size)
		*(dest + i + j) = '\0';
	else if (size > j)
		*(dest + size - 1) = '\0';
	if (size < j)
		return (i + size);
	return (i + j);
}
