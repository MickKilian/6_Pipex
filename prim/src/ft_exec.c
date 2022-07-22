/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:35:52 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/20 17:52:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_execve(void)
{
	char	*arr[5];
	char	*env[2];

	const char *infile = "toto";

	int fd = open(infile, O_RDWR);

	if (fd < 0)
		perror(infile);


	arr[0] = "ping";
	arr[1] = "-c";
	arr[2] = "3";
	arr[3] = "google.com";
	arr[4] = NULL;

	env[0] = "TEST=environment variable";
	env[1] = NULL;
	//if (execve("/usr/bin/ls", arr, env))
	//	ft_printf("error\n");
	execve("/usr/bin/ping", arr, env);
	ft_printf("Finished executing\n");
	return (0);
}



/*
arr[0] = "pipex";
arr[1] = "infile";
arr[2] = "ls -la";
arr[3] = "wc -c";
arr[4] = "outfile";
*/

