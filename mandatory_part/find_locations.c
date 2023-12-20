/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_locations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:10:34 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/19 02:39:46 by aalatzas         ###   ########.fr       */
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
	if (map->i_items == 0)
		errormsg(NEED_MINIMUM_1_COLLECTIBLE);
	doorlocation(map);
	charlocation(map);
}

void	keylocation(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->chary || (y == map->chary && x <= map->charx))
	{
		if (map->mapdata[y][x] == 'C' || map->mapdata[y][x] == 'X')
			map->index++;
		x++;
		if (x == map->linelength)
		{
			x = 0;
			y++;
		}
	}
}
