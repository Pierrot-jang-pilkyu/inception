/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:44:13 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 17:51:48 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY_NOTIFY 17
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define RED (0xFF0000)
# define GREEN (0x00FF00)
# define BLUE (0x0000FF)

typedef struct s_point
{
	int		x;
	int		y;
	char	map_c;
}					t_point;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}					t_img;

typedef struct s_bound
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	wb;
	char	ab;
	char	sb;
	char	db;
}					t_bound;

typedef struct s_playerb
{
	int	success_flag;
	int	move_flag;
	int	x;
	int	y;
	int	pixel_x;
	int	pixel_y;
	int	step;
	int	px_step;
	int	py_step;
}					t_playerb;

typedef struct s_mapb
{
	t_list		*map;
	char		**b_map;
	const char	*filename;
	int			row;
	int			col;
	int			pl_x;
	int			pl_y;
	int			p_num;
	int			c_num;
	int			e_num;
	t_img		img_base;
	t_img		img_wall;
	t_img		img_col;
	t_img		img_play;
	t_img		img_esc;
	t_img		img_vil;
}					t_mapb;

typedef struct s_varsb
{
	void		*mlx;
	void		*win;
	t_mapb		*map;
	t_playerb	*player;
}					t_varsb;

// struct init
void	inits(t_playerb *player, t_mapb *map, t_varsb *vars);

// parsing
int		get_linelen(char *map_line);
void	get_map(t_mapb *map);
void	map_check(t_mapb *map);
void	get_b_map(t_mapb *map, t_playerb *player);
void	set_b_map(t_mapb *map, t_playerb *player, t_point p);
void	get_player_position(t_mapb *map, t_playerb *player);

// game execution
int		game_clear(t_playerb *player);
int		game_fail(t_playerb *player);
int		game_close(t_varsb *vars);
void	map_regen(t_mapb *map, t_playerb *pl, t_point p);
void	putstr_to_window(t_varsb *vars, t_playerb *pl);
void	x_regen(t_playerb *pl, t_point *point, int sign);
void	y_regen(t_playerb *pl, t_point *point, int sign);
void	move_w(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars);
void	move_a(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars);
void	move_s(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars);
void	move_d(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars);
void	ft_mlx_img(t_mapb *map, t_playerb *player, t_varsb *vars);
int		keypress(int keycode, t_varsb *vars);

void	put_error(char *message);

#endif