/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:02:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/14 00:44:19 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	errormsg2(int error_code)
{
	if (error_code == 9)
	{
		write(1, "ERROR: Ist not possible to Win!\n", 32);
		exit (EXIT_FAILURE);
	}
}

void	errormsg1(int error_code)
{
	if (error_code == 5)
	{
		write(1, "ERROR: Only 1 character and 1 exit is allowed !\n", 48);
		exit (EXIT_FAILURE);
	}
	if (error_code == 6)
	{
		write(1, "ERROR: Invalid characters found in the map. \
		\nPlease use only the chars 'P','C','1','0','E' in the map!\n", 105);
		exit (EXIT_FAILURE);
	}
	if (error_code == 7)
	{
		perror("ERROR: I think you shouldn't use empty lines in the map :P\n");
		exit (EXIT_FAILURE);
	}
	if (error_code == 8)
	{
		write(1, "ERROR: Map ist not rectangular!\n", 32);
		exit (EXIT_FAILURE);
	}
}

void	errormsg(int error_code)
{
	if (error_code == 1)
	{
		write(1, "ERROR: The MAP must end with the ->.ber<- extension.\n", 53);
		exit (EXIT_FAILURE);
	}
	else if (error_code == 2)
	{
		perror("ERROR");
		exit (EXIT_FAILURE);
	}
	else if (error_code == 3)
	{
		write(1, "ERROR:The map must be surrounded by ones!\n", 42);
		exit (EXIT_FAILURE);
	}
	else if (error_code == 4)
	{
		write(1, "ERROR:The game only works with the resolution ", 46);
		write(1, "2560x1440!\nThe map is too big for this resolution!\n", 51);
		exit (EXIT_FAILURE);
	}
	errormsg1(error_code);
	errormsg2(error_code);
}

void	end_game(t_tx *tx)
{
	mlx_terminate(tx->mlx);
	system("leaks so_long_bonus");
	exit(EXIT_SUCCESS);
}
