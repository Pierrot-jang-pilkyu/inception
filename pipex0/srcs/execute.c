/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:06:34 by pjang             #+#    #+#             */
/*   Updated: 2022/10/18 11:56:20 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// fd conversion!!!
void	conv_fd(t_data *data, int idx)
{
	int	fd;

	if (idx == 0)
	{
		fd = less_than_operator(data);
		dup2(fd, STDIN_FILENO);
		dup2(data->fd[idx][WRITE], STDOUT_FILENO);
		close(fd);
	}
	else if (0 < idx && idx < data->pipe_size - 1)
	{
		dup2(data->fd[idx - 1][READ], STDIN_FILENO);
		dup2(data->fd[idx][WRITE], STDOUT_FILENO);
	}
	else if (idx == data->pipe_size - 1)
	{
		fd = more_than_operator(data);
		if (dup2(data->fd[idx - 1][READ], STDIN_FILENO) == -1)
			ft_putendl_fd("bash: Pipe error", STDERR_FILENO);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	fd_closed(data);
}

void	execute(t_data *data, int idx, char **envp)
{
	char	*err_msg;
	char	*err_tmp;
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
		temp++;
	}
	err_tmp = ft_strjoin("bash: ", data->arg[0]);
	err_msg = ft_strjoin(err_tmp, ": command not found");
	put_error(STDERR_FILENO, err_msg);
	safety_free(err_msg, NULL);
	safety_free(err_tmp, NULL);
	exit(1);
}
