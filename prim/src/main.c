/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:20:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 21:58:52 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	ppx;

	ft_bzero(&ppx, sizeof(t_data));
	if (argc != 5)
		return (ft_printerr(ERR_ARGS));
	else
	{
		if (ft_initpath(&ppx, argc, envp)
			|| ft_initprocpip(&ppx, argc, argv))
		{
			if (ppx.path_env)
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
