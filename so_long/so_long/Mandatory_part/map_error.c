/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:02:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/15 15:14:31 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	errormsg1(int error_code)
{
	if (error_code == WIN_NOT_POSSIBLE)
		putstr("ERROR: It's not possible to win!\n");
	else if (error_code == INVALID_NUMBER_OF_ARGUMENTS)
		putstr("ERROR: Invalid number of arguments!\n");
	else if (error_code == INVALID_MAP)
		putstr("ERROR: Invalid map!\n");
	else if (error_code == NEED_MINIMUM_1_COLLECTIBLE)
		putstr("ERROR: You need minimum 1 collectible!\n");
	else if (error_code == ERROR_MALLOC)
		putstr("ERROR: Malloc failed!\n");
	else
		putstr("ERROR: Unknown error!\n");
}

int	errormsg(int error_code)
{
	if (error_code == MAP_END_DOT_BER)
		putstr("ERROR: The MAP must end with the ->.ber<- extension.\n");
	else if (error_code == ERROR_OPEN_MAP)
		perror("ERROR");
	else if (error_code == MAP_IS_NOT_CLOSED_BY_1)
		putstr("ERROR: The map must be surrounded by ones!\n");
	else if (error_code == MAP_RESOLUTION_TOO_BIG)
	{
		putstr("ERROR: The game only works with the resolution ");
		putstr("2560x1440!\nThe map is too big for this resolution!\n");
	}
	else if (error_code == ONE_CHARACTER_ONE_EXIT)
		putstr("ERROR: Exactly 1 character and 1 exit needed!\n");
	else if (error_code == INVALID_LETTER_FOUND_IN_MAP)
		putstr("ERROR: Invalid characters found in the map. \
		\nPlease use only the chars 'P','C','1','0','E' in the map!\n");
	else if (error_code == MAP_NOT_RECTANGULAR)
		putstr("ERROR: Map is not rectangular!\n");
	else
		errormsg1(error_code);
	return (EXIT_FAILURE);
}

void	log_steps(int steps)
{
	char	*steps_str;

	putstr(GREEN);
	putstr("| Steps: ");
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
		putstr(steps_str);
		free(steps_str);
	}
	putstr(" | \n");
	putstr("+--------------+");
	putstr(RESET "\n");
}

int	end_game(t_tx *tx, t_map *map)
{
	if (map->mapdata[map->t_s.new_chary][map->t_s.new_charx] == 'E' \
		&& map->t_s.collected == map->i_items)
	{
		putstr(RED "+--------------+\n" RESET);
		putstr(RED "| * You won! * |\n" RESET);
		putstr(RED "+--------------+\n" RESET);
	}
	mlx_delete_image(tx->mlx, tx->m_wall);
	mlx_delete_image(tx->mlx, tx->m_field);
	mlx_delete_image(tx->mlx, tx->m_key);
	mlx_delete_image(tx->mlx, tx->m_door);
	mlx_delete_image(tx->mlx, tx->m_doorw);
	mlx_delete_image(tx->mlx, tx->m_dooro);
	mlx_delete_image(tx->mlx, tx->m_char);
	free_split(map->mapdata);
	free_split(map->map_check_win);
	free(tx->mlx);
	exit(EXIT_SUCCESS);
}
