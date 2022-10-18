/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:37:57 by pjang             #+#    #+#             */
/*   Updated: 2022/10/18 05:53:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	show(t_data data)
// {
// 	int	i;

// 	ft_printf("file1 : %s\n", data.file1);
// 	ft_printf("file2 : %s\n", data.file2);
// 	i = -1;
// 	while (data.cmds[++i] != NULL)
// 		ft_printf("cmd %d : %s\n", i, data.cmds[i]);
// }

void	parsing_red(t_data *data)
{
	data->red_lto->left = ft_strdup("0");
	data->red_lto->re_num = LTO;
	data->red_lto->token = ft_strdup(data->file1);
	data->red_mto->left = ft_strdup("1");
	data->red_mto->re_num = MTO;
	data->red_mto->token = ft_strdup(data->file2);
}

void	parsing(int ac, char *const av[], t_data *data)
{
	int		i;
	char	**temp;

	data->file1 = ft_strdup(av[1]);
	data->file2 = ft_strdup(av[ac - 1]);
	data->cmds = (char **)malloc(sizeof(char *) * (ac - 3 + 1));
	i = 1;
	temp = data->cmds;
	while (++i < ac - 1)
		*temp++ = ft_strdup(av[i]);
	*temp = NULL;
	parsing_red(data);
}
