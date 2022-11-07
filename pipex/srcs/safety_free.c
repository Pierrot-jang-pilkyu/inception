/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:42:12 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 19:13:10 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	red_free(t_red *red)
{
	safety_free(red->left, NULL);
	safety_free(red->right, NULL);
	safety_free(red->buf, NULL);
	safety_free(red->token, red->e_token);
}

void	data_free(t_data *data)
{
	int	i;

	safety_free(data->file1, NULL);
	safety_free(data->file2, data->cmds);
	safety_free(NULL, (char **)data->arg);
	safety_free(NULL, data->paths);
	red_free(data->red_lto);
	red_free(data->red_hrd);
	red_free(data->red_mto);
	red_free(data->red_dmto);
	free(data->red_lto);
	free(data->red_hrd);
	free(data->red_mto);
	free(data->red_dmto);
	free(data->pid);
	i = -1;
	while (++i < data->pipe_size)
		free(data->fd[i]);
	free(data->fd);
}

void	safety_free(char *str, char **strs)
{
	char	**temp;

	if (str)
	{
		free(str);
		str = NULL;
	}
	if (strs)
	{
		temp = strs;
		while (*strs != NULL)
		{
			if (*strs)
				free(*strs);
			*strs++ = NULL;
		}
		strs = temp;
		free(strs);
		strs = NULL;
	}
}
