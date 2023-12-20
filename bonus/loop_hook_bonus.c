/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:29:42 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/20 09:37:04 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_ghost_collision(t_tx *tx, double ch_x, double ch_y, t_map *map)
{
	double	distance;
	double	distance_x;
	double	distance_y;
	double	ghost_x;
	double	ghost_y;

	distance = 0.6;
	ghost_x = (double)tx->m_enemy2->instances->x / S_TEX;
	ghost_y = (double)tx->m_enemy2->instances->y / S_TEX;
	distance_x = fabs(ghost_x - ch_x);
	distance_y = fabs(ghost_y - ch_y);
	if (distance_x <= distance && distance_y <= distance)
		end_game(map, YOU_LOSE);
}

void	ghost_animation(t_tx *tx, int char_x, int char_y)
{
	static double	ghost_move_counter = 0.0;
	double			update_frequency;
	int				ghost_move_steep;

	update_frequency = GHOST_LOOP_UPDATE_TIME;
	ghost_move_steep = GHOST_MOVE_SPEED;
	ghost_move_counter += 1;
	if (ghost_move_counter >= update_frequency)
	{
		ghost_move_counter = 0.0;
		if (tx->m_enemy2->instances->x < char_x * S_TEX)
			tx->m_enemy2->instances->x += ghost_move_steep;
		else if (tx->m_enemy2->instances->x > char_x * S_TEX)
			tx->m_enemy2->instances->x -= ghost_move_steep;
		if (tx->m_enemy2->instances->y < char_y * S_TEX)
			tx->m_enemy2->instances->y += ghost_move_steep;
		else if (tx->m_enemy2->instances->y > char_y * S_TEX)
			tx->m_enemy2->instances->y -= ghost_move_steep;
	}
	tx->m_enemy1->enabled = ((int)ghost_move_counter / 10) % 2 == 0;
}

void	door_animation(t_tx *tx)
{
	static int	a = 0;

	if (a < 10)
	{
		tx->m_dooro1->enabled = 1;
		tx->m_dooro2->enabled = 0;
	}
	else if (a >= 20 && a < 30)
	{
		tx->m_dooro1->enabled = 0;
		tx->m_dooro2->enabled = 1;
	}
	else if (a >= 30)
		a = 0;
	a++;
}

void	player_animation(t_tx *tx)
{
	static int	a = 0;

	if (a < 8)
	{
		tx->m_player1->enabled = 1;
		tx->m_player2->enabled = 0;
	}
	else if (a >= 8 && a < 16)
	{
		tx->m_player1->enabled = 0;
		tx->m_player2->enabled = 1;
	}
	else if (a >= 16)
		a = 0;
	a++;
}

void	animation_main(void *param)
{
	t_map	*map;
	t_tx	*tx;
	void	**params;

	params = (void **)param;
	map = (t_map *)params[0];
	tx = (t_tx *)params[1];
	if (map->collected == map->i_items)
	{
		tx->m_doorc->enabled = 0;
		door_animation(tx);
	}
	player_animation(tx);
	if (map->ghost_move)
		ghost_animation(tx, map->charx, map->chary);
	check_ghost_collision(tx, map->charx, map->chary, map);
}
