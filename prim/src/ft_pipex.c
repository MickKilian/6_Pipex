/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:25:42 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/15 22:51:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipex(t_data *ppx, char **argv, char **envp)
{
	if (ft_makepipes(ppx))
		return (ft_printerr(ERR_PIPES));
	if (ft_makechildrenproc(ppx, argv, envp))
		return (ft_printerr(ERR_CHILDREN));
	return (0);
}

int	ft_makepipes(t_data *ppx)
{
	int	i;

	i = 0;
	while (i < ppx->nb_pipes)
	{
		if (pipe(ppx->fd[i]) == -1)
			return (1);
		i++;
	}
	ppx->fd[i] = NULL;
	return (0);
}

int	ft_makechildrenproc(t_data *ppx, char **argv, char **envp)
{
	int		i;

	i = -1;
	//if (ppx->fd[i + 1])
		//dprintf(2, "Tout va bien\n");
	while (++i < ppx->nb_proc)
	{
		ppx->pid[i] = fork();
		if (ppx->pid[i] == -1)
			return (1);
		if (ppx->pid[i] == 0)
		{
			//dprintf(2, "%s\n", argv[i + 2]);
			if (i == 0)
			{
				if (ft_redirect(ppx->fd_infile, STDIN_FILENO))
				{
					//dprintf(2, "I am here\n");
					return (1);
				}
			}
			else
			{
				//dprintf(2, "I am here1\n");
				//dprintf(2, "%s dup2(%d,%d)\n", argv[i + 2]
				//, ppx->fd[i - 1][0], STDIN_FILENO);
				dup2(ppx->fd[i - 1][0], STDIN_FILENO);
				//dprintf(2, "I am here1ex\n");
			}
			if (i == ppx->nb_proc - 1)
			{
				if (ft_redirect(ppx->fd_outfile, STDOUT_FILENO))
				{	
					//dprintf(2, "I am here\n");
					return (1);
				}
			}
			else
			{
				//dprintf(2, "I am here2\n");
				//dprintf(2, "i = %d\n", i);
				//dprintf(2, "%s dup2(%d,%d)\n", argv[i + 2]
				//, ppx->fd[i][1], STDOUT_FILENO);
				dup2(ppx->fd[i][1], STDOUT_FILENO);
				//dprintf(2, "I am here2ex\n");
			}
			//dprintf(2, "cmd : %s\n", argv[i + 2]);
			//dprintf(2, "I am here_cmd\n");
			ft_leaveopenfdchild(ppx, i);
			if (ft_execve(ppx, argv[i + 2 + ppx->heredoc_offset], envp))
				return (ft_printerr(ERR_EXEC));
			ft_closefdchild(ppx, i);
			return (0);
		}
	}
	ft_closeallfd(ppx);
	//dprintf(2, "(parent)\n");
	i = -1;
	//dprintf(2, "nb_proc = %d\n", ppx->nb_proc);
	while (++i < ppx->nb_proc)
	{
		waitpid(ppx->pid[i], NULL, 0);
		//dprintf(2, "process %s exited\n", argv[i + 2]);
	}
	return (0);
}

int	ft_redirect(int fd_orig, int fd_redir)
{
	//ft_printf("I am here with file redir id = %d\n", fd_redir);
	//dprintf(2, "Redirecting %d in %d\n", fd_orig, fd_redir);
	if (dup2(fd_orig, fd_redir) >= 0)
		return (0);
	else
		return (ft_printerr(ERR_REDIR));
}
