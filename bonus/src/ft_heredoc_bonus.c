/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:55:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:38:20 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_heredoc(char *argv)
{
	int		fd_tempfile;
	char	*str_gnl;

	fd_tempfile = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_tempfile < 0)
		ft_printerr(ERR_FILEHEREDOC);
	while (1)
	{
		write(1, ">", 1);
		str_gnl = get_next_line(0);
		if (str_gnl)
		{
			if (!ft_strncmp(str_gnl, argv, ft_strlen(argv))
				&& ft_strlen(argv) == ft_strlen(str_gnl) - 1)
				break ;
			else
			{
				write(fd_tempfile, str_gnl, ft_strlen(str_gnl));
				free(str_gnl);
			}
		}
	}
	free(str_gnl);
	close(fd_tempfile);
	return (0);
}
