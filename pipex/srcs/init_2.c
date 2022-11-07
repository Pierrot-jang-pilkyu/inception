/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:04:39 by pjang             #+#    #+#             */
/*   Updated: 2022/11/01 22:06:39 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_error_token(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * 14);
	if (!res)
		put_error("bash: res", NULL);
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
