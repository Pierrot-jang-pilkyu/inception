/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:48:31 by pjang             #+#    #+#             */
/*   Updated: 2022/10/28 17:11:45 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
// unistd = read, write, wait, pipe, dup, dup2, execve / stdlib = exit
# include <fcntl.h>				// open
# include <stdio.h>				//perror
# include <sys/wait.h>			// fork, waitpid
# define LTO (11)				// <
# define HRD (22)				// <<
# define MTO (33)				// >
# define DMTO (44)				// >>
# define READ (0)
# define WRITE (1)

typedef struct s_red
{
	char	*left;
	char	*right;
	int		re_num;
	int		out_fd;
	char	*buf;
	char	*token;
	char	**e_token;
}				t_red;

typedef struct s_data
{
	pid_t		*pid;
	int			**fd;
	int			red[2];
	int			pipe_size;
	char		*file1;
	char		**cmds;
	char		*file2;
	char		**arg;
	char		**paths;
	t_red		*red_lto;
	t_red		*red_hrd;
	t_red		*red_mto;
	t_red		*red_dmto;
}				t_data;

void	put_error(char *error_msg, char *token);

void	init(int argc, t_data *data, char **envp);
void	parsing(int ac, char *const av[], t_data *data);
void	data_free(t_data *data);
void	safety_free(char *str, char **strs);

// redirection
int		here_doc(t_data *data);
int		valid_token(t_red *red);
int		less_than_operator(t_data *data);
int		more_than_operator(t_data *data);
int		d_more_than_operator(t_data *data);

// backtick
void	get_bt_from_buf(t_red *red);

// pipex
int		get_slash(char *str);
void	arg_return_to_original(t_data *data, int idx);
void	conv_fd(t_data *data, int idx);
int		get_slash(char *str);
void	execute(t_data *data, int idx, char **envp);
void	pipex(t_data *data, int idx, char **envp);
void	fd_closed(t_data *data);

#endif