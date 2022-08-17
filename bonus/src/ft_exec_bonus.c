/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:35:52 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:15:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_findcmdpath(t_data *ppx, char *cmd)
{
	char	*cmd_str;
	char	*temp;
	int		i;

	i = 0;
	while (ppx->path_spt[i])
	{
		temp = ft_strjoin(ppx->path_spt[i], "/");
		cmd_str = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(cmd_str, 0))
			return (cmd_str);
		else
			free(cmd_str);
		i++;
	}
	return (NULL);
}

int	ft_execve(t_data *ppx, char *cmd_str, char **envp)
{
	char	**cmd_spt;

	cmd_spt = ft_split(cmd_str, ' ');
	if (!cmd_spt)
		return (ft_printerr(ERR_CMDSPLIT));
	else
	{
		execve(cmd_spt[0], cmd_spt, envp);
		ppx->cmd_path = ft_findcmdpath(ppx, cmd_spt[0]);
		if (!ppx->cmd_path)
		{
			ft_printcomperr(ERR_CMDPATH, cmd_spt[0]);
			ft_freemallocchartrunc(cmd_spt, -1);
			return (1);
		}
		else if (execve(ppx->cmd_path, cmd_spt, envp) == -1)
		{
			ft_freemallocchartrunc(cmd_spt, -1);
			free(ppx->cmd_path);
			return (ft_printerr(ERR_EXECVE));
		}
	}
	return (0);
}
