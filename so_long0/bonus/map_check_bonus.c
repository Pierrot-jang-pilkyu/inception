/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:56:47 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 15:50:38 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	wall_check(t_mapb *map)
{
	int		i;
	int		len;
	int		first;
	t_list	*temp;

	len = map->row;
	temp = map->map;
	first = 1;
	while (temp)
	{
		i = -1;
		while (++i < len)
		{
			if (i == 0 || i == len - 1 || first == 1 || temp->next == NULL)
				if (*((char *)temp->content + i) != '1')
					put_error("Wall Error.");
		}
		first = 0;
		temp = temp->next;
	}
}

void	char_check(t_mapb *map)
{
	int		i;
	char	c;
	t_list	*temp;

	temp = map->map;
	while (temp)
	{
		i = 0;
		while (*((char *)temp->content + i) != '\0')
		{
			c = *((char *)temp->content + i);
			if (!(c == '0' || c == '1' || c == 'C' || \
				c == 'E' || c == 'P' || c == 'V'))
				put_error("Impossible character in map.");
			i++;
		}
		temp = temp->next;
	}
}

void	least_check(t_mapb *map)
{
	int		i;
	char	c;
	t_list	*temp;

	temp = map->map;
	while (temp)
	{
		i = 0;
		while (*((char *)temp->content + i))
		{
			c = *((char *)temp->content + i);
			if (c == 'P')
				map->p_num++;
			else if (c == 'C')
				map->c_num++;
			else if (c == 'E')
				map->e_num++;
			i++;
		}
		temp = temp->next;
	}
	if (map->p_num == 0 || map->c_num == 0 || map->e_num == 0)
		put_error("Map must have at least one E, one C, and one P.");
}

void	rectangular_check(t_mapb *map)
{
	int		len;
	t_list	*temp;

	temp = map->map;
	len = get_linelen((char *)temp->content);
	while (temp)
	{
		if (len != get_linelen((char *)temp->content))
			put_error("The map must be rectangular.");
		temp = temp->next;
	}
}

void	map_check(t_mapb *map)
{
	rectangular_check(map);
	wall_check(map);
	char_check(map);
	least_check(map);
	if (map->p_num > 1)
		put_error("Player is only one.");
}
