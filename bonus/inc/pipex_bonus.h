/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:28:25 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/17 16:52:25 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft.h"
# include "get_next_line.h"

# define ERR_ARGS "Error : Too few arguments\n"
# define ERR_FILEHEREDOC "Error with heredoc\n"
# define ERR_PATHENV "Error : Env Path not found\n"
# define ERR_PATHSPLIT "Error while splitting environment path\n"
# define ERR_REDIR "Redirection Error\n"
# define ERR_FILE "File Error\n"
# define ERR_MPROC "Error with malloc (processes)\n"
# define ERR_MPIPE "Error with malloc (pipes)\n"
# define ERR_INIT "---> Initialization Error\n"
# define ERR_PIPES "Error while creating pipes\n"
# define ERR_CHILDREN "---> Child process failed\n"
# define ERR_CMDSPLIT "Error while splitting command instruction\n"
# define ERR_CMDPATH "Command not found : "
# define ERR_EXECVE "Error : Could not find program to execute\n"
# define ERR_EXEC "---> Command execution failed\n"
# define OFFSET "   "

typedef struct s_data
{
	int		fd_infile;
	int		fd_outfile;
	int		hdoc;
	int		**fd;
	int		*pid;
	char	*path_env;
	char	**path_spt;
	char	*cmd_path;
	int		nb_pipes;
	int		nb_proc;
}	t_data;

enum
{
	TOOFEW
};

// main.c
int		main(int argc, char **argv, char **envp);

// ft_pipex.c
int		ft_pipex(t_data *ppx, char **argv, char **envp);
int		ft_makepipes(t_data *ppx);
int		ft_makechildrenproc(t_data *ppx, char **argv, char **envp);

// ft_initialize.c
int		ft_initpath(t_data *ppx, int argc, char **envp);
int		ft_initprocpip(t_data *ppx, int argc, char **argv);
int		ft_openinfile(t_data *ppx, char *file);
int		ft_openoutfile(t_data *ppx, char *file);
char	*ft_findpathstr(char **envp);

// ft_freeclose.c
void	ft_closeallfd(t_data *ppx);
void	ft_freemallocinttrunc(int **temp, int trunc);
void	ft_freemallocchartrunc(char **temp, int trunc);
void	ft_freepidfdtrunc(t_data *ppx, int trunc);
void	ft_freeall(t_data *ppx, int trunc);

// ft_managerr.c
int		ft_printerr(char *errmsg);
int		ft_printcomperr(char *str1, char *str2);

// ft_redirect.c
int		ft_redirect(int fd_orig, int fd_redir);
int		ft_inoutfileredirect(t_data *ppx);
int		ft_fdchildredirect(t_data *ppx, int i);

// ft_exec.c
char	*ft_findcmdpath(t_data *ppx, char *cmd);
int		ft_execve(t_data *ppx, char *cmd_str, char **envp);

// ft_heredoc.c
int		ft_heredoc(char *argv);

#endif
