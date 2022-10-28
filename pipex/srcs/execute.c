/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:06:34 by pjang             #+#    #+#             */
/*   Updated: 2022/10/28 17:01:49 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	choose_red(t_data *data, int idx)
{
	if (idx == 0)
	{
		return (less_than_operator(data));
	}
	if (idx == data->pipe_size)
	{
		if (data->red[1] == MTO)
			return (more_than_operator(data));
		if (data->red[1] == DMTO)
			return (d_more_than_operator(data));
	}
	exit(EXIT_FAILURE);
}

void	conv_fd(t_data *data, int idx)
{
	int	fd;

	if (idx == 0)
	{
		fd = choose_red(data, idx);
		dup2(fd, STDIN_FILENO);
		dup2(data->fd[idx][WRITE], STDOUT_FILENO);
		close(fd);
	}
	else if (0 < idx && idx < data->pipe_size)
	{
		dup2(data->fd[idx - 1][READ], STDIN_FILENO);
		dup2(data->fd[idx][WRITE], STDOUT_FILENO);
	}
	else if (idx == data->pipe_size)
	{
		fd = choose_red(data, idx);
		dup2(data->fd[idx - 1][READ], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	fd_closed(data);
}

void	execute(t_data *data, int idx, char **envp)
{
	char	*path;
	char	*p_temp;
	char	**temp;

	conv_fd(data, idx);
	temp = data->paths;
	while (*temp != NULL)
	{
		p_temp = ft_strjoin(*temp, "/");
		path = ft_strjoin(p_temp, data->arg[0]);
		safety_free(p_temp, NULL);
		execve(path, data->arg, envp);
		safety_free(path, NULL);
		temp++;
	}
	put_error(NULL, data->arg[0]);
}
