/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:20:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:20:53 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	ppx;

	ft_bzero(&ppx, sizeof(t_data));
	ppx.hdoc = 0;
	if (!ft_strncmp(argv[1], "here_doc", 9))
		ppx.hdoc = 1;
	if (argc < 5 + ppx.hdoc)
		return (ft_printerr(ERR_ARGS));
	else
	{
		if (ft_initpath(&ppx, argc, envp)
			|| ft_initprocpip(&ppx, argc, argv))
		{
			ft_freemallocchartrunc(ppx.path_spt, -1);
			ft_printerr(ERR_INIT);
			return (1);
		}
		if (ft_pipex(&ppx, argv, envp))
		{
			ft_freeall(&ppx, -1);
			return (1);
		}
		ft_freeall(&ppx, -1);
	}
	return (0);
}
