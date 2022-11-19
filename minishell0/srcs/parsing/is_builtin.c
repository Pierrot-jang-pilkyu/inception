/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:43:15 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 04:50:24 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_builtin_name(void)
{
	char	*buf;
	char	**res;

	buf = ft_strdup("echo cd pwd export unset env exit");
	res = ft_split(buf, ' ');
	safety_free(buf);
	return (res);
}

int	is_builtin(char	*token)
{
	int		i;
	char	**builtin;
	char	**temp;

	builtin = get_builtin_name();
	temp = ft_split(token, ' ');
	i = 0;
	while (i < 7)
	{
		if (ft_memcmp(token, builtin, ft_strlen(temp[0])) == 0)
		{
			safety_dimention_free(builtin);
			safety_dimention_free(temp);
			return (1);
		}
		i++;
	}
	safety_dimention_free(builtin);
	safety_dimention_free(temp);
	return (0);
}
