/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 06:34:24 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/20 08:34:13 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_img_to_window(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	mlx_resize_image(img, S_TEX, S_TEX);
	mlx_image_to_window(mlx, img, x * S_TEX, y * S_TEX);
}

static void	count_steep(t_map *map, t_tx *tx)
{
	map->steps++;
	print_steps(map->steps);
	put_steeps_to_screen(map, tx);
}

static void	move_player2(t_map *map, t_tx *tx, mlx_key_data_t key_data)
{
	if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
		&& map->mapdata[map->chary][map->charx + 1] != '1')
	{
		map->charx++;
		tx->m_player1->instances->x += S_TEX;
		tx->m_player2->instances->x += S_TEX;
	}
	else if (key_data.key == MLX_KEY_ESCAPE)
		end_game (map, GAME_STOPED);
	if (map->mapdata[map->chary][map->charx] == 'C')
	{
		map->collected++;
		map->mapdata[map->chary][map->charx] = 'X';
		keylocation(map);
		tx->m_key->instances[map->index - 1].enabled = false;
		map->index = 0;
	}
	else if ((map->mapdata[map->chary][map->charx] == 'E'
		&& map->collected == map->i_items))
		end_game(map, YOU_WIN);
	else if (map->mapdata[map->chary][map->charx] == 'G')
		end_game(map, YOU_LOSE);
}

static void	move_player(t_map *map, t_tx *tx, mlx_key_data_t key_data)
{
	if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
		&& map->mapdata[map->chary - 1][map->charx] != '1')
	{
		map->chary--;
		tx->m_player1->instances->y -= S_TEX;
		tx->m_player2->instances->y -= S_TEX;
	}
	else if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
		&& map->mapdata[map->chary + 1][map->charx] != '1')
	{
		map->chary++;
		tx->m_player1->instances->y += S_TEX;
		tx->m_player2->instances->y += S_TEX;
	}
	else if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
		&& map->mapdata[map->chary][map->charx -1] != '1')
	{
		map->charx--;
		tx->m_player1->instances->x -= S_TEX;
		tx->m_player2->instances->x -= S_TEX;
	}
	move_player2(map, tx, key_data);
}

void	my_key_hook(mlx_key_data_t key_data, void *param)
{
	t_map	*map;
	t_tx	*tx;
	void	**params;
	bool	valid_key;

	params = (void **) param;
	map = (t_map *)params[0];
	tx = (t_tx *)params[1];
	if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP
		|| key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN
		|| key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT
		|| key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT
		|| key_data.key == MLX_KEY_ESCAPE)
		valid_key = 1;
	if ((key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
		&& valid_key)
	{
		move_player(map, tx, key_data);
		count_steep(map, tx);
		if ((map->mapdata[map->chary][map->charx] == 'E'
			&& map->collected != map->i_items))
			message(COLLECT_ALL_COLLECTIBLES);
	}
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_PRESS)
		map->ghost_move = !map->ghost_move;
}
