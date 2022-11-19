/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:43 by pjang             #+#    #+#             */
/*   Updated: 2022/11/18 22:34:07 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*g_lst;

void	append_list(char *token)
{
	ft_lstadd_back(&g_lst, ft_lstnew((void *)token));
}

char	*get_red_end_idx(char *c_tmp, char deli, int space_count, int flag)
{
	while (*c_tmp)
	{
		while (*c_tmp && *c_tmp == deli)
		{
			space_count++;
			c_tmp++;
		}
		if (space_count > 1 && flag == 0)
			break ;
		if (space_count > 0 && flag == 1)
			break ;
		while (*c_tmp && *c_tmp != deli)
			c_tmp++;
	}
	return (c_tmp);
}

void	get_redirection_idx(char *c, int idx, int **s_e)
{
	int		space_count;
	char	deli;
	char	*c_tmp;

	space_count = 0;
	deli = ' ';
	*s_e[0] = idx;
	c_tmp = c;
	if (idx > 0)
	{
		if (ft_isdigit(*(c - 1)))
			*s_e[0] = idx - 1;
	}
	if (*(c + 1) == ' ')
		*(*s_e + 1) = get_red_end_idx(c_tmp, deli, space_count, 0) - c - 2;
	else
		*(*s_e + 1) = get_red_end_idx(c_tmp, deli, space_count, 1) - c - 2;
}

void	get_open_close_idx(int result, int *flag, int **s_e, int idx)
{
	if (result == 1)
	{
		if (*flag == 0 || *flag == 2)
		{
			*flag = result;
			(*s_e)[0] = idx;
		}
		else if (*flag == 1)
			*(*s_e + 1) = idx;
	}
	else
	{
		if (*flag == 0)
		{
			*flag = result;
			*s_e[0] = idx;
		}
		else if (*flag == 2)
			*(*s_e + 1) = idx;
	}
}

int	get_logical_token(char *c, int idx)
{
	int	flag;

	flag = is_seq2(c);
	if (flag == 3)
	{
		append_list(ft_substr(c, idx, idx + 1));
		return (1);
	}
	if (flag == 4)
		append_list(ft_substr(c, idx, idx));
	return (0);
}

int	add_token(char *c, int *flag, int idx, int *init)
{
	int			res;
	static int	*s_e;

	if (!*init)
	{
		s_e = (int *)malloc(sizeof(int) * 2);
		*init = 1;
		s_e[0] = 0;
		s_e[1] = 0;
	}
	if (*c == ' ')
	{
		s_e[0] = idx + 1;
		return (0);
	}
	res = 0;
	if (is_seq(c))
	{
		if (!*flag && idx > s_e[0])
			append_list(ft_substr(c - idx, s_e[0], idx));
		get_open_close_idx(is_seq(c), flag, &s_e, idx);
	}
	else if (is_seq1(c))
	{
		if (!*flag && idx > s_e[0])
			append_list(ft_substr(c - idx, s_e[0], idx));
		get_open_close_idx(is_seq1(c), flag, &s_e, idx);
	}
	else if (is_seq2(c))
		return (get_logical_token(c, idx));
	else if (is_seq3(c))
		get_redirection_idx(c, idx, &s_e);
	if (*(c + 1) == '\0')
	{
		s_e[1] = idx;
		append_list(ft_substr(c - idx, s_e[0], s_e[1] - s_e[0] + 1));
		free(s_e);
		return (0);
	}
	if (s_e[0] < s_e[1])
	{
		append_list(ft_substr(c - idx, s_e[0], s_e[1] - s_e[0] + 1));
		res = s_e[1] - s_e[0];
		s_e[0] = s_e[1];
		if (*flag != 3)
		{
			*flag = 0;
			return (res);
		}
		*flag = 0;
		return (0);
	}
	return (res);
}

int	parsing(char *buf)
{
	int	idx;
	int	idx2;
	int	flag;
	int	init;

	flag = 0;
	idx = 0;
	init = 0;
	while (*buf)
	{
		idx2 = add_token(buf, &flag, idx, &init);
		buf++;
		idx++;
	}
	return (0);
}

int main(void)
{
	char	*str;
	t_list	*temp;

	str = ft_strdup("he\"llo\" world");
	// str = ft_strdup("hello world");
	parsing(str);
	temp = g_lst;
	while (temp)
	{
		printf("%s", (char *)temp->content);
		temp = temp->next;
		printf("\n");
	}
	free(str);
}
