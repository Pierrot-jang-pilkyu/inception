/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:01:28 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 14:39:55 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_mini	g_mini;

void	get_token_array(t_prs *prs)
{
	int		i;
	char	*buf;
	t_list	*temp;

	temp = prs->redirect;
	init_tkn(temp);
	i = 0;
	while (temp)
	{
		buf = (char *)temp->content;
		if (set_logical_pipe_token(buf, i))
			;
		else if (set_redirection_token(temp, buf, i))
		{
			i++;
			temp = temp->next;
		}
		else
			set_command_token(temp, buf, i);
		i++;
		temp = temp->next;
	}
}

int	*get_tree_idx(void)
{
	int		len;
	int		*res;

	len = 0;
	while (g_mini.tkn[len].idx != -1)
		len++;
	res = (int *)malloc(sizeof(int) * (len + 1));
	if (!res)
		put_error(strerror(errno));
	res[len] = -1;
	len = -1;
	while (g_mini.tkn[++len].idx != -1)
	{
		if (g_mini.tkn[len].idx == AND || g_mini.tkn[len].idx == OR)
			res[len] = 1;
		if (g_mini.tkn[len].idx == PIPE)
			res[len] = 2;
		if (g_mini.tkn[len].idx == STD_IN || g_mini.tkn[len].idx == STD_OUTT || \
			g_mini.tkn[len].idx == HEREDOC || g_mini.tkn[len].idx == STD_OUTA)
			res[len] = 3;
		if (g_mini.tkn[len].idx == COMMAND)
			res[len] = 0;
	}
	return (res);
}

void	get_priority_idx2(int depth, int *i, int right, int *j)
{
	if (depth == 3)
	{
		while (*i < --right)
		{
			if (g_mini.tree_idx[right] == depth)
			{
				if (*j == 0)
					g_mini.tree_idx[right] = 2 * (*j) + 1;
				else
					g_mini.tree_idx[right] = 2 * (*j);
				*j = g_mini.tree_idx[right];
				break ;
			}
		}
		return ;
	}
	while (*(++i) < right)
	{
		if (g_mini.tree_idx[*i] == depth)
		{
			g_mini.tree_idx[*i] = 2 * (*j) + 1;
			*j = g_mini.tree_idx[*i];
			break ;
		}
	}
}

void	get_priority_idx(int depth, int left, int right, int n)
{
	int	i;
	int	j;

	if ((left < right) && (depth < 4))
	{
		i = left - 1;
		j = n;
		get_priority_idx2(depth, &i, right, &j);
		if (j == n)
			get_priority_idx(depth + 1, left, right, j);
		else
		{
			get_priority_idx(depth + 1, left, i, 2 * j);
			if (depth == 3)
				get_priority_idx(depth, i + 1, right, 2 * n + 1);
			else
				get_priority_idx(depth, i + 1, right, 2 * n + 1);
		}
	}
}

void	in_tree(void)
{
	g_mini.tree_idx = get_tree_idx();
}
