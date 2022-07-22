/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:40:11 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/06 18:27:05 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char const *s, int c)
{
	size_t	count;
	int		trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s == c)
			trigger = 0;
		else if (*s != c)
		{
			if (trigger == 0)
			{
				trigger = 1;
				count++;
			}
		}
		s++;
	}
	return (count);
}

static	char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	int		i;

	cpy = malloc((n + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (n--)
	{
		*(cpy + i) = *(s + i);
		i++;
	}
	*(cpy + i) = '\0';
	return (cpy);
}

static	void	free_malloc(char **temp, int i)
{
	while (i)
	{
		free(temp[i]);
		i--;
	}
	free(temp);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		nb_words;
	char	**temp;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb_words = ft_count_words(s, c);
	temp = malloc((nb_words + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (i < nb_words)
	{
		while (*s == c)
			s++;
		count = 0;
		while ((*s && *s != c) && s++)
			count++;
		temp[i++] = ft_strndup(s - count, count);
		if (!temp[i - 1])
			free_malloc(temp, i - 1);
	}
	temp[i] = 0;
	return (temp);
}
