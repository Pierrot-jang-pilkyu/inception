/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_regen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:33:06 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 18:28:38 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	x_regen(t_playerb *pl, t_point *point, int sign)
{
	if (sign > 0)
	{
		pl->pixel_x++;
		pl->px_step++;
	}
	else if (sign < 0)
	{
		pl->pixel_x--;
		pl->px_step--;
	}
	if (pl->px_step == -16 || pl->px_step == 16)
	{
		ft_printf("Steps : %d\n", ++pl->step);
		pl->x = pl->pixel_x / 16;
		pl->px_step = 0;
	}
	point->x = pl->x;
	point->y = pl->y;
}

void	y_regen(t_playerb *pl, t_point *point, int sign)
{
	if (sign > 0)
	{
		pl->pixel_y++;
		pl->py_step++;
	}
	else if (sign < 0)
	{
		pl->pixel_y--;
		pl->py_step--;
	}
	if (pl->py_step == -16 || pl->py_step == 16)
	{
		ft_printf("Steps : %d\n", ++pl->step);
		pl->y = pl->pixel_y / 16;
		pl->py_step = 0;
	}
	point->x = pl->x;
	point->y = pl->y;
}

void	map_regen(t_mapb *map, t_playerb *pl, t_point p)
{
	char	c;
	t_point	tmp_p;
	t_list	*temp;

	temp = map->map;
	tmp_p.y = -1;
	while (++tmp_p.y < map->col)
	{
		tmp_p.x = -1;
		while (++tmp_p.x < map->row)
		{
			c = *((char *)temp->content + tmp_p.x);
			if (tmp_p.x == pl->x && tmp_p.y == pl->y && c == 'P')
				*((char *)temp->content + tmp_p.x) = '0';
			if (tmp_p.x == p.x && tmp_p.y == p.y && c == 'C')
				*((char *)temp->content + tmp_p.x) = '0';
		}
		temp = temp->next;
	}
}
