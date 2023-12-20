/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:46:59 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/20 14:22:00 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	end_game(t_map *map, int fd)
{
	if (fd == YOU_LOSE)
		message(fd);
	else if ((map->mapdata[map->chary][map->charx] == 'E'
		&& map->collected == map->i_items) || fd == YOU_WIN)
		message(fd);
	else if (fd == GAME_STOPED)
		message(fd);
	free_split(map->mapdata);
	free_split(map->map_check_win);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_tx		tx;

	tx = (t_tx){0};
	map = (t_map){0};
	if (argc != 2)
		errormsg(INVALID_NUMBER_OF_ARGUMENTS);
	map.mapname = argv[1];
	openmap(&map);
	count_collectibles(&map);
	search_utils(&map);
	map.collected = 0;
	ft_putstr_fd(MAGENTA "+--------------------------------+\n" RESET, 1);
	ft_putstr_fd(MAGENTA "| The game has started.Have fun! |\n" RESET, 1);
	ft_putstr_fd(MAGENTA "+--------------------------------+\n" RESET, 1);
	print_steps(0);
	grafik_main(&map, &tx);
	end_game(&map, GAME_STOPED);
	mlx_terminate(tx.mlx);
	return (0);
}
	// system("leaks so_long");
