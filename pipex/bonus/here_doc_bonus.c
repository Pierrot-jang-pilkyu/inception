/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 05:11:22 by pjang             #+#    #+#             */
/*   Updated: 2022/11/01 21:57:47 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	read_gnl(t_red *red, int fd)
{
	char	*get;

	while (1)
	{
		write(1, ">", 1);
		get = get_next_line(0);
		if (!get)
			break ;
		if (ft_memcmp(red->token, get, ft_strlen(get)) == 0)
			break ;
		ft_putstr_fd(get, fd);
		safety_free(get, NULL);
	}
}

int	here_doc(t_data *data)
{
	int		fd;
	t_red	*red;

	red = data->red_hrd;
	valid_token(red);
	if (ft_memcmp(data->file2, "heredoc", 8) == 0)
		red->filename = ft_strdup("here_doc");
	else
		red->filename = ft_strdup("heredoc");
	fd = open(red->filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		put_error(NULL, "heredoc");
	read_gnl(red, fd);
	return (fd);
}
