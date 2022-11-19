/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:41:50 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 04:41:19 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_prs(t_prs *prs)
{
	prs->quote = (t_list *)malloc(sizeof(t_list));
	if (!prs->quote)
		exit(1);
	prs->quote->content = (void *)ft_strdup("head");
	prs->pts = (t_list *)malloc(sizeof(t_list));
	if (!prs->pts)
		exit(1);
	prs->pts->content = (void *)ft_strdup("head");
	prs->logical = (t_list *)malloc(sizeof(t_list));
	if (!prs->logical)
		exit(1);
	prs->logical->content = (void *)ft_strdup("head");
	prs->pipe = (t_list *)malloc(sizeof(t_list));
	if (!prs->pipe)
		exit(1);
	prs->pipe->content = (void *)ft_strdup("head");
	prs->redirect = (t_list *)malloc(sizeof(t_list));
	if (!prs->redirect)
		exit(1);
	prs->redirect->content = (void *)ft_strdup("head");
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

void	set_pts_open_idx(char *buf, t_prs *prs, int i)
{
	if (i > prs->s_e[START])
	{
		prs->s_e[END] = i - 1;
		into_list(buf, prs, 2);
	}
	prs->s_e[START] = i + 1;
}

void	divide_pts2(char *buf, t_prs *prs)
{
	int	i;

	i = -1;
	prs->s_e[START] = 0;
	prs->s_e[END] = 0;
	while (prs->priority[++i])
	{
		if (prs->priority[i] == '(')
			set_pts_open_idx(buf, prs, i);
		else if (prs->priority[i] == ')')
		{
			prs->s_e[END] = i - 1;
			into_list(buf, prs, 2);
			prs->s_e[START] = i + 1;
		}
	}
	if (buf[prs->s_e[END]] != '\0' && buf[prs->s_e[START]] != '\0')
	{
		prs->s_e[END] = i;
		into_list(buf, prs, 2);
	}
}

void	divide_pts(t_prs *prs)
{
	char	*cg;
	t_list	*temp;

	temp = prs->quote->next;
	while (temp)
	{
		cg = (char *)temp->content;
		if (cg[0] == '\"' || cg[0] == '\'')
		{
			ft_lstadd_back(&prs->pts, ft_lstnew(temp->content));
			temp = temp->next;
			continue ;
		}
		do_priority(cg, prs);
		divide_pts2(cg, prs);
		temp = temp->next;
	}
}

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

	temp = prs->pts->next;
	while (temp)
	{
		cg = (char *)temp->content;
		if (cg[0] == '\"' || cg[0] == '\'')
		{
			ft_lstadd_back(&prs->logical, ft_lstnew(temp->content));
			temp = temp->next;
			continue ;
		}
		do_priority(cg, prs);
		divide_logical2(cg, prs);
		temp = temp->next;
	}
}

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

	temp = prs->logical->next;
	while (temp)
	{
		cg = (char *)temp->content;
		if (cg[0] == '\"' || cg[0] == '\'')
		{
			ft_lstadd_back(&prs->pipe, ft_lstnew(temp->content));
			temp = temp->next;
			continue ;
		}
		do_priority(cg, prs);
		divide_pipe2(cg, prs);
		temp = temp->next;
	}
}

void	divide_redirection2(char *buf, t_prs *prs)
{
	int	i;

	i = -1;
	prs->s_e[START] = 0;
	prs->s_e[END] = 0;
	while (prs->priority[++i])
	{
		if (prs->priority[i] == STD_IN)
		{
			if (i > prs->s_e[START])
			{
				prs->s_e[END] = i - 1;
				into_list(buf, prs, 5);
			}
			prs->s_e[START] = i;
			prs->s_e[END] = i;
			into_list(buf, prs, 5);
			prs->s_e[START] = i + 1;
		}
		else if (prs->priority[i] == HEREDOC)
		{
			if (i > prs->s_e[START])
			{
				prs->s_e[END] = i - 1;
				into_list(buf, prs, 5);
			}
			prs->s_e[START] = i;
			prs->s_e[END] = i + 1;
			into_list(buf, prs, 5);
			prs->s_e[START] = i + 2;
		}
		else if (prs->priority[i] == STD_OUTT)
		{
			if (i > prs->s_e[START])
			{
				prs->s_e[END] = i - 1;
				into_list(buf, prs, 5);
			}
			prs->s_e[START] = i;
			prs->s_e[END] = i;
			into_list(buf, prs, 5);
			prs->s_e[START] = i + 1;
		}
		else if (prs->priority[i] == STD_OUTA)
		{
			if (i > prs->s_e[START])
			{
				prs->s_e[END] = i - 1;
				into_list(buf, prs, 5);
			}
			prs->s_e[START] = i;
			prs->s_e[END] = i + 1;
			into_list(buf, prs, 5);
			prs->s_e[START] = i + 2;
		}
	}
	if (buf[prs->s_e[END]] != '\0' && buf[prs->s_e[START]] != '\0')
	{
		prs->s_e[END] = i;
		into_list(buf, prs, 5);
	}
}

void	divide_redirection(t_prs *prs)
{
	char	*cg;
	t_list	*temp;

	temp = prs->pipe->next;
	while (temp)
	{
		cg = (char *)temp->content;
		if (cg[0] == '\"' || cg[0] == '\'')
		{
			ft_lstadd_back(&prs->redirect, ft_lstnew(temp->content));
			temp = temp->next;
			continue ;
		}
		do_priority(cg, prs);
		divide_redirection2(cg, prs);
		temp = temp->next;
	}
}

void	divide(char	*buf)
{
	int		i;
	char	*cg;
	t_prs	prs;
	t_list	*temp;

	init_prs(&prs);
	do_priority(buf, &prs);
	divide_quote(buf, &prs);
	divide_pts(&prs);
	divide_logical(&prs);
	divide_pipe(&prs);
	divide_redirection(&prs);
	printf("\nprs.quote\n");
	temp = prs.quote;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("\nprs.pts\n");
	temp = prs.pts;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("\nprs.logical\n");
	temp = prs.logical;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("\nprs.pipe\n");
	temp = prs.pipe;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("\nprs.redirect\n");
	temp = prs.redirect;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}

void	parsing(char *buf)
{
	divide(buf);
}

int main(void)
{
	char	*str = ft_strdup("h(ls) < in && echo \"llo\" | || | world >> out");

	divide(str);
}