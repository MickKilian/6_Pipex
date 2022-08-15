/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeclose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:17:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/15 16:08:11 by mbourgeo         ###   ########.fr       */
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

void	ft_leaveopen(t_data *ppx, int fdi, int fdj)
{
	int	i;

	i = 0;
	while (ppx->fd[i])
	{
		//dprintf(2, "i = %d, fdi = %d\n", i, fdi);
		if (i != fdi || fdj)
		{
			close (ppx->fd[i][0]);
			//dprintf(2, "close(fd[%d][0])  : %d\n", i, ppx->fd[i][0]);
		}
		if (i != fdi || !fdj)
		{
			close (ppx->fd[i][1]);
			//dprintf(2, "close(fd[%d][1]) : %d\n", i, ppx->fd[i][1]);
		}
		i++;
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

void	ft_freeclose(t_data *ppx)
{
	ft_closeallfd(ppx);
	ft_freefd(ppx->fd);
	if (ppx->pid)
		free(ppx->pid);
}
