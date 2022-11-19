/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_pts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:53:53 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 05:57:21 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_pts_open_idx(char *buf, t_prs *prs, int i, int *flag)
{
	*flag = 1;
	if (i > prs->s_e[START])
	{
		prs->s_e[END] = i - 1;
		into_list(buf, prs, 2);
	}
	prs->s_e[START] = i + 1;
}

void	set_pts_finish_idx(char *buf, t_prs *prs, int i)
{
	if (buf[i - 1] == '(' || buf[i - 1] == ')')
		prs->s_e[END] = i - 2;
	else
		prs->s_e[END] = i;
	into_list(buf, prs, 2);
}

void	divide_pts2(char *buf, t_prs *prs)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	prs->s_e[START] = 0;
	prs->s_e[END] = 0;
	while (prs->priority[++i])
	{
		if (!flag && prs->priority[i] == '(')
			set_pts_open_idx(buf, prs, i, &flag);
		else if (flag && prs->priority[i] == ')')
		{
			flag = 0;
			prs->s_e[END] = i - 1;
			into_list(buf, prs, 2);
			prs->s_e[START] = i + 1;
		}
	}
	if (buf[prs->s_e[END]] != '\0' && buf[prs->s_e[START]] != '\0')
		set_pts_finish_idx(buf, prs, i);
}

void	divide_pts(t_prs *prs)
{
	char	*cg;
	t_list	*temp;

	temp = prs->quote;
	while (temp)
	{
		cg = (char *)temp->content;
		if (cg[0] == '\"' || cg[0] == '\'')
		{
			ft_lstadd_back(&prs->pts, ft_lstnew(ft_strdup(cg)));
			temp = temp->next;
			continue ;
		}
		do_priority(cg, prs);
		divide_pts2(cg, prs);
		temp = temp->next;
	}
}
