/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:58:59 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/19 05:04:07 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_sprites(t_map *map, t_tx *tx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = (S_TEX / 2) - ((S_TEX / 2) / 2);
	mlx_resize_image (tx->m_char, S_TEX, S_TEX);
	mlx_image_to_window (tx->mlx, tx->m_char,
		map->charx * S_TEX, map->chary * S_TEX);
	while (y < map->lines && x < map->linelength)
	{
		if (map->mapdata[y][x] == 'C')
		{
			mlx_resize_image (tx->m_key, S_TEX / 2, S_TEX / 2);
			mlx_image_to_window (tx->mlx, tx->m_key,
				x * S_TEX + i, y * S_TEX + i);
		}
		if (x == (map->linelength - 1) || map->mapdata[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
}

static void	my_img_to_window(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	mlx_resize_image(img, S_TEX, S_TEX);
	mlx_image_to_window(mlx, img, x * S_TEX, y * S_TEX);
}

static void	load_map(t_map *map, t_tx *tx, mlx_t *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->lines)
	{
		if (map->mapdata[y][x] == '1' || map->mapdata[y][x] == '0')
			my_img_to_window(mlx, tx->m_wall, x, y);
		if (map->mapdata[y][x] == '0' || map->mapdata[y][x] == 'P'
		|| map->mapdata[y][x] == 'C')
			my_img_to_window(mlx, tx->m_field, x, y);
		if (map->mapdata[y][x] == 'E')
			my_img_to_window(mlx, tx->m_door, x, y);
		if (x == (map->linelength - 1) || map->mapdata[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
	load_sprites(map, tx);
}

static void	load_texture(t_map *map, t_tx *tx)
{
	tx->mlx = mlx_init((map->linelength - 1)
			* S_TEX, map->lines * S_TEX, "SO_LONG", false);
	if (!tx->mlx)
		exit (EXIT_FAILURE);
	tx->r_wall = mlx_load_png("./mandatory_part/Texturen/wall.png");
	tx->r_field = mlx_load_png("./mandatory_part/Texturen/field.png");
	tx->r_key = mlx_load_png("./mandatory_part/Texturen/gems.png");
	tx->r_door = mlx_load_png("./mandatory_part/Texturen/door.png");
	tx->r_char = mlx_load_png("./mandatory_part/Texturen/player.png");
}

int32_t	grafik_main(t_map *map, t_tx *tx)
{
	void	*params[2];

	load_texture(map, tx);
	tx->m_wall = mlx_texture_to_image(tx->mlx, tx->r_wall);
	mlx_delete_texture(tx->r_wall);
	tx->m_field = mlx_texture_to_image(tx->mlx, tx->r_field);
	mlx_delete_texture(tx->r_field);
	tx->m_key = mlx_texture_to_image(tx->mlx, tx->r_key);
	mlx_delete_texture(tx->r_key);
	tx->m_door = mlx_texture_to_image(tx->mlx, tx->r_door);
	mlx_delete_texture(tx->r_door);
	tx->m_char = mlx_texture_to_image(tx->mlx, tx->r_char);
	mlx_delete_texture(tx->r_char);
	params[0] = (void *)map;
	params[1] = (void *)tx;
	load_map(map, tx, tx->mlx);
	mlx_key_hook(tx->mlx, my_key_hook, params);
	mlx_loop(tx->mlx);
	return (EXIT_SUCCESS);
}
