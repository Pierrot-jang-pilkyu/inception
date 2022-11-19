/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:08:49 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 14:51:21 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// parsing(토큰화)
/*
	buff -> global.read
	buf
	우선순위
	-> list
	-> tree
*/
void	parsing(char *buf)
{
	t_prs	prs;

	init_prs(&prs);
	do_priority(buf, &prs);
	divide_quote(buf, &prs);
	divide_pts(&prs);
	divide_logical(&prs);
	divide_pipe(&prs);
	divide_redirection(&prs);
	t_list *temp;
	printf("\nprs.redirect\n");
	temp = prs.redirect;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	get_token_array(&prs);
	printf("\ng_mini.tkn\n");
	int i = 0;
	while (g_mini.tkn[i].idx != -1)
	{
		printf("tkn[%d] idx : %d\n", i, g_mini.tkn[i].idx);
		printf("tkn[%d] value : %s\n", i, g_mini.tkn[i].value);
		i++;
	}
	free_prs(&prs);
}

void	do_priority(char *buf, t_prs *prs)
{
	int	i;

	safety_free(prs->priority);
	prs->priority = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (!prs->priority)
		exit(1);
	ft_memset((void *)prs->priority, ' ', ft_strlen(buf));
	i = -1;
	while (buf[++i])
	{
		if (is_seq((buf + i)))
			prs->priority[i] = is_seq((buf + i));
		else if (is_seq1((buf + i)))
			prs->priority[i] = is_seq1((buf + i));
		else if (is_seq2((buf + i)))
			prs->priority[i] = is_seq2((buf + i));
		else if (is_seq3((buf + i)))
			prs->priority[i] = is_seq3((buf + i));
		if (prs->priority[i] == AND || prs->priority[i] == OR || \
			prs->priority[i] == HEREDOC || prs->priority[i] == STD_OUTA)
			i++;
	}
	prs->priority[i] = '\0';
}

char	*get_content(char	*buf, t_prs *prs)
{
	int		i;
	char	*res;

	i = prs->s_e[START];
	while (buf[i])
	{
		if (buf[i] != ' ')
		{
			prs->s_e[START] = i;
			break ;
		}
		i++;
	}
	i = prs->s_e[END];
	while (i >= prs->s_e[START])
	{
		if (buf[i] != ' ')
		{
			prs->s_e[END] = i;
			break ;
		}
		i--;
	}
	res = ft_substr(buf, prs->s_e[START], prs->s_e[END] - prs->s_e[START] + 1);
	return (res);
}

void	into_list(char *buf, t_prs *prs, int no)
{
	char	*content;

	content = get_content(buf, prs);
	if (no == 1)
		ft_lstadd_back(&prs->quote, ft_lstnew((void *)content));
	else if (no == 2)
		ft_lstadd_back(&prs->pts, ft_lstnew((void *)content));
	else if (no == 3)
		ft_lstadd_back(&prs->logical, ft_lstnew((void *)content));
	else if (no == 4)
		ft_lstadd_back(&prs->pipe, ft_lstnew((void *)content));
	else if (no == 5)
		ft_lstadd_back(&prs->redirect, ft_lstnew((void *)content));
}
