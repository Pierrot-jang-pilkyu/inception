/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:44:04 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 15:32:57 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// void	print_map(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (map[++i] != NULL)
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			ft_printf("%c", map[i][j]);
// 			if (j % 16 == 15)
// 				ft_printf(" ");
// 		}
// 		ft_printf("\n");
// 		if (i % 16 == 15)
// 			ft_printf("\n");
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char *argv[])
{
	char		*title;
	t_mapb		map;
	t_playerb	player;
	t_varsb		vars;

	if (argc == 2)
	{
		inits(&player, &map, &vars);
		map.filename = argv[1];
		get_map(&map);
		get_b_map(&map, &player);
		get_player_position(&map, &player);
		title = "ANGEL IN THE HEAVEN";
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, map.row * 64, map.col * 64, title);
		ft_mlx_img(&map, &player, &vars);
		mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, &keypress, &vars);
		mlx_hook(vars.win, X_EVENT_DESTROY_NOTIFY, 0, &game_close, &vars);
		putstr_to_window(&vars, &player);
		mlx_loop(vars.mlx);
	}
	else
		put_error("Only One argument is required.");
	system("leaks so_long");
	return (0);
}
