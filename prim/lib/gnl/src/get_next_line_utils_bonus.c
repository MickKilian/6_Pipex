/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 06:45:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/15 15:33:51 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_mem_alloc(int n, int type_malloc)
{
	char	*str;
	char	*str_cpy;
	t_list2	*list_el;

	if (type_malloc == STR_MALLOC)
	{
		str = malloc(n * sizeof(char));
		if (!str)
			return (NULL);
		str_cpy = str;
		while (n-- > 0)
			*str_cpy++ = '\0';
		return (str);
	}
	else
	{
		list_el = malloc(n * sizeof(t_list2));
		if (!list_el)
			return (NULL);
		return (list_el);
	}
}

int	ft_strjoin2(char **s1, char **s2, int type_join, int addition)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (*s1 == NULL || *s2 == NULL)
		return (0);
	while ((*s1)[++j])
		;
	if (type_join == JOIN)
	{
		str = (char *)ft_mem_alloc(ft_strjoin2(s1, s1, LENGTH,
					ft_strjoin2(s2, s2, LENGTH, 0)) + 1, STR_MALLOC);
		while ((*s1)[++i])
			str[i] = (*s1)[i];
		while ((*s2)[++i - j - 1])
			str[i - 1] = (*s2)[i - j - 1];
		str[i - 1] = '\0';
		free(*s1);
		free(*s2);
		*s1 = str;
	}
	return (j + addition);
}

char	*ft_substr2(char **s, int start, int length)
{
	char	*str;
	int		shift;
	int		len_s;

	if (*s == NULL)
		return (NULL);
	len_s = ft_strjoin2(s, s, LENGTH, 0);
	if (start >= len_s)
		length = 0;
	else if (start + length >= len_s)
		length = len_s - start;
	if (length == 0)
	{
		free(*s);
		*s = NULL;
		return (NULL);
	}
	str = (char *)ft_mem_alloc(length + 1, STR_MALLOC);
	shift = -1;
	while (++shift < length)
		*(str + shift) = *((*s + shift) + start);
	*(str + shift) = '\0';
	if (start != 0)
		free(*s);
	return (str);
}

int	ft_read_buffer(int fd, char **stock)
{
	char	*buffer;
	int		index_nl;
	int		nb_char;

	nb_char = BUFFER_SIZE;
	index_nl = -1;
	while (nb_char == BUFFER_SIZE && index_nl == -1)
	{
		buffer = (char *)ft_mem_alloc(BUFFER_SIZE + 1, STR_MALLOC);
		nb_char = read(fd, buffer, BUFFER_SIZE);
		if (nb_char == -1)
			break ;
		index_nl = ft_index_nl(buffer);
		ft_strjoin2(stock, &buffer, JOIN, 0);
	}
	if (nb_char == -1 || !*stock[0])
	{
		if (nb_char == -1)
			free(buffer);
		free(*stock);
		return (-1);
	}
	return (ft_strjoin2(stock, stock, LENGTH, 0) - (index_nl >= 0)
		* (nb_char - index_nl));
}

int	ft_index_nl(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\0')
		return (-1);
	return (count);
}
