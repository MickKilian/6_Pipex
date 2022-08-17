/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:35:18 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:47:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_initpath(t_data *ppx, int argc, char **envp)
{
	int	i;

	i = -1;
	ppx->nb_proc = argc - 3 - ppx->hdoc;
	ppx->nb_pipes = ppx->nb_proc - 1;
	ppx->path_env = ft_strdup(ft_findpathstr(envp));
	if (!ppx->path_env)
		return (ft_printerr(ERR_PATHENV));
	ppx->path_spt = ft_split(ppx->path_env, ':');
	free(ppx->path_env);
	if (!ppx->path_spt)
		return (ft_printerr(ERR_PATHSPLIT));
	return (0);
}

int	ft_initprocpip(t_data *ppx, int argc, char **argv)
{
	int	i;

	i = -1;
	if (ft_openinfile(ppx, argv[1 + ppx->hdoc])
		|| ft_openoutfile(ppx, argv[argc - 1]))
		return (1);
	ppx->pid = malloc((ppx->nb_proc) * sizeof(int));
	if (!ppx->pid)
		return (ft_printerr(ERR_MPROC));
	ppx->fd = malloc((ppx->nb_pipes + 1) * sizeof(int *));
	if (!ppx->fd)
	{
		free(ppx->pid);
		return (ft_printerr(ERR_MPIPE));
	}
	while (++i < ppx->nb_pipes)
	{
		ppx->fd[i] = malloc(2 * sizeof(int));
		if (!ppx->fd[i])
		{
			ft_freepidfdtrunc(ppx, i);
			return (ft_printerr(ERR_MPIPE));
		}
	}
	return (0);
}

int	ft_openinfile(t_data *ppx, char *str)
{
	if (ppx->hdoc)
	{
		ft_heredoc(str);
		ppx->fd_infile = open(".heredoc_tmp", O_RDONLY);
		if (ppx->fd_infile < 0)
		{
			unlink(".heredoc_tmp");
			ft_printerr(ERR_FILEHEREDOC);
			return (1);
		}
	}
	else
	{
		ppx->fd_infile = open(str, O_RDONLY);
	}
	if (ppx->fd_infile < 0)
	{
		perror(str);
		return (1);
	}
	return (0);
}

int	ft_openoutfile(t_data *ppx, char *file)
{
	if (ppx->hdoc)
		ppx->fd_outfile = open(file, O_WRONLY | O_CREAT | O_APPEND, 0664);
	else
		ppx->fd_outfile = open(file, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (ppx->fd_outfile < 0)
	{
		ft_printerr(ERR_FILE);
		perror(file);
		return (1);
	}
	return (0);
}

char	*ft_findpathstr(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
