/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:25:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/13 15:52:51 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//include
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include ".././libft/libft.h"
# include ".././MLX42.h"

//Errormsg
# define MAP_END_DOT_BER 1
# define ERROR_OPEN_MAP 2
# define MAP_IST_NOT_CLOSED_BEI_1 3
# define MAP_RESOLUTION_TOO_BIG 4
# define ONE_CHARECTER_ONE_EXIT 5
# define INVALID_LETHER_FOUND_IN_MAP 6
# define EMPTY_LINES_FOUND_IN_MAP 7
# define MAP_IS_NOT_RECTANGULAR 8
# define WIN_NOT_POSSIBLE 9
# define S_TEX 50

/*
possible == bool ist falls wenn ist not possible t found
all collectibles or the door during DFS

collected == collectibles collected durring DFS
tur == wenn door found during DFS tur == 1
*/
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

/*
mapname == name from map
romap == 
mapdata = map without \n
map_check_win == copy of mapdata so that visited can be marked during DFS.
linelength == length from map length without \n
lines == lines from map
charx == X position from characker (P)
chary == Y position from charakter (P)
i_items == includes the count of the collectibles that need to be collected.
*/
typedef struct s_map
{
	char			*mapname;
	char			*romap;
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
void	openmap(t_map *map);
void	readmap(int fd, size_t checklenght, t_map *map);
void	errormsg(int error_code);
void	checkallones(t_map *map);
void	search(int x, int y, t_map *map, t_search *s);
void	search_utils(t_map *map);
void	onechar_oneexit(t_map *map);
int		only_valid_symbols(t_map *map);
void	my_key_hook(mlx_key_data_t key_data, void *param);
int32_t	s_img2win(mlx_t *mlx, mlx_image_t *img, int32_t x, int32_t y);
void	end_game(mlx_t *mlx);

#endif