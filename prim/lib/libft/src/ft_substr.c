/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:47:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:53:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;
	size_t	length;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (start + len >= len_s)
		len = len_s - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	length = len;
	while (len--)
		*str++ = *(s++ + start);
	*str = '\0';
	return (str - length);
}
