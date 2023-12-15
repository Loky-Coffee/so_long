/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:46:59 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/15 17:28:17 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	test_texture(t_map *map, t_tx *tx, mlx_t *mlx, t_x *x)
{
	static long long int	timestamp;
	while (x->j < map->lines && x->i < map->linelength)
	{
		if (map->mapdata[x->j][x->i] == '1' || map->mapdata[x->j][x->i] == '0')
			s_img2win(mlx, tx->m_wall, x->x, x->y);
		if (map->mapdata[x->j][x->i] == '0')
			s_img2win(mlx, tx->m_field, x->x, x->y);
		if (map->mapdata[x->j][x->i] == 'C')
			s_img2win(mlx, tx->m_key, x->x, x->y);
		if (map->mapdata[x->j][x->i] == 'E')
			s_img2win(mlx, tx->m_door, x->x, x->y);
		if (map->mapdata[x->j][x->i] == 'P')
			s_img2win(mlx, tx->m_char, x->x, x->y);
		if (map->mapdata[x->j][x->i] == 'G')
			s_img2win(mlx, tx->m_enemy, x->x, x->y);
		printf("timestamp: %lld\n", timestamp);
		if(timestamp == 49 && map->mapdata[x->j][x->i] == 'G')
		{
			timestamp = 0;
			s_img2win(mlx, tx->m_enemy2, x->x, x->y);
		}
		timestamp++;
		if (x->i == (map->linelength - 1) || map->mapdata[x->j][x->i] == '\n')
		{
			x->x = 0;
			x->y += S_TEX;
			x->i = 0;
			x->j = x->j + 1;
		}
		else
		{
			x->i++;
			x->x += S_TEX;
		}
	}
}

void	loadfotos(t_map *map, t_tx *tx)
{
	tx->mlx = mlx_init((map->linelength - 1)
			* S_TEX, map->lines * S_TEX, "SO_LONG", false);
	if (!tx->mlx)
		exit (EXIT_FAILURE);
	tx->r_wall = mlx_load_png("./Texturen/wall.png");
	tx->r_field = mlx_load_png("./Texturen/field.png");
	tx->r_key = mlx_load_png("./Texturen/collectibel.png");
	tx->r_door = mlx_load_png("./Texturen/door_close.png");
	tx->r_doorw = mlx_load_png("./Texturen/door_with_char.png");
	tx->r_dooro = mlx_load_png("./Texturen/door_open.png");
	tx->r_char = mlx_load_png("./Texturen/charakter.png");
	tx->r_enemy = mlx_load_png("./Texturen/enemy.png");
	tx->r_enemy2 = mlx_load_png("./Texturen/enemy2.png");
}

int32_t	grafik(t_map *map, t_x *x, t_tx *tx)
{
	void	*params[2];

	loadfotos(map, tx);
	tx->m_wall = mlx_texture_to_image(tx->mlx, tx->r_wall);
	mlx_delete_texture(tx->r_wall);
	tx->m_field = mlx_texture_to_image(tx->mlx, tx->r_field);
	mlx_delete_texture(tx->r_field);
	tx->m_key = mlx_texture_to_image(tx->mlx, tx->r_key);
	mlx_delete_texture(tx->r_key);
	tx->m_char = mlx_texture_to_image(tx->mlx, tx->r_char);
	mlx_delete_texture(tx->r_char);
	tx->m_door = mlx_texture_to_image(tx->mlx, tx->r_door);
	mlx_delete_texture(tx->r_door);
	tx->m_doorw = mlx_texture_to_image(tx->mlx, tx->r_doorw);
	mlx_delete_texture(tx->r_doorw);
	tx->m_dooro = mlx_texture_to_image(tx->mlx, tx->r_dooro);
	mlx_delete_texture(tx->r_dooro);
	tx->m_enemy = mlx_texture_to_image(tx->mlx, tx->r_enemy);
	mlx_delete_texture(tx->r_enemy);
	tx->m_enemy2 = mlx_texture_to_image(tx->mlx, tx->r_enemy2);
	mlx_delete_texture(tx->r_enemy2);
	params[0] = (void *)map;
	params[1] = (void *)tx;
	mlx_key_hook(tx->mlx, my_key_hook, params);
	test_texture(map, tx, tx->mlx, x);
	mlx_loop(tx->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_x			x;
	t_tx		tx;

	tx = (t_tx){0};
	x = (t_x){0};
	map = (t_map){0};
	if (argc != 2)
		errormsg(INVALID_NUMBER_OF_ARGUMENTS);
	map.mapname = argv[1];
	openmap(&map);
	if (map.i_items == 0)
		errormsg(NEED_MINIMUM_1_COLLECTIBLE);
	doorlocation(&map);
	checkallones(&map);
	onechar_oneexit(&map);
	only_valid_symbols(&map);
	search_utils(&map);
	log_steps(0);
	grafik(&map, &x, &tx);
	end_game(&tx, &map);
	return (0);
}
