/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_fail_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:06:47 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 17:28:36 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	game_fail(t_playerb *player)
{
	ft_printf("Steps : %d\n", ++player->step);
	ft_printf("\nYou died.\n\n");
	exit(0);
}
