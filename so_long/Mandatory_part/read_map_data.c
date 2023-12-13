/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:59:03 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/12 11:58:00 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charlocation(t_map *map)
{
	while (map->chary < map->lines)
	{
		if (map->mapdata[map->chary][map->charx] == 'P')
			break ;
		if (map->charx == map->linelength - 1)
		{
			map->chary++;
			map->charx = 0;
		}
		map->charx++;
	}
}

void	doorlocation(t_map *map)
{
	while (map->doory < map->lines)
	{
		if (map->mapdata[map->doory][map->doorx] == 'E')
			break ;
		if (map->doorx == map->linelength - 1)
		{
			map->doory++;
			map->doorx = 0;
		}
		map->doorx++;
	}
}

void	count_collectibles(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->i_items = 0;
	while (y < map->lines)
	{
		if (map->mapdata[y][x] == 'C')
			map->i_items++;
		if (x == map->linelength - 1)
		{
			y++;
			x = 0;
		}
		x++;
	}
}

void	readmap(int fd, size_t cl, t_map *map)
{
	char	*temp;

	temp = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		if ((cl != ft_strlen(*ft_split(temp, '\n'))) && cl != 0)
			errormsg(MAP_IS_NOT_RECTANGULAR);
		cl = ft_strlen(*ft_split(temp, '\n'));
		if (ft_strlen(temp) < 2)
			errormsg(EMPTY_LINES_FOUND_IN_MAP);
		if (temp > 0)
		{
			if (map->linelength == 0)
				map->linelength = ft_strlen(temp);
		}
		map->romap = ft_strjoin(map->romap, temp);
		map->lines++;
		free(temp);
	}
	close (fd);
	map->mapdata = ft_split(map->romap, '\n');
	map->map_check_win = ft_split(map->romap, '\n');
}

void	openmap(t_map *map)
{
	char	*file_extension;
	int		fd;
	size_t	checklenght;

	checklenght = 0;
	fd = 0;
	file_extension = ft_strrchr(map->mapname, '.');
	if (file_extension == NULL || ft_strncmp(file_extension, ".ber", 42) != 0)
		errormsg(MAP_END_DOT_BER);
	if (map->mapname)
	{
		fd = open(map->mapname, O_RDONLY);
		if (fd == -1)
			errormsg(ERROR_OPEN_MAP);
	}
	readmap(fd, checklenght, map);
	charlocation(map);
	count_collectibles(map);
}
