/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:05:18 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/12 04:04:55 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	only_valid_symbols(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->lines)
	{
		x = 0;
		while (x < map->linelength)
		{
			if ((map->mapdata[y][x] != 'P') && (map->mapdata[y][x] != 'C') \
			&& (map->mapdata[y][x] != '1') && (map->mapdata[y][x] != '0') \
			&& (map->mapdata[y][x] != 'E') && (map->mapdata[y][x] != '\n') \
			&& (map->mapdata[y][x] != '\0'))
				errormsg(INVALID_LETHER_FOUND_IN_MAP);
			x++;
		}
		y++;
	}
	return (0);
}

void	onechar_oneexit(t_map *map)
{
	int	charackter;
	int	door;
	int	x;
	int	y;

	charackter = 0;
	door = 0;
	x = 0;
	y = 0;
	while (y < map->lines && x < map->linelength)
	{
		if (map->mapdata[y][x] == 'P')
			charackter++;
		else if (map->mapdata[y][x] == 'E')
			door++;
		if (charackter > 1 || door > 1)
			errormsg(ONE_CHARECTER_ONE_EXIT);
		if (x == (map->linelength - 1))
		{
			y++;
			x = 0;
		}
		x++;
	}
}

void	search(int x, int y, t_map *map, t_search *s)
{
	if (s->possible || x <= 0 || x >= map->linelength - 1 || y <= 0 \
	|| y >= map->lines - 1)
		return ;
	if (map->mapdata[y][x] == '1' || map->map_check_win[y][x] == 'V')
		return ;
	if (map->mapdata[y][x] == 'C')
		s->collected++;
	else if (map->mapdata[y][x] == 'E')
	{
		s->tur = 1;
		if (s->collected == map->i_items)
		{
			s->possible = true;
			return ;
		}
	}
	map->map_check_win[y][x] = 'V';
	if (map->mapdata[y][x + 1] != '1')
		search(x + 1, y, map, s);
	if (map->mapdata[y][x - 1] != '1')
		search(x - 1, y, map, s);
	if (map->mapdata[y + 1][x] != '1')
		search(x, y + 1, map, s);
	if (map->mapdata[y - 1][x] != '1')
		search(x, y - 1, map, s);
}

void	search_utils(t_map *map)
{
	t_search	s;

	s.possible = false;
	s.collected = 0;
	s.tur = 0;
	search(map->charx, map->chary, map, &s);
	if (s.collected != map->i_items || s.tur == 0)
		errormsg(WIN_NOT_POSSIBLE);
}

void	checkallones(t_map *map)
{
	int	x;
	int	y;

	y = map->lines - 1;
	x = map->linelength - 2;
	while (x >= 0)
	{
		if (map->mapdata[0][x] != '1' || map->mapdata[y][x] != '1')
			errormsg(MAP_IST_NOT_CLOSED_BEI_1);
		x--;
	}
	y = map->lines - 1;
	x = map->linelength - 2;
	while (y >= 0)
	{
		if (map->mapdata[y][0] != '1' || map->mapdata[y][x] != '1')
			errormsg(MAP_IST_NOT_CLOSED_BEI_1);
		y--;
	}
	if (map->linelength > 51 || map->lines > 26)
		errormsg(MAP_RESOLUTION_TOO_BIG);
}
