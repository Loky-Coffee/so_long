/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texure_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:58:59 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/20 11:31:09 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_enemies(t_map *map, t_tx *tx)
{
	map->load_y = 0;
	while (map->load_y < map->lines)
	{
		map->load_x = 0;
		while (map->load_x < map->linelength - 1)
		{
			if (map->mapdata[map->load_y][map->load_x] == 'G')
			{
				map->load_fx = (map->load_x * S_TEX) - (S_TEX / 10);
				map->load_fy = (map->load_y * S_TEX) - (S_TEX / 10);
				mlx_resize_image (tx->m_enemy1, S_TEX
					+ (S_TEX / 4), S_TEX + (S_TEX / 4));
				mlx_image_to_window (tx->mlx, tx->m_enemy1,
					map->load_fx, map->load_fy);
				mlx_resize_image (tx->m_enemy2, S_TEX
					+ (S_TEX / 4), S_TEX + (S_TEX / 4));
				mlx_image_to_window (tx->mlx, tx->m_enemy2,
					map->load_fx, map->load_fy);
			}
			map->load_x++;
		}
		map->load_y++;
	}
	mlx_resize_image (tx->m_black, S_TEX * map->linelength, S_TEX);
	mlx_image_to_window(tx->mlx, tx->m_black, 0, map->lines * S_TEX);
}

static void	load_player_and_keys(t_map *map, t_tx *tx)
{
	int	x;
	int	y;

	y = 0;
	mlx_resize_image (tx->m_player1, S_TEX, S_TEX);
	mlx_image_to_window (tx->mlx, tx->m_player1,
		map->charx * S_TEX, map->chary * S_TEX);
	mlx_resize_image (tx->m_player2, S_TEX, S_TEX);
	mlx_image_to_window (tx->mlx, tx->m_player2,
		map->charx * S_TEX, map->chary * S_TEX);
	while (y < map->lines)
	{
		x = 0;
		while (x < map->linelength - 1)
		{
			if (map->mapdata[y][x] == 'C')
			{
				mlx_resize_image (tx->m_key, S_TEX / 2, S_TEX / 2);
				mlx_image_to_window (tx->mlx, tx->m_key,
					x * S_TEX + S_TEX / 4, y * S_TEX + S_TEX / 4);
			}
			x++;
		}
		y++;
	}
}

static void	load_map(t_map *map, t_tx *tx, mlx_t *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->lines)
	{
		my_img_to_window(mlx, tx->m_field, x, y);
		if (map->mapdata[y][x] == '1')
			my_img_to_window(mlx, tx->m_wall, x, y);
		if (map->mapdata[y][x] == 'E')
		{
			my_img_to_window(mlx, tx->m_dooro1, x, y);
			my_img_to_window(mlx, tx->m_dooro2, x, y);
			my_img_to_window(mlx, tx->m_doorc, x, y);
		}
		if (x == (map->linelength - 1) || map->mapdata[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
}

static void	load_texture(t_map *map, t_tx *tx)
{
	tx->mlx = mlx_init((map->linelength - 1)
			* S_TEX, (map->lines * S_TEX) + 25, "SO_LONG", false);
	if (!tx->mlx)
		exit (EXIT_FAILURE);
	tx->r_wall = mlx_load_png("./bonus/Texturen/wall.png");
	tx->r_field = mlx_load_png("./bonus/Texturen/field.png");
	tx->r_key = mlx_load_png("./bonus/texturen/coin1.png");
	tx->r_doorc = mlx_load_png("./bonus/texturen/door_close.png");
	tx->r_dooro1 = mlx_load_png("./bonus/texturen/door_open1.png");
	tx->r_dooro2 = mlx_load_png("./bonus/texturen/door_open2.png");
	tx->r_player1 = mlx_load_png("./bonus/texturen/player1.png");
	tx->r_player2 = mlx_load_png("./bonus/texturen/player2.png");
	tx->r_enemy1 = mlx_load_png("./bonus/texturen/enemy1.png");
	tx->r_enemy2 = mlx_load_png("./bonus/texturen/enemy2.png");
	tx->r_black = mlx_load_png("./bonus/texturen/black.png");
	mlx_focus(tx->mlx);
}

int32_t	grafik_main(t_map *map, t_tx *tx)
{
	void	*params[2];
	int		i;

	i = 0;
	load_texture(map, tx);
	tx->m_wall = mlx_texture_to_image(tx->mlx, tx->r_wall);
	tx->m_field = mlx_texture_to_image(tx->mlx, tx->r_field);
	tx->m_key = mlx_texture_to_image(tx->mlx, tx->r_key);
	tx->m_doorc = mlx_texture_to_image(tx->mlx, tx->r_doorc);
	tx->m_dooro1 = mlx_texture_to_image(tx->mlx, tx->r_dooro1);
	tx->m_dooro2 = mlx_texture_to_image(tx->mlx, tx->r_dooro2);
	tx->m_player1 = mlx_texture_to_image(tx->mlx, tx->r_player1);
	tx->m_player2 = mlx_texture_to_image(tx->mlx, tx->r_player2);
	tx->m_enemy1 = mlx_texture_to_image(tx->mlx, tx->r_enemy1);
	tx->m_enemy2 = mlx_texture_to_image(tx->mlx, tx->r_enemy2);
	tx->m_black = mlx_texture_to_image(tx->mlx, tx->r_black);
	params[0] = (void *)map;
	params[1] = (void *)tx;
	load_map(map, tx, tx->mlx);
	load_player_and_keys(map, tx);
	load_enemies(map, tx);
	mlx_key_hook(tx->mlx, my_key_hook, params);
	mlx_loop_hook(tx->mlx, animation_main, params);
	mlx_loop(tx->mlx);
	return (EXIT_SUCCESS);
}
