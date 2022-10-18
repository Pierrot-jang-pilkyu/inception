/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:24:42 by pjang             #+#    #+#             */
/*   Updated: 2022/10/18 11:49:08 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipe_limit(t_data *data, int idx)
{
	if (idx < data->pipe_size)
	{
		if (pipe(data->fd[idx]) == -1)
			put_error(STDERR_FILENO, "bash: Failure call the pipe function");
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

void	process_execute(t_data *data, int idx, char **envp)
{
	data->arg = (char *const *)ft_split(data->cmds[idx], ' ');
	execute(data, idx, envp);
}

void	pipex(t_data *data, int idx, char **envp)
{
	int	status;

	pipe_limit(data, idx);
	data->pid[idx] = fork();
	if (data->pid[idx] == -1)
		put_error(STDERR_FILENO, "bash: Failure call the fork function");
	if (data->pid[idx] > 0)
	{
		if (idx == data->pipe_size)
		{
			fd_closed(data);
			while (wait(&status) != -1)
				;
			return ;
		}
		pipex(data, idx + 1, envp);
	}
	if (data->pid[idx] == 0)
		process_execute(data, idx, envp);
}
