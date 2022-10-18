/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:02:08 by pjang             #+#    #+#             */
/*   Updated: 2022/10/18 12:05:56 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_buf(t_red *red, int fd)
{
	char	*temp;
	char	*t_buf;

	temp = get_next_line(fd);
	if (!temp)
		return (0);
	while (1)
	{
		t_buf = ft_strdup(red->buf);
		safety_free(red->buf, NULL);
		red->buf = ft_strjoin(t_buf, temp);
		safety_free(temp, NULL);
		safety_free(t_buf, NULL);
		temp = get_next_line(fd);
		if (!temp)
			break ;
	}
	return (1);
}

int	less_than_operator(t_data *data)
{
	int		fd;
	t_red	*red;

	red = data->red_lto;
	valid_token(red);
	fd = open(red->token, O_RDWR);
	if (fd == -1)
	{
		return (0);
		// ft_printf("bash: %s: No such file or directory\n", red->token);
		// exit(1);
	}
	return (fd);
}

int	more_than_operator(t_data *data)
{
	int		fd;
	t_red	*red;

	red = data->red_mto;
	valid_token(red);
	fd = open(red->token, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		return (0);
		// ft_printf("bash: Failure calling the open function\n");
		// exit(1);
	}
	return (fd);
}

int	d_more_than_operator(t_data *data)
{
	int		fd;
	t_red	*red;

	red = data->red_dmto;
	valid_token(red);
	fd = open(red->token, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		return (0);
		// ft_printf("bash: Failure calling the open function\n");
		// exit(1);
	}
	return (fd);
}
