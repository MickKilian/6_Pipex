/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:55:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/15 17:26:02 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_heredoc(t_data *ppx, char *argv)
{
	int		fd_tempfile;
	char	*str_gnl;

	fd_tempfile = open("heredoc_file", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd_tempfile < 0)
		ft_printerr(ERR_FILEHEREDOC);
	while (1)
	{
		if (ppx->nb_proc > 1)
			write(1, "pipe heredoc> ", 14);
		else
			write(1, "heredoc> ", 9);
		str_gnl = get_next_line(0);
		if (str_gnl)
		{
			if( !ft_strncmp(str_gnl, argv, ft_strlen(argv))
				&& ft_strlen(argv) == ft_strlen(str_gnl) - 1)
				break;
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
