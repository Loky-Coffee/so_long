/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 06:34:24 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/19 04:11:49 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	log_steps(int steps)
{
	char	*steps_str;

	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("| Steps: ", 1);
	if (steps < 10)
		write(1, "0", 1);
	if (steps < 100)
		write(1, "0", 1);
	if (steps < 1000)
		write(1, "0", 1);
	if (steps < 10000)
		write(1, "0", 1);
	steps_str = ft_itoa(steps);
	if (steps_str != NULL)
	{
		ft_putstr_fd(steps_str, 1);
		free(steps_str);
	}
	ft_putstr_fd(" | \n", 1);
	ft_putstr_fd("+--------------+", 1);
	ft_putstr_fd(RESET "\n", 1);
}

static void	count_steep(t_map *map)
{
	map->steps++;
	log_steps(map->steps);
}

static void	move_player2(t_map *map, t_tx *tx, mlx_key_data_t key_data)
{
	if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
		&& map->mapdata[map->chary][map->charx + 1] != '1')
	{
		map->charx++;
		tx->m_char->instances->x += S_TEX;
		count_steep(map);
	}
	else if (key_data.key == MLX_KEY_ESCAPE)
		end_game (map);
	if (map->mapdata[map->chary][map->charx] == 'C')
	{
		map->mapdata[map->chary][map->charx] = 'X';
		map->collected++;
		keylocation(map);
		tx->m_key->instances[map->index - 1].enabled = false;
		map->index = 0;
	}
	if ((map->mapdata[map->chary][map->charx] == 'E'
		&& map->collected == map->i_items))
		end_game(map);
}

static void	move_player(t_map *map, t_tx *tx, mlx_key_data_t key_data)
{
	if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
		&& map->mapdata[map->chary - 1][map->charx] != '1')
	{
		map->chary--;
		tx->m_char->instances->y -= S_TEX;
		count_steep(map);
	}
	else if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
		&& map->mapdata[map->chary + 1][map->charx] != '1')
	{
		map->chary++;
		tx->m_char->instances->y += S_TEX;
		count_steep(map);
	}
	else if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
		&& map->mapdata[map->chary][map->charx -1] != '1')
	{
		map->charx--;
		tx->m_char->instances->x -= S_TEX;
		count_steep(map);
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
		move_player(map, tx, key_data);
}
