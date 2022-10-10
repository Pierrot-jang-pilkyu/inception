/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_linelen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 04:14:32 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 12:25:17 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	get_linelen(char *map_line)
{
	int	len;

	len = 0;
	while (map_line[len] != '\n' && map_line[len])
		len++;
	return (len);
}
