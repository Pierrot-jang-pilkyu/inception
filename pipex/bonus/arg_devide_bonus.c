/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_devide_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:08:20 by pjang             #+#    #+#             */
/*   Updated: 2022/10/28 17:55:59 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	arg_2(t_data *data, t_list **list, int idx, int i)
{
	int		flag;
	int		begin;
	char	delim;

	delim = ' ';
	begin = 0;
	flag = 0;
	while (data->cmds[idx][++i])
	{
		while (data->cmds[idx][i] && data->cmds[idx][i] == delim)
			i++;
		if (!flag && (data->cmds[idx][i] == '\'' || data->cmds[idx][i] == '\"'))
		{
				delim = data->cmds[idx][i];
				flag = 1;
		}
		while (data->cmds[idx][i] && data->cmds[idx][i] != delim)
			i++;
		if (i != 0 && begin != i)
			ft_lstadd_back(list, \
				ft_lstnew(ft_substr(data->cmds[idx], begin, i - begin)));
		begin = i + 1;
	}
}

void	arg_3(char *cmd, t_list **list, int i)
{
	int		flag;
	int		begin;
	char	delim;

	delim = ' ';
	begin = 0;
	flag = 0;
	while (cmd[++i])
	{
		while (cmd[i] && cmd[i] == delim)
			i++;
		if (!flag && (cmd[i] == '\'' || cmd[i] == '\"'))
		{
				delim = cmd[i];
				flag = 1;
		}
		if (i != 0)
			ft_lstadd_back(list, \
				ft_lstnew(ft_substr(cmd, begin, i - begin - 1)));
		begin = i;
		while (cmd[i] && cmd[i] != delim)
			i++;
	}
}

void	get_slash_cmd(t_data *data, int idx, char *cmd)
{
	int		slash;
	char	*temp;
	char	*temp1;

	temp = data->cmds[idx];
	slash = get_slash(temp);
	if (slash != -1)
	{
		temp1 = ft_substr(temp, ++slash, ft_strlen(temp));
		cmd = ft_strdup(temp1);
		safety_free(temp1, NULL);
	}
}

void	arg_return_to_original(t_data *data, int idx)
{
	int		i;
	char	*cmd;
	t_list	*list;
	t_list	*temp;

	cmd = NULL;
	safety_free(NULL, data->arg);
	if (data->cmds[idx][0] != '/')
		arg_2(data, &list, idx, -1);
	else
	{
		get_slash_cmd(data, idx, cmd);
		arg_3(cmd, &list, -1);
	}
	data->arg = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	temp = list;
	i = -1;
	while (++i < ft_lstsize(list))
	{
		data->arg[i] = ft_strdup((const char *)temp->content);
		temp = temp->next;
	}
}
