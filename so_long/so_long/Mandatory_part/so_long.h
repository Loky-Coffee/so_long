/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:25:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/15 15:20:21 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//includes
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include ".././libft/libft.h"
# include ".././MLX42.h"
# define GREEN "\033[92m"
# define RED "\033[91m"
# define RESET "\033[0m"
# define S_TEX 50

//Errormsg enum
enum e_error_code
{
	NO_ERROR,
	MAP_END_DOT_BER,
	ERROR_OPEN_MAP,
	MAP_IS_NOT_CLOSED_BY_1,
	MAP_RESOLUTION_TOO_BIG,
	ONE_CHARACTER_ONE_EXIT,
	INVALID_LETTER_FOUND_IN_MAP,
	MAP_NOT_RECTANGULAR,
	WIN_NOT_POSSIBLE,
	INVALID_NUMBER_OF_ARGUMENTS,
	INVALID_MAP,
	NEED_MINIMUM_1_COLLECTIBLE,
	ERROR_MALLOC,
};

typedef struct s_search
{
	bool	possible;
	int		collected;
	int		tur;
	int		old_charx;
	int		old_chary;
	int		new_charx;
	int		new_chary;
	bool	position_updated;
}	t_search;

typedef struct s_map
{
	char			*mapname;
	char			**mapdata;
	char			**map_check_win;
	int				linelength;
	int				lines;
	int				charx;
	int				chary;
	int				doory;
	int				doorx;
	int				i_items;
	int				steps;
	t_search		t_s;
}	t_map;

typedef struct s_tx
{
	mlx_t			*mlx;
	mlx_texture_t	*r_wall;
	mlx_texture_t	*r_field;
	mlx_texture_t	*r_key;
	mlx_texture_t	*r_door;
	mlx_texture_t	*r_doorw;
	mlx_texture_t	*r_dooro;
	mlx_texture_t	*r_char;
	mlx_image_t		*m_wall;
	mlx_image_t		*m_field;
	mlx_image_t		*m_key;
	mlx_image_t		*m_door;
	mlx_image_t		*m_doorw;
	mlx_image_t		*m_dooro;
	mlx_image_t		*m_char;
	t_map			*txmap;
}	t_tx;

typedef struct s_x
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_x;

int		main(int argc, char **argv);
void	doorlocation(t_map *map);
int		openmap(t_map *map);
int		errormsg(int error_code);
void	checkallones(t_map *map);
void	search(int x, int y, t_map *map, t_search *s);
void	search_utils(t_map *map);
void	onechar_oneexit(t_map *map);
int		only_valid_symbols(t_map *map);
void	my_key_hook(mlx_key_data_t key_data, void *param);
int32_t	s_img2win(mlx_t *mlx, mlx_image_t *img, int32_t x, int32_t y);
int		end_game(t_tx *tx, t_map *map);
void	charlocation(t_map *map);
void	count_collectibles(t_map *map);
void	log_steps(int steps);
void	free_split(char **split_array);

#endif