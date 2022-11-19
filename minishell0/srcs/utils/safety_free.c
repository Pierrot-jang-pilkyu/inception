/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:41:39 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 04:07:02 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_prs(t_prs *prs)
{
	safety_free(prs->priority);
	ft_lstclear(&prs->quote, &safety_free);
	ft_lstclear(&prs->pts, &safety_free);
	ft_lstclear(&prs->logical, &safety_free);
	ft_lstclear(&prs->pipe, &safety_free);
	ft_lstclear(&prs->redirect, &safety_free);
}

void	safety_free(void *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	safety_dimention_free(char **strs)
{
	char	**temp;

	if (strs)
	{
		temp = strs;
		while (*strs != NULL)
		{
			if (*strs)
				free(*strs);
			*strs++ = NULL;
		}
		strs = temp;
		free(strs);
		strs = NULL;
	}
}
