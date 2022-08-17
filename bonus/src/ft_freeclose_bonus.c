/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeclose_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:17:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:42:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_closeallfd(t_data *ppx)
{
	int	i;

	i = -1;
	while (ppx->fd[++i])
	{
		close(ppx->fd[i][0]);
		close(ppx->fd[i][1]);
	}
	close(ppx->fd_infile);
	if (ppx->hdoc)
		unlink(".heredoc_tmp");
	close(ppx->fd_outfile);
}

void	ft_freemallocinttrunc(int **temp, int trunc)
{
	int	i;

	i = -1;
	while (++i != trunc && temp[i])
		free(temp[i]);
	free(temp[i]);
	free (temp);
}

void	ft_freemallocchartrunc(char **temp, int trunc)
{
	int	i;

	i = -1;
	while (++i != trunc && temp[i])
	{
		free(temp[i]);
	}
	free(temp[i]);
	free (temp);
}

void	ft_freepidfdtrunc(t_data *ppx, int trunc)
{
	free(ppx->pid);
	ft_freemallocinttrunc(ppx->fd, trunc);
}

void	ft_freeall(t_data *ppx, int trunc)
{
	ft_freepidfdtrunc(ppx, trunc);
	ft_freemallocchartrunc(ppx->path_spt, -1);
}
