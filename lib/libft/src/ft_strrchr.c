/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:33:47 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/06 02:47:30 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	while (*(s + ft_strlen(s) - len_s) && (unsigned char)c != *(s + len_s - 1))
		len_s--;
	if (!(unsigned char)c)
		return ((char *)(s + ft_strlen(s)));
	if (len_s == 0)
		return (0);
	else
		return ((char *)(s + len_s - 1));
}
