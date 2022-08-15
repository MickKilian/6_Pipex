/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:20:13 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:53:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;

	if (s1 == NULL || set == NULL)
		return (NULL);
	length = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + length - 1)) && length != 0)
		length--;
	while (ft_strchr(set, *s1) && length != 0)
	{
		s1++;
		length--;
	}
	return (ft_substr(s1, 0, length));
}
