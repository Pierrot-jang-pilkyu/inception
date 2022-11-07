/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:06:34 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 20:43:57 by pjang            ###   ########.fr       */
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

char	*getpath(t_data *data)
{
	int		flag;
	char	*path;
	char	*p_temp;
	char	**temp;

	flag = 0;
	temp = data->paths;
	path = NULL;
	while (*temp != NULL)
	{
		safety_free(path, NULL);
		p_temp = ft_strjoin(*temp, "/");
		path = ft_strjoin(p_temp, data->arg[0]);
		if (!p_temp || !path)
			put_error("bash : getpath: malloc assign error", NULL);
		safety_free(p_temp, NULL);
		if (!access(path, F_OK))
		{
			flag = 1;
			break ;
		}
		temp++;
	}
	return (path);
}

void	execute(t_data *data, int idx, char **envp)
{
	char	*path;

	conv_fd(data, idx);
	if (!data->arg[0])
		put_error("bash: data->arg[0]: null pointer", NULL);
	path = getpath(data);
	if (!path)
		put_error("bash: getpath in exec: malloc assign error", NULL);
	execve(path, (char *const *)data->arg, envp);
	safety_free(path, NULL);
	if (*data->cmds[idx] == '/')
		put_error(NULL, data->arg[0]);
	else
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(data->arg[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}
