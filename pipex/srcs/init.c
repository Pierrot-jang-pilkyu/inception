/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:13:08 by pjang             #+#    #+#             */
/*   Updated: 2022/10/28 14:58:10 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_error_token(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * 14);
	res[0] = ft_strdup("<");
	res[1] = ft_strdup("<<");
	res[2] = ft_strdup(">");
	res[3] = ft_strdup(">>");
	res[4] = ft_strdup("|");
	res[5] = ft_strdup("&");
	res[6] = ft_strdup(";");
	res[7] = ft_strdup("(");
	res[8] = ft_strdup(")");
	res[9] = ft_strdup("\n");
	res[10] = ft_strdup("#");
	res[11] = ft_strdup("`");
	res[12] = ft_strdup("*");
	res[13] = NULL;
	return (res);
}

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

void	init_fd(int argc, t_data *data)
{
	int	i;

	data->fd = (int **)malloc(sizeof(int *) * (argc - 1));
	i = -1;
	while (++i < argc - 1)
	{
		data->fd[i] = (int *)malloc(sizeof(int) * 2);
		data->fd[i][0] = -2;
		data->fd[i][1] = -2;
	}
	data->fd[i] = NULL;
}

void	init(int argc, t_data *data, char **envp)
{
	init_fd(argc, data);
	data->pipe_size = argc - 3 - 1;
	data->pid = (pid_t *)malloc(sizeof(pid_t) * (data->pipe_size + 1));
	data->pid[data->pipe_size] = -1;
	data->file1 = NULL;
	data->cmds = NULL;
	data->file2 = NULL;
	data->arg = NULL;
	data->paths = NULL;
	get_path(data, envp);
	data->red_lto = (t_red *)malloc(sizeof(t_red) * 1);
	data->red_hrd = (t_red *)malloc(sizeof(t_red) * 1);
	data->red_mto = (t_red *)malloc(sizeof(t_red) * 1);
	data->red_dmto = (t_red *)malloc(sizeof(t_red) * 1);
	init_red(data->red_lto);
	init_red(data->red_hrd);
	init_red(data->red_mto);
	init_red(data->red_dmto);
}
