/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filemanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:10:08 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/20 19:41:52 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_checkfile(char *file, int *fd)
{
	*fd = open(file, O_RDWR, 0777);
	if (*fd < 0)
		return (1);
	return (0);
}

int	ft_redirect(int fd_orig, int fd_redir)
{
	return(dup2(fd_orig, fd_redir));
}
