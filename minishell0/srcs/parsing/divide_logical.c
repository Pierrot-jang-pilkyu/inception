/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_logical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:54:35 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 04:38:29 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_logical_idx(char *buf, t_prs *prs, int i)
{
	if (i > prs->s_e[START])
	{
		prs->s_e[END] = i - 1;
		into_list(buf, prs, 3);
	}
	prs->s_e[START] = i;
	prs->s_e[END] = i + 1;
	into_list(buf, prs, 3);
	prs->s_e[START] = i + 2;
}

void	divide_logical2(char *buf, t_prs *prs)
{
	int	i;

	i = -1;
	prs->s_e[START] = 0;
	prs->s_e[END] = 0;
	while (prs->priority[++i])
	{
		if (prs->priority[i] == '&')
			set_logical_idx(buf, prs, i);
		else if ((int)prs->priority[i] == OR)
			set_logical_idx(buf, prs, i);
	}
	if (buf[prs->s_e[END]] != '\0' && buf[prs->s_e[START]] != '\0')
	{
		prs->s_e[END] = i;
		into_list(buf, prs, 3);
	}
}

void	divide_logical(t_prs *prs)
{
	char	*cg;
	t_list	*temp;

	temp = prs->pts;
	while (temp)
	{
		cg = (char *)temp->content;
		if (cg[0] == '\"' || cg[0] == '\'')
		{
			ft_lstadd_back(&prs->logical, ft_lstnew(ft_strdup(cg)));
			temp = temp->next;
			continue ;
		}
		do_priority(cg, prs);
		divide_logical2(cg, prs);
		temp = temp->next;
	}
}
