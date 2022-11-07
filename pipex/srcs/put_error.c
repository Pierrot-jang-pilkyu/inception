/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:53:46 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 21:19:02 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_token_path(char *token)
{
	char	**temp;

	temp = ft_split(token, ' ');
	return (temp[0]);
}

void	put_error(char *error_msg, char *token)
{
	char	*temp;

	if (token)
	{
		token = get_token_path(token);
		temp = ft_strjoin("bash: ", token);
		perror(temp);
		safety_free(temp, NULL);
		exit(127);
	}
	ft_putendl_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}
