/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:44:13 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 15:45:53 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
}					t_bound;

typedef struct s_player
{
	int	success_flag;
	int	x;
	int	y;
	int	step;
}					t_player;

typedef struct s_map
{
	t_list		*map;
	const char	*filename;
	int			row;
	int			col;
	int			p_num;
	int			c_num;
	int			e_num;
	t_img		img_base;
	t_img		img_wall;
	t_img		img_col;
	t_img		img_play;
	t_img		img_esc;
}					t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
}					t_vars;

// struct init
void	inits(t_player *player, t_map *map, t_vars *vars);

// parsing
int		get_linelen(char *map_line);
void	get_map(t_map *map);
void	map_check(t_map *map);
void	get_player_position(t_map *map, t_player *player);

// game execution
int		game_close(t_vars *vars);
int		game_clear(t_player *player);
void	map_regen(t_map *map, t_player *pl, t_point p);
void	move_w(t_player *pl, t_bound b, t_map *map, t_vars *vars);
void	move_a(t_player *pl, t_bound b, t_map *map, t_vars *vars);
void	move_s(t_player *pl, t_bound b, t_map *map, t_vars *vars);
void	move_d(t_player *pl, t_bound b, t_map *map, t_vars *vars);
void	ft_mlx_img(t_map *map, t_player *player, t_vars *vars);
int		keypress(int keycode, t_vars *vars);

void	put_error(char *message);

#endif