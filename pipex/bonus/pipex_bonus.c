/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:24:42 by pjang             #+#    #+#             */
/*   Updated: 2022/10/28 18:02:34 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipe_limit(t_data *data, int idx)
{
	if (idx < data->pipe_size)
	{
		if (pipe(data->fd[idx]) == -1)
			put_error("bash: Fail pipe function", NULL);
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
	arg_return_to_original(data, idx);
	execute(data, idx, envp);
}

void	pipex(t_data *data, int idx, char **envp)
{
	int	status;

	pipe_limit(data, idx);
	data->pid[idx] = fork();
	if (data->pid[idx] == -1)
		put_error("bash: Fail fork function", NULL);
	if (data->pid[idx] > 0)
	{
		if (idx == data->pipe_size)
		{
			fd_closed(data);
			waitpid(data->pid[idx], &status, 0);
			data_free(data);
			unlink("heredoc");
			if (WIFEXITED(status))
				exit(WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
				exit(WTERMSIG(status));
			return ;
		}
		pipex(data, idx + 1, envp);
	}
	if (data->pid[idx] == 0)
		process_execute(data, idx, envp);
}
