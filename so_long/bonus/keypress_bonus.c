/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:44:06 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 18:42:54 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_map_char(t_playerb *pl, t_mapb *map, t_point p, t_bound *b)
{
	p.y = 0;
	while (p.y < map->col * 16)
	{
		p.x = -1;
		while (++p.x < map->row * 16)
		{
			if ((p.y == pl->pixel_y - 1) && (p.x == pl->pixel_x))
				b->w = map->b_map[pl->pixel_y - 1][pl->pixel_x];
			else if ((p.y == pl->pixel_y - 1) && (p.x == pl->pixel_x + 15))
				b->wb = map->b_map[pl->pixel_y - 1][pl->pixel_x + 15];
			else if ((p.y == pl->pixel_y) && (p.x == pl->pixel_x - 1))
				b->a = map->b_map[pl->pixel_y][pl->pixel_x - 1];
			else if ((p.y == pl->pixel_y + 15) && (p.x == pl->pixel_x - 1))
				b->ab = map->b_map[pl->pixel_y + 15][pl->pixel_x - 1];
			else if ((p.y == pl->pixel_y + 16) && (p.x == pl->pixel_x))
				b->s = map->b_map[pl->pixel_y + 16][pl->pixel_x];
			else if ((p.y == pl->pixel_y + 16) && (p.x == pl->pixel_x + 15))
				b->sb = map->b_map[pl->pixel_y + 16][pl->pixel_x + 15];
			else if ((p.y == pl->pixel_y) && (p.x == pl->pixel_x + 16))
				b->d = map->b_map[pl->pixel_y][pl->pixel_x +16];
			else if ((p.y == pl->pixel_y + 15) && (p.x == pl->pixel_x + 16))
				b->db = map->b_map[pl->pixel_y + 15][pl->pixel_x +16];
		}
		p.y++;
	}
}

void	init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->map_c = '\0';
}

int	keypress(int keycode, t_varsb *vars)
{
	t_bound	bound;
	t_point	tmp_p;

	init_point(&tmp_p);
	vars->player->move_flag = 1;
	get_map_char(vars->player, vars->map, tmp_p, &bound);
	if (keycode == KEY_W)
		move_w(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_A)
		move_a(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_S)
		move_s(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_D)
		move_d(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_ESC)
		game_close(vars);
	return (0);
}
