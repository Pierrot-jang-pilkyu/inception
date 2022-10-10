/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:57:08 by pjang             #+#    #+#             */
/*   Updated: 2022/10/10 18:59:26 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	set_b_map(t_mapb *map, t_playerb *pl, t_point p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 16)
	{
		j = -1;
		while (++j < 16)
		{
			if (p.map_c == 'P')
				map->b_map[(p.y * 16) + i][(p.x * 16) + j] = '0';
			else if (pl->move_flag)
				map->b_map[pl->pixel_y + i][pl->pixel_x + j] = 'P';
			else
				map->b_map[(p.y * 16) + i][(p.x * 16) + j] = p.map_c;
		}
	}
	i = -1;
	if (!pl->move_flag)
	{
		while (++i < map->col)
			map->b_map[(p.y * 16) + i][(map->row * 16)] = '\0';
	}
}

void	get_b_map(t_mapb *map, t_playerb *pl)
{
	int		i;
	t_point	p;
	t_list	*temp;

	map->b_map = (char **)malloc(sizeof(char *) * ((map->col * 16) + 1));
	i = -1;
	while (++i < map->col * 16)
		map->b_map[i] = (char *)malloc(sizeof(char) * ((map->row * 16) + 1));
	temp = map->map;
	p.y = -1;
	while (++p.y < map->col)
	{
		p.x = -1;
		while (++p.x < map->row)
		{
			p.map_c = *((char *)temp->content + p.x);
			set_b_map(map, pl, p);
		}
		temp = temp->next;
	}
	map->b_map[map->col * 16] = NULL;
}

void	file_check(const char *filename)
{
	int		len;
	char	*temp;

	len = ft_strlen(filename);
	temp = ft_substr(filename, len - 4, 4);
	if (ft_strncmp((const char *)temp, ".ber", 4) != 0)
		put_error("The file extension is incorrect.");
	free(temp);
}

void	del_newline(t_mapb *map)
{
	int		len;
	t_list	*temp;
	char	*str;

	temp = map->map;
	str = (char *)temp->content;
	while (temp)
	{
		len = get_linelen((char *)temp->content);
		*((char *)temp->content + len) = '\0';
		temp = temp->next;
		map->col++;
	}
}

void	get_map(t_mapb *map)
{
	int		fd;
	int		i;
	char	*temp;

	i = -1;
	file_check(map->filename);
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		put_error("fd(-1) : File open failure.");
	temp = get_next_line(fd);
	if (!temp)
		put_error("Empty file.");
	ft_lstadd_back(&map->map, ft_lstnew((void *)temp));
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		ft_lstadd_back(&map->map, ft_lstnew((void *)temp));
	}
	map->row = get_linelen((char *)map->map->content);
	del_newline(map);
	map_check(map);
	close(fd);
}
