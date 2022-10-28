/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:53:46 by pjang             #+#    #+#             */
/*   Updated: 2022/10/28 04:12:45 by pjang            ###   ########.fr       */
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
	char	*temp1;

	if (token)
	{
		token = get_token_path(token);
		if (get_slash(token) != -1)
		{
			temp = ft_strjoin("bash: ", token);
			temp1 = ft_strjoin(temp, ": No such file or directory");
		}
		else
		{
			temp = ft_strjoin("bash: ", token);
			temp1 = ft_strjoin(temp, ": command not found");
		}
		ft_putendl_fd(temp1, STDERR_FILENO);
		safety_free(temp, NULL);
		safety_free(temp1, NULL);
		exit(127);
	}
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
