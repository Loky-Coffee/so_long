/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:25:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/19 04:09:26 by aalatzas         ###   ########.fr       */
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

//texture size please max 50
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

/**
 * DFS search struct
 * @param possible true if the character can move to this position
 * @param tur true if the character can move to this position
*/
typedef struct s_search
{
	bool	possible;
	bool	tur;
}	t_search;

/**
* @param mapname name of the map
* @param mapdata mapdata in a 2d array
* @param map_check_win mapdata in a 2d array
* @param linelength length of the line
* @param lines number of lines
* @param charx x position of the character
* @param chary y position of the character
* @param doory y position of the door
* @param doorx x position of the door
* @param i_items number of collectibles
* @param collected number of collected collectibles
* @param index index for the collectibles instances
* @param steps number of steps
*/
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
	int				collected;
	int				index;
	int				steps;
}	t_map;

/**
* @param mlx mlx pointer
* @param r_wall mlx_texture_t pointer for the wall texture
* @param r_field mlx_texture_t pointer for the field texture
* @param r_key mlx_texture_t pointer for the key texture
* @param r_door mlx_texture_t pointer for the door texture
* @param r_char mlx_texture_t pointer for the character texture
* @param m_wall mlx_image_t pointer for the wall texture
* @param m_field mlx_image_t pointer for the field texture
* @param m_key mlx_image_t pointer for the key texture
* @param m_door mlx_image_t pointer for the door texture
* @param m_char mlx_image_t pointer for the character texture
*/
typedef struct s_tx
{
	mlx_t			*mlx;
	mlx_texture_t	*r_wall;
	mlx_texture_t	*r_field;
	mlx_texture_t	*r_key;
	mlx_texture_t	*r_door;
	mlx_texture_t	*r_char;
	mlx_image_t		*m_wall;
	mlx_image_t		*m_field;
	mlx_image_t		*m_key;
	mlx_image_t		*m_door;
	mlx_image_t		*m_char;
}	t_tx;

//so_long.c global functions
int		main(int argc, char **argv);
void	end_game(t_map *map);

//find_locations.c global functions
void	keylocation(t_map *map);
void	count_collectibles(t_map *map);

//load_texure.c global functions
int32_t	grafik_main(t_map *map, t_tx *tx);

//key_hook.c global functions
void	log_steps(int steps);
void	my_key_hook(mlx_key_data_t key_data, void *param);

//check_map_valid.c global functions
void	search_utils(t_map *map);

//read_map_data.c global functions
int		openmap(t_map *map);

//error_msg.c global functions
int		errormsg(int error_code);

#endif