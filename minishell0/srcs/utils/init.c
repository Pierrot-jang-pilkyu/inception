/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:49:27 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 14:36:27 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_mini	g_mini;

void	init_mini(void)
{
	g_mini.env = NULL;
	g_mini.tkn = NULL;
	g_mini.tree = NULL;
	g_mini.contents = NULL;
}

void	init_tkn(t_list *temp)
{
	int		i;
	int		len;

	len = ft_lstsize(temp);
	g_mini.tkn = (t_tkn *)malloc(sizeof(t_tkn) * (len + 1));
	if (!g_mini.tkn)
		put_error(strerror(errno));
	i = 0;
	while (i < len)
	{
		g_mini.tkn[i].idx = 0;
		g_mini.tkn[i].value = NULL;
		i++;
	}
	g_mini.tkn[len].idx = -1;
	g_mini.tkn[len].value = NULL;
}

void	init_prs(t_prs *prs)
{
	prs->priority = NULL;
	prs->quote = NULL;
	prs->pts = NULL;
	prs->logical = NULL;
	prs->pipe = NULL;
	prs->redirect = NULL;
}
