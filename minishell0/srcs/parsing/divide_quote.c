/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:50:49 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 05:38:16 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_quote_open_idx(char *buf, t_prs *prs, int i)
{
	if (i > prs->s_e[START])
	{
		prs->s_e[END] = i - 1;
		into_list(buf, prs, 1);
	}
	prs->s_e[START] = i;
}

void	set_quote_close_idx(char *buf, t_prs *prs, int i, int *flag)
{
	*flag = 0;
	prs->s_e[END] = i;
	into_list(buf, prs, 1);
	prs->s_e[START] = i + 1;
}

void	init_quote_val(int *i, int *flag, t_prs *prs)
{
	*i = -1;
	*flag = 0;
	prs->s_e[START] = 0;
	prs->s_e[END] = 0;
}

void	divide_quote(char *buf, t_prs *prs)
{
	int	i;
	int	flag;

	init_quote_val(&i, &flag, prs);
	while (prs->priority[++i])
	{
		if (!flag && prs->priority[i] == '\"')
		{
			flag = 1;
			set_quote_open_idx(buf, prs, i);
		}
		else if (!flag && prs->priority[i] == '\'')
		{
			flag = 2;
			set_quote_open_idx(buf, prs, i);
		}
		else if (flag == 1 && prs->priority[i] == '\"')
			set_quote_close_idx(buf, prs, i, &flag);
		else if (flag == 2 && prs->priority[i] == '\'')
			set_quote_close_idx(buf, prs, i, &flag);
	}
	if (buf[prs->s_e[END]] == '\0' || buf[prs->s_e[START]] == '\0')
		return ;
	prs->s_e[END] = i;
	into_list(buf, prs, 1);
}
