/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeclose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:17:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/15 22:51:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freefd(int **fd)
{
	int	i;

	i = -1;
	while (fd[++i])
		free(fd[i]);
	if (fd)
		free(fd);
}

void	ft_leaveopenfdchild(t_data *ppx, int fdi)
{
	int	i;

	i = -1;
	while (ppx->fd[++i])
	{
		if (i != fdi - 1)
			close (ppx->fd[i][0]);
		if (i != fdi)
			close (ppx->fd[i][1]);
	}
}

void	ft_closeallfd(t_data *ppx)
{
	int	i;

	i = -1;
	//dprintf(2, "closing all fds\n");
	while (ppx->fd[++i])
	{
		//dprintf(2, "closing %d\n", ppx->fd[i][0]);
		close(ppx->fd[i][0]);
		//dprintf(2, "closing %d\n", ppx->fd[i][1]);
		close(ppx->fd[i][1]);
	}
	//dprintf(2, "closing open files\n");
	close(ppx->fd_infile);
	close(ppx->fd_outfile);
}

void	ft_closefdchild(t_data *ppx, int i)
{
	close (ppx->fd[i - 1][0]);
	close (ppx->fd[i][1]);
	close (ppx->fd_infile);
	close (ppx->fd_outfile);
}

void	ft_freeclose(t_data *ppx)
{
	ft_closeallfd(ppx);
	ft_freefd(ppx->fd);
	if (ppx->pid)
		free(ppx->pid);
}
