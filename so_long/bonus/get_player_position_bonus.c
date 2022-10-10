/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:54:08 by pjang             #+#    #+#             */
/*   Updated: 2022/10/07 05:10:21 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	save_point(t_mapb *map, t_playerb *player)
{
	player->pixel_x = player->x * 16;
	player->pixel_y = player->y * 16;
	map->pl_x = player->x;
	map->pl_y = player->y;
}

void	get_player_position(t_mapb *map, t_playerb *player)
{
	int		i;
	int		j;
	char	c;
	t_list	*temp;

	temp = map->map;
	i = 0;
	while (temp)
	{
		j = 0;
		while (*((char *)temp->content + j))
		{
			c = *((char *)temp->content + j);
			if (c == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		temp = temp->next;
		i++;
	}
	save_point(map, player);
}
