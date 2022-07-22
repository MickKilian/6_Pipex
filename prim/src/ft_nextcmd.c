/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:25:42 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/20 16:56:46 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_pipex(int argc, char *argv[], char *envp[])
{
	int		p1[2]; // C -> P
	//int		p2[2]; // p -> C
	int		id;

	(void)argc;
	(void)argv;
	(void)envp;
	if (pipe(p1)== -1)
		return (1);
	//if (pipe(p2)== -1)
	//	return (2);
	id = fork();
	if (id == -1)
		return (3);
	if (id == 0)
	{
		//CHILD PROCESS
		int		n;
		char	*name = "bonjour";
		close(p1[0]);
//		close(p2[0]);
//		close(p2[1]);
		n = strlen(name) + 1;
		if (write(p1[1], &n, sizeof(int)) == -1)
			return (4);
		if (write(p1[1], name, sizeof(char) * n) == -1)
			return (5);
		ft_printf("Sent word : %s\n", name);
		close(p1[1]);
	}
	else
	{
		//PARENT PROCESS
		int		n;
		char	str[200];
//		close(p2[1]);
		close(p1[1]);
		if (read(p1[0], &n, sizeof(int)) == -1)
			return (6);
		if (read(p1[0], str, sizeof(char) * n) == -1)
			return (7);
		close(p1[0]);
//		close(p2[0]);
		wait(NULL);
		ft_printf("Received word : %s\n", str);
	}
	return (0);
}
