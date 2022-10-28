/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:46:30 by pjang             #+#    #+#             */
/*   Updated: 2022/09/23 02:35:13 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	while (temp != 0)
	{
		next = temp->next;
		del(temp->content);
		free(temp);
		temp = next;
	}
	*lst = 0;
}
