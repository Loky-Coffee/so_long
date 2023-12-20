/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:02:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/19 03:00:07 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errormsg1(int error_code)
{
	if (error_code == WIN_NOT_POSSIBLE)
		ft_putstr_fd("ERROR: It's not possible to win!\n", 2);
	else if (error_code == INVALID_NUMBER_OF_ARGUMENTS)
		ft_putstr_fd("ERROR: Invalid number of arguments!\n", 2);
	else if (error_code == INVALID_MAP)
		ft_putstr_fd("ERROR: Invalid map!\n", 2);
	else if (error_code == NEED_MINIMUM_1_COLLECTIBLE)
		ft_putstr_fd("ERROR: You need minimum 1 collectible!\n", 2);
	else if (error_code == ERROR_MALLOC)
		ft_putstr_fd("ERROR: Malloc failed!\n", 2);
	else
		ft_putstr_fd("ERROR: Unknown error!\n", 2);
}

int	errormsg(int error_code)
{
	if (error_code == MAP_END_DOT_BER)
		ft_putstr_fd("ERROR: The MAP must end with the ->.ber<- extension.\n",
			2);
	else if (error_code == ERROR_OPEN_MAP)
		perror("ERROR");
	else if (error_code == MAP_IS_NOT_CLOSED_BY_1)
		ft_putstr_fd("ERROR: The map must be surrounded by ones!\n", 2);
	else if (error_code == MAP_RESOLUTION_TOO_BIG)
	{
		ft_putstr_fd("ERROR: The game only works with the resolution ", 2);
		ft_putstr_fd("2560x1440!\nThe map is too big for this resolution!\n",
			2);
	}
	else if (error_code == ONE_CHARACTER_ONE_EXIT)
		ft_putstr_fd("ERROR: Exactly 1 character and 1 exit needed!\n", 2);
	else if (error_code == INVALID_LETTER_FOUND_IN_MAP)
		ft_putstr_fd("ERROR: Invalid characters found in the map. \
		\nPlease use only the chars 'P','C','1','0','E' in the map!\n", 2);
	else if (error_code == MAP_NOT_RECTANGULAR)
		ft_putstr_fd("ERROR: Map is not rectangular!\n", 2);
	else
		errormsg1(error_code);
	exit (EXIT_FAILURE);
}
	// system("leaks so_long");