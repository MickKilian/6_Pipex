/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managerr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:57:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:15:58 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_printerr(char *errmsg)
{
	write (2, errmsg, ft_strlen(errmsg));
	return (1);
}

int	ft_printcomperr(char *str1, char *str2)
{
	char	*temp;
	char	*errmsg;

	temp = ft_strjoin(str1, str2);
	errmsg = ft_strjoin(temp, "\n");
	free(temp);
	ft_printerr(errmsg);
	free(errmsg);
	return (1);
}
