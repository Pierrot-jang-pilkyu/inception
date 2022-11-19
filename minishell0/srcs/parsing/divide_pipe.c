/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:55:53 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 04:38:35 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	divide_pipe2(char *buf, t_prs *prs)
{
	int	i;

	i = -1;
	prs->s_e[START] = 0;
	prs->s_e[END] = 0;
	while (prs->priority[++i])
	{
		if (prs->priority[i] == '|')
		{
			if (i > prs->s_e[START])
			{
				prs->s_e[END] = i - 1;
				into_list(buf, prs, 4);
			}
			prs->s_e[START] = i;
			prs->s_e[END] = i;
			into_list(buf, prs, 4);
			prs->s_e[START] = i + 1;
		}
	}
	if (buf[prs->s_e[END]] != '\0' && buf[prs->s_e[START]] != '\0')
	{
		prs->s_e[END] = i;
		into_list(buf, prs, 4);
	}
}

void	divide_pipe(t_prs *prs)
{
	char	*cg;
	t_list	*temp;

	temp = prs->logical;
	while (temp)
	{
		cg = (char *)temp->content;
		if (cg[0] == '\"' || cg[0] == '\'')
		{
			ft_lstadd_back(&prs->pipe, ft_lstnew(ft_strdup(cg)));
			temp = temp->next;
			continue ;
		}
		do_priority(cg, prs);
		divide_pipe2(cg, prs);
		temp = temp->next;
	}
}
