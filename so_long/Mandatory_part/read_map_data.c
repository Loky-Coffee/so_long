/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:59:03 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/14 00:55:13 by aalatzas         ###   ########.fr       */
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

void	readmap(int fd, t_map *map, char *temp, char *temp2)
{
	char	*new_temp2;

	new_temp2 = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		if (temp[0] != '\0')
		{
			new_temp2 = ft_strjoin(temp2, temp);
			free(temp2);
			temp2 = new_temp2;
			if (map->linelength == 0)
				map->linelength = ft_strlen(temp);
		}
		map->lines++;
		free (temp);
	}
	close(fd);
	map->romap = temp2;
	map->mapdata = ft_split(map->romap, '\n');
	map->map_check_win = ft_split(map->romap, '\n');
}

void	openmap(t_map *map)
{
	char	*file_extension;
	int		fd;
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
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
	readmap(fd, map, temp, temp2);
	charlocation(map);
	count_collectibles(map);
}
