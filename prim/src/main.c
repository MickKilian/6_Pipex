/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:20:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/20 19:45:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd1;
	char	*infile = "infile";

	(void)argc;
	(void)argv;
	(void)envp;
	//ft_pipex(argc, argv, NULL);
	if (!ft_checkfile(infile, &fd1))
	{
		if (!ft_redirect(fd1, STDIN_FILENO))
			printf("Redirection was successfull!\n");
		else
			printf("Redirection failed!\n");
	}
	else
	{
		perror(infile);
	}
	//ft_execve();
	return (0);
}
