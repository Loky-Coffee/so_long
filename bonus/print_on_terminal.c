/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_on_terminal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:47:48 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/20 08:39:25 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	message(int fd)
{
	if (fd == YOU_WIN)
	{
		ft_putstr_fd(GREEN "|  &%$@@   * You won! *   @@$%&  |\n" RESET, 1);
		ft_putstr_fd(GREEN "+--------------------------------+\n" RESET, 1);
	}
	else if (fd == YOU_LOSE)
	{
		ft_putstr_fd(RED "| &%$@@   * You lost! *   @@$%&  |\n" RESET, 1);
		ft_putstr_fd(RED "+--------------------------------+\n" RESET, 1);
	}
	else if (fd == GAME_STOPED)
	{
		ft_putstr_fd(RED "| &%$@@  * Game stoped! *  @@$%& |\n" RESET, 1);
		ft_putstr_fd(RED "+--------------------------------+\n" RESET, 1);
	}
	else if (fd == COLLECT_ALL_COLLECTIBLES)
	{
		ft_putstr_fd(YELLOW "|*Collect The Coins First to Win*|\n" RESET, 1);
		ft_putstr_fd(YELLOW "+--------------------------------+\n" RESET, 1);
	}
}

void	print_steps(int steps)
{
	char	*steps_str;

	ft_putstr_fd(CYAN, 1);
	ft_putstr_fd("| &%$@@  * Steps: ", 1);
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
	ft_putstr_fd(" *  @@$%& |\n", 1);
	ft_putstr_fd("+--------------------------------+", 1);
	ft_putstr_fd(RESET "\n", 1);
}

void	put_steeps_to_screen(t_map *map, t_tx *tx)
{
	char	*collectibles;
	char	*items;
	char	*steps;

	if (!map || !tx->mlx || !tx->m_black)
		return ;
	collectibles = ft_itoa(map->collected);
	items = ft_itoa(map->i_items);
	steps = ft_itoa(map->steps);
	mlx_image_to_window(tx->mlx, tx->m_black, 0, (map->lines * S_TEX));
	mlx_put_string(tx->mlx, "Steps:", 0, map->lines * S_TEX);
	mlx_put_string(tx->mlx, steps, (S_TEX + 20) * 1.2, map->lines * S_TEX);
	mlx_put_string(tx->mlx, "Collect:", (S_TEX + 20) * 2, map->lines * S_TEX);
	mlx_put_string(tx->mlx, collectibles,
		(S_TEX + 20) * 3.6, map->lines * S_TEX);
	free(collectibles);
	mlx_put_string(tx->mlx, "/", (S_TEX + 20) * 4, map->lines * S_TEX);
	mlx_put_string(tx->mlx, items, (S_TEX + 20) * 4.2, map->lines * S_TEX);
	free(items);
	free(steps);
}
