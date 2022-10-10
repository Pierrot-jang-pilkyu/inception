/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:05:23 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 18:20:02 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	putstr_to_window(t_varsb *vars, t_playerb *pl)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(pl->step);
	str = ft_strjoin("Steps : ", temp);
	mlx_string_put(vars->mlx, vars->win, 32, 32, BLUE, str);
	free(str);
	str = NULL;
	free(temp);
	temp = NULL;
}

void	move_w(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if ((b.w == 'E' || b.wb == 'E') && pl->success_flag)
		game_clear(pl);
	else if (b.w == 'V' || b.wb == 'V')
		game_fail(pl);
	else if (b.w == 'C' || b.wb == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	else if (b.w == '1' || b.wb == '1')
		return ;
	if (b.w == '0' || b.w == 'C' || b.wb == '0' || b.wb == 'C')
	{
		y_regen(pl, &tmp_p, -1);
		map_regen(map, pl, tmp_p);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}

void	move_a(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if ((b.a == 'E' || b.ab == 'E') && pl->success_flag)
		game_clear(pl);
	else if (b.a == 'V' || b.ab == 'V')
		game_fail(pl);
	else if (b.a == 'C' || b.ab == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	else if (b.a == '1' || b.ab == '1')
		return ;
	if (b.a == '0' || b.a == 'C' || b.ab == '0' || b.ab == 'C')
	{
		x_regen(pl, &tmp_p, -1);
		map_regen(map, pl, tmp_p);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}

void	move_s(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if ((b.s == 'E' || b.sb == 'E') && pl->success_flag)
		game_clear(pl);
	else if (b.s == 'V' || b.sb == 'V')
		game_fail(pl);
	else if (b.s == 'C' || b.sb == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	else if (b.s == '1' || b.sb == '1')
		return ;
	if (b.s == '0' || b.s == 'C' || b.sb == '0' || b.sb == 'C')
	{
		y_regen(pl, &tmp_p, 1);
		map_regen(map, pl, tmp_p);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}

void	move_d(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if ((b.d == 'E' || b.db == 'E') && pl->success_flag)
		game_clear(pl);
	else if (b.d == 'V' || b.db == 'V')
		game_fail(pl);
	else if (b.d == 'C' || b.db == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	else if (b.d == '1' || b.db == '1')
		return ;
	if (b.d == '0' || b.d == 'C' || b.db == '0' || b.db == 'C')
	{
		x_regen(pl, &tmp_p, 1);
		map_regen(map, pl, tmp_p);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}
