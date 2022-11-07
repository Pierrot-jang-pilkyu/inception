/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:37:57 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 19:10:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	parsing_red(t_data *data)
{
	data->red_lto->left = ft_strdup("0");
	data->red_lto->re_num = LTO;
	data->red_lto->token = ft_strdup(data->file1);
	data->red_mto->left = ft_strdup("1");
	data->red_mto->re_num = MTO;
	data->red_mto->token = ft_strdup(data->file2);
	data->red_hrd->left = ft_strdup("0");
	data->red_hrd->re_num = HRD;
	data->red_hrd->token = ft_strjoin(data->file1, "\n");
	data->red_dmto->left = ft_strdup("1");
	data->red_dmto->re_num = DMTO;
	data->red_dmto->token = ft_strdup(data->file2);
}

void	update_data(int *i, int ac, char *const av[], t_data *data)
{
	if (ft_memcmp(av[1], "here_doc", 9) == 0)
	{
		data->red[0] = HRD;
		data->red[1] = DMTO;
		data->pipe_size--;
		data->file1 = ft_strdup(av[2]);
		data->cmds = (char **)malloc(sizeof(char *) * (ac - 4 + 1));
		if (!data->cmds)
			put_error("bash: data->cmds: malloc assign error", NULL);
		*i = 2;
	}
	else
	{
		data->red[0] = LTO;
		data->red[1] = MTO;
		data->file1 = ft_strdup(av[1]);
		data->cmds = (char **)malloc(sizeof(char *) * (ac - 3 + 1));
		if (!data->cmds)
			put_error("bash: data->cmds: malloc assign error", NULL);
		*i = 1;
	}
}

void	parsing(int ac, char *const av[], t_data *data)
{
	int		i;
	char	**temp;

	data->file2 = ft_strdup(av[ac - 1]);
	update_data(&i, ac, av, data);
	temp = data->cmds;
	while (++i < ac - 1)
		*temp++ = ft_strdup(av[i]);
	*temp = NULL;
	parsing_red(data);
}
