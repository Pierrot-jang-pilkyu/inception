/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:02:08 by pjang             #+#    #+#             */
/*   Updated: 2022/11/05 11:49:11 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	less_than_operator(t_data *data)
{
	int		fd;
	t_red	*red;

	red = data->red_lto;
	valid_token(red);
	fd = open(red->token, O_RDWR);
	if (fd == -1)
		put_error(NULL, red->token);
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
		put_error(NULL, red->token);
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
		put_error(NULL, red->token);
	return (fd);
}
