/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 00:44:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:16:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_redirect(int fd_orig, int fd_redir)
{
	if (dup2(fd_orig, fd_redir) >= 0)
		return (0);
	else
		return (ft_printerr(ERR_REDIR));
}

int	ft_inoutfileredirect(t_data *ppx)
{
	if (ft_redirect(ppx->fd_infile, STDIN_FILENO))
		return (1);
	if (ft_redirect(ppx->fd_outfile, STDOUT_FILENO))
		return (1);
	return (0);
}

int	ft_fdchildredirect(t_data *ppx, int i)
{
	if (i != 0)
		if (ft_redirect(ppx->fd[i - 1][0], STDIN_FILENO))
			return (1);
	if (i != ppx->nb_proc - 1)
		if (ft_redirect(ppx->fd[i][1], STDOUT_FILENO))
			return (1);
	return (0);
}
