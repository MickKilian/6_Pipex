/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:28:25 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/15 16:12:55 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft.h"
# include "get_next_line_bonus.h"

# define ERR_ARGS "Error : Too few arguments"
# define ERR_FILEHEREDOC "Error with heredoc"
# define ERR_PATHENV "Error : Env Path not found"
# define ERR_REDIR "Redirection Error"
# define ERR_FILE "File Error"
# define ERR_MPROC "Error with malloc (processes)"
# define ERR_MPIPE "Error with malloc (pipes)"
# define ERR_INIT "---> Initialization Error"
# define ERR_PIPES "Error while creating pipes"
# define ERR_CHILDREN "---> Child process failed"
# define ERR_CMDSPLIT "Error while splitting command instruction"
# define ERR_CMDPATH "Error : Command not found"
# define ERR_EXEC "---> Command execution failed"
# define OFFSET "   "

typedef struct s_data
{
	int		fd_infile;
	int		fd_outfile;
	int		heredoc_offset;
	int		**fd;
	int		*pid;
	char	*path_env;
	char	*cmd_path;
	int		nb_pipes;
	int		nb_proc;
} t_data;

enum
{
	TOOFEW
};

// main.c
int	main(int argc, char **argv, char **envp);

// ft_pipex.c
int		ft_pipex(t_data *ppx, char **argv, char **envp);
int		ft_makepipes(t_data *ppx);
int		ft_makechildrenproc(t_data *ppx, char **argv, char **envp);
int		ft_redirect(int fd_orig, int fd_redir);

// ft_initialize.c
int		ft_initialize(t_data *ppx, int argc, char **argv, char **envp);
int		ft_openinfile(t_data *ppx, char *file);
int		ft_openoutfile(t_data *ppx, char *file);

// ft_freeclose.c
void	ft_freefd(int **fd);
void	ft_leaveopen(t_data *ppx, int fdi, int fdj);
void	ft_closeallfd(t_data *ppx);
void	ft_freeclose(t_data *ppx);

// ft_managerr.c
int		ft_printerr(char *errmsg);

// ft_exec.c
char	*ft_findpathstr(char **envp);
char	*ft_findcmdpath(char *cmd, char *path_str);
int		ft_execve(t_data *ppx, char *cmd_str, char **envp);

// ft_heredoc.c
int		ft_heredoc(t_data *ppx, char *argv);

#endif
