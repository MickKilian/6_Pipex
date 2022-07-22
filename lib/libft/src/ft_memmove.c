/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:48:05 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/03 03:29:40 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = (src < dest) * (n - 1);
	while (n--)
	{
		*((unsigned char *)(dest + i)) = *((unsigned char *)(src + i));
		i = i + 1 - 2 * (src < dest);
	}
	return (dest);
}
