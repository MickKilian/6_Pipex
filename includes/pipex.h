/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:28:25 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/20 19:39:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../lib/libft/src/libft.h"

// main.c
int	main(int argc, char *argv[], char *envp[]);

// pipex.c
int	ft_pipex(int argc, char *argv[], char *envp[]);

// ft_exec.c
int	ft_execve(void);

// ft_filemanage.c
int	ft_checkfile(char *file, int *fd);
int	ft_redirect(int fd_orig, int fd_redir);

#endif
