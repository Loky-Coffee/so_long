/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 06:34:24 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/14 00:42:30 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	s_img2win(mlx_t *mlx, mlx_image_t *img, int32_t x, int32_t y)
{
	mlx_resize_image (img, S_TEX, S_TEX);
	return (mlx_image_to_window (mlx, img, x, y));
}

bool	ist_valid_key(mlx_key_data_t key_data)
{
	if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP
		|| key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN
		|| key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT
		|| key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT
		|| key_data.key == MLX_KEY_ESCAPE)
		return (1);
	return (0);
}

void	print_position_update(t_map *map, t_tx *tx)
{
	int	oldx;
	int	oldy;
	int	newx;
	int	newy;
	int	item_take;

	oldx = map->t_s.old_charx;
	oldy = map->t_s.old_chary;
	newx = map->t_s.new_charx;
	newy = map->t_s.new_chary;
	item_take = map->t_s.collected;
	if (item_take == map->i_items)
		s_img2win(tx->mlx, tx->m_dooro, map->doorx * S_TEX, map->doory * S_TEX);
	if (map->mapdata[newy][newx] == '0' || map->mapdata[newy][newx] == 'P')
		s_img2win(tx->mlx, tx->m_char, newx * S_TEX, newy * S_TEX);
	if (map->mapdata[newy][newx] == 'E')
		s_img2win(tx->mlx, tx->m_doorw, map->doorx * S_TEX, map->doory * S_TEX);
	if (map->mapdata[oldy][oldx] == 'E' && map->mapdata[newy][newx] == '0'
		&& item_take != map->i_items)
		s_img2win(tx->mlx, tx->m_door, oldx * S_TEX, oldy * S_TEX);
	if (map->mapdata[oldy][oldx] != 'E')
		s_img2win(tx->mlx, tx->m_field, oldx * S_TEX, oldy * S_TEX);
	if (map->mapdata[map->chary][map->charx] != 'E'
		&& item_take != map->i_items)
		s_img2win(tx->mlx, tx->m_door, map->doorx * S_TEX, map->doory * S_TEX);
}

void	press_key(t_map *map, t_tx *tx, mlx_key_data_t key_data)
{
	map->t_s.old_charx = map->charx;
	map->t_s.old_chary = map->chary;
	map->t_s.new_charx = map->charx;
	map->t_s.new_chary = map->chary;
	map->t_s.position_updated = false;
	if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
		map->t_s.new_chary--;
	else if (key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
		map->t_s.new_chary++;
	else if (key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
		map->t_s.new_charx--;
	else if (key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
		map->t_s.new_charx++;
	else if (key_data.key == MLX_KEY_ESCAPE)
		end_game(tx);
	if (map->mapdata[map->t_s.new_chary][map->t_s.new_charx] == 'C')
	{
		map->mapdata[map->t_s.new_chary][map->t_s.new_charx] = '0';
		map->t_s.collected++;
	}
	if ((map->t_s.collected == map->i_items \
		&& map->mapdata[map->chary][map->charx] == 'E')
		|| (map->mapdata[map->t_s.new_chary][map->t_s.new_charx] == 'E'
		&& map->t_s.collected == map->i_items))
		end_game(tx);
}

void	my_key_hook(mlx_key_data_t key_data, void *param)
{
	t_map	*map;
	t_tx	*tx;
	void	**params;

	params = (void **) param;
	map = (t_map *) params [0];
	tx = (t_tx *) params [1];
	if ((key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
		&& ist_valid_key(key_data))
	{
		press_key(map, tx, key_data);
		if (map->mapdata[map->t_s.new_chary][map->t_s.new_charx] != '1')
		{
			map->charx = map->t_s.new_charx;
			map->chary = map->t_s.new_chary;
			map->t_s.position_updated = true;
		}
		if (map->t_s.position_updated)
			print_position_update(map, tx);
		if (map->mapdata[map->t_s.new_chary][map->t_s.new_charx] != '1')
		{
			map->steps++;
			printf("\033[0;92mSteps->%d\n", map->steps);
		}
	}
}
