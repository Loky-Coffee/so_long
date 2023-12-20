/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:25:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/20 12:03:15 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//External library includes
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

//mlx Library includes
# include ".././libft/libft.h"
# include ".././MLX42.h"

//terminal collors
# define RED "\033[91m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define BLUE "\033[94m"
# define MAGENTA "\033[95m"
# define CYAN "\033[96m"
# define RESET "\033[0m"

//texture size (SCALE) please max for Bonus: 74
# define S_TEX 74

//Ghost move speed INT! and loop update time DOUBLE!
//If GHOST_MOVE_SPEED > 2 ist not possible t win the game
# define GHOST_MOVE_SPEED 1
# define GHOST_LOOP_UPDATE_TIME 0.1

//End of Game
# define YOU_WIN 0
# define YOU_LOSE 1
# define GAME_STOPED 2
# define COLLECT_ALL_COLLECTIBLES 3

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

//mlx_texture_t struct
/**
* @param Variable: pointer to the mlx image
* @param ______________________________________________
* @param m_wall mlx_texture_t pointer for the wall texture
* @param m_field mlx_texture_t pointer for the field texture
* @param m_key mlx_texture_t pointer for the key texture
* @param m_doorc mlx_texture_t pointer for the door closed texture
* @param m_dooro1 mlx_texture_t pointer for the door open texture
* @param m_dooro2 mlx_texture_t pointer for the door open texture
* @param m_player1 mlx_texture_t pointer for the player texture
* @param m_player2 mlx_texture_t pointer for the player texture
* @param m_enemy1 mlx_texture_t pointer for the enemy texture
* @param m_enemy2 mlx_texture_t pointer for the enemy texture
* @param m_black mlx_texture_t pointer for the black texture
* @param ______________________________________________
* @param Example:
* @param mlx mlx pointer
* @param r_name mlx_texture_t pointer for the wall texture
* @param m_name mlx_image_t pointer for the key texture
*/
typedef struct s_tx
{
	mlx_t			*mlx;
	mlx_texture_t	*r_key;
	mlx_texture_t	*r_wall;
	mlx_texture_t	*r_field;
	mlx_texture_t	*r_doorc;
	mlx_texture_t	*r_dooro1;
	mlx_texture_t	*r_dooro2;
	mlx_texture_t	*r_player1;
	mlx_texture_t	*r_player2;
	mlx_texture_t	*r_enemy1;
	mlx_texture_t	*r_enemy2;
	mlx_texture_t	*r_black;
	mlx_image_t		*m_wall;
	mlx_image_t		*m_field;
	mlx_image_t		*m_key;
	mlx_image_t		*m_doorc;
	mlx_image_t		*m_dooro1;
	mlx_image_t		*m_dooro2;
	mlx_image_t		*m_player1;
	mlx_image_t		*m_player2;
	mlx_image_t		*m_enemy1;
	mlx_image_t		*m_enemy2;
	mlx_image_t		*m_black;
}	t_tx;

//Map struct
/**
* @param mapname char*: name of the map
* @param mapdata char**: mapdata in a 2d array
* @param map_check_win char**: mapdata in a 2d array
* @param linelength int: length of the line
* @param lines int: number of lines
* @param charx int: x position of the character
* @param chary int: y position of the character
* @param doory int: y position of the door
* @param doorx int: x position of the door
* @param i_items int: number of collectibles
* @param collected int: number of collected collectibles
* @param index int: index for the collectibles instances
* @param steps int: number of steps
* @param ghost_move bool: true if the ghost is moving
* @param load int: load_enemyes animation scaling factor
* @param load_x int: x position for the load_anemies animation
* @param load_y int: y position for the load_anemies animation
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
	int				i_enemies;
	int				collected;
	int				index;
	int				steps;
	int				load_fx;
	int				load_fy;
	int				load_x;
	int				load_y;
	bool			ghost_move;
	t_tx			tx;
}	t_map;

//so_long.c global functions
int			main(int argc, char **argv);
void		end_game(t_map *map, int fd);

//find_locations.c global functions
void		keylocation(t_map *map);
void		count_collectibles(t_map *map);

//load_texure.c global functions
int32_t		grafik_main(t_map *map, t_tx *tx);
void		my_img_to_window(mlx_t *mlx, mlx_image_t *img, int x, int y);

//key_hook.c global functions
void		print_steps(int steps);
void		my_key_hook(mlx_key_data_t key_data, void *param);

//check_map_valid.c global functions
void		search_utils(t_map *map);

//read_map_data.c global functions
int			openmap(t_map *map);

//error_msg.c global functions
int			errormsg(int error_code);

//print_on_terminal.c global functions
void		message(int fd);
void		put_steeps_to_screen(t_map *map, t_tx *tx);

//loop_hook_bonus.c global functions
void		animation_main(void *param);

#endif