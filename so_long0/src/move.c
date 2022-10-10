/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:05:23 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 15:25:36 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_w(t_player *pl, t_bound b, t_map *map, t_vars *vars)
{
	t_point	tmp_p;

	if (b.w == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.w == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.w == '0' || b.w == 'C')
	{
		tmp_p.x = pl->x;
		tmp_p.y = pl->y;
		pl->y--;
		map_regen(map, pl, tmp_p);
		ft_printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
	}
}

void	move_a(t_player *pl, t_bound b, t_map *map, t_vars *vars)
{
	t_point	tmp_p;

	if (b.a == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.a == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.a == '0' || b.a == 'C')
	{
		tmp_p.x = pl->x;
		tmp_p.y = pl->y;
		pl->x--;
		map_regen(map, pl, tmp_p);
		ft_printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
	}
}

void	move_s(t_player *pl, t_bound b, t_map *map, t_vars *vars)
{
	t_point	tmp_p;

	if (b.s == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.s == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.s == '0' || b.s == 'C')
	{
		tmp_p.x = pl->x;
		tmp_p.y = pl->y;
		pl->y++;
		map_regen(map, pl, tmp_p);
		ft_printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
	}
}

void	move_d(t_player *pl, t_bound b, t_map *map, t_vars *vars)
{
	t_point	tmp_p;

	if (b.d == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.d == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.d == '0' || b.d == 'C')
	{
		tmp_p.x = pl->x;
		tmp_p.y = pl->y;
		pl->x++;
		map_regen(map, pl, tmp_p);
		ft_printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
	}
}
