/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:24:42 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 21:17:00 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	pipe_limit(t_data *data, int idx)
{
	if (idx < data->pipe_size)
	{
		if (pipe(data->fd[idx]) == -1)
			put_error("bash: pipe function error", NULL);
	}
}

void	fd_closed(t_data *data)
{
	int	idx;

	idx = -1;
	while (++idx < data->pipe_size)
	{
		close(data->fd[idx][READ]);
		close(data->fd[idx][WRITE]);
	}
}

int	get_slash(char *str)
{
	int	i;
	int	len;
	int	res;

	i = -1;
	len = ft_strlen(str);
	res = -1;
	while (++i < len)
	{
		if (str[i] == '/')
			res = i;
		if (str[i] == ' ')
			break ;
	}
	return (res);
}

void	process_execute(t_data *data, int idx, char **envp)
{
	char	**path;

	arg_return_to_original(data, idx);
	if (data->cmds[idx][0] == '/')
	{
		path = ft_split(data->cmds[idx], ' ');
		if (!path)
			put_error("bash: path: malloc asssign error", NULL);
		conv_fd(data, idx);
		execve(path[0], data->arg, envp);
		safety_free(NULL, path);
		put_error(NULL, data->cmds[idx]);
	}
	execute(data, idx, envp);
}

void	pipex(t_data *data, int idx, char **envp, int status)
{
	pipe_limit(data, idx);
	data->pid[idx] = fork();
	if (data->pid[idx] == -1)
		put_error("bash: fork function error", NULL);
	if (data->pid[idx] > 0)
	{
		if (idx == data->pipe_size)
		{
			fd_closed(data);
			waitpid(data->pid[idx], &status, 0);
			while (wait(&idx) != -1)
				;
			if (!access(data->red_lto->token, F_OK) && data->red[0] == HRD)
				unlink(data->red_lto->token);
			data_free(data);
			if (WIFEXITED(status))
				exit(WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
				exit(WTERMSIG(status));
			return ;
		}
		pipex(data, idx + 1, envp, status);
	}
	if (data->pid[idx] == 0)
		process_execute(data, idx, envp);
}
