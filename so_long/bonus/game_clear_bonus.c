/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clear_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:06:47 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 15:32:57 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	game_clear(t_playerb *player)
{
	ft_printf("Steps : %d\n", ++player->step);
	ft_printf("\nCongratuation! The game has been cleared.\n\n");
	exit(0);
}
