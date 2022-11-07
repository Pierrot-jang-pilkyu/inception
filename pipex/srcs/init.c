/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:13:08 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 17:38:25 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_red(t_red *red)
{
	red->left = NULL;
	red->right = NULL;
	red->re_num = 0;
	red->out_fd = -1;
	red->buf = NULL;
	red->token = NULL;
	red->e_token = get_error_token();
}

void	get_path(t_data *data, char **envp)
{
	char	*strs;
	char	**temp;

	temp = envp;
	strs = NULL;
	while (*temp != NULL)
	{
		if (ft_strncmp(*temp, "PATH=", 5) == 0)
		{
			strs = ft_substr(*temp, 5, 1024);
			break ;
		}
		temp++;
	}
	data->paths = ft_split(strs, ':');
	safety_free(strs, NULL);
}

void	init_fd(t_data *data)
{
	int	i;

	data->fd = (int **)malloc(sizeof(int *) * (data->pipe_size + 1));
	if (!data->fd)
		put_error("bash: data->fd: memory assign error", NULL);
	i = -1;
	while (++i < data->pipe_size)
	{
		data->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!data->fd[i])
			put_error("bash: *data->fd: memory assign error", NULL);
		data->fd[i][0] = -2;
		data->fd[i][1] = -2;
	}
	data->fd[i] = NULL;
}

void	init_data_dalloc(t_data *data)
{
	data->pid = (pid_t *)malloc(sizeof(pid_t) * (data->pipe_size + 1));
	if (!data->pid)
		put_error("bash: data->pid: memory assign error", NULL);
	data->pid[data->pipe_size] = -1;
	data->red_lto = (t_red *)malloc(sizeof(t_red) * 1);
	if (!data->red_lto)
		put_error("bash: data->red_lto: memory assign error", NULL);
	data->red_hrd = (t_red *)malloc(sizeof(t_red) * 1);
	if (!data->red_hrd)
		put_error("bash: data->red_hrd: memory assign error", NULL);
	data->red_mto = (t_red *)malloc(sizeof(t_red) * 1);
	if (!data->red_mto)
		put_error("bash: data->red_mto: memory assign error", NULL);
	data->red_dmto = (t_red *)malloc(sizeof(t_red) * 1);
	if (!data->red_dmto)
		put_error("bash: data->red_dmto: memory assign error", NULL);
}

void	init(int argc, t_data *data, char **envp)
{
	data->pipe_size = argc - 3 - 1;
	init_fd(data);
	data->file1 = NULL;
	data->cmds = NULL;
	data->file2 = NULL;
	data->arg = NULL;
	data->paths = NULL;
	get_path(data, envp);
	init_data_dalloc(data);
	init_red(data->red_lto);
	init_red(data->red_hrd);
	init_red(data->red_mto);
	init_red(data->red_dmto);
}
