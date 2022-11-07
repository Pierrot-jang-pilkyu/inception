/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:52 by pjang             #+#    #+#             */
/*   Updated: 2022/11/01 21:58:53 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	fp(const char *format, char *token, int i)
{
	ft_printf(format, token);
	if (0 <= i && i <= 10)
		exit(258);
	else if (10 < i)
		exit(1);
	else if (0 > i)
		exit(0);
}

int	valid_file(t_red *red, int i)
{
	if (red->re_num == LTO && access(red->token, R_OK))
	{
		if (!access(red->token, F_OK))
			fp("bash: %s: Permission denied\n", red->token, i);
	}
	if ((red->re_num == MTO || red->re_num == DMTO) && access(red->token, W_OK))
	{
		if (!access(red->token, F_OK))
			fp("bash: %s: Permission denied\n", red->token, i);
	}
	return (red->re_num);
}

int	valid_token(t_red *red)
{
	int		i;
	char	*temp[2];

	temp[0] = ft_strdup("bash: syntax error near unexpected token '%s'\n");
	temp[1] = ft_strdup("bash: %s: ambiguous redirect\n");
	i = -1;
	while (red->e_token[++i] != NULL)
	{
		if (ft_strncmp(red->token, red->e_token[i], 3) == 0)
		{
			if (0 <= i && i <= 10)
				fp(temp[0], red->token, i);
			else if (10 < i)
			{
				if (red->re_num != 2)
					fp(temp[1], red->token, i);
				else
					break ;
			}
		}
	}
	safety_free(temp[0], NULL);
	safety_free(temp[1], NULL);
	return (valid_file(red, i));
}
