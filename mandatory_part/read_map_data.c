/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:59:03 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/19 02:52:47 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	verify_line_length(const char *line, const int length)
{
	int	l;

	l = ft_strlen(line);
	if (line[l - 1] == '\n')
		return (l == length);
	return (l + 1 == length);
}

static char	*readmap2(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL || line[0] == '\n')
		errormsg(INVALID_MAP);
	map->linelength = ft_strlen(line);
	map->lines++;
	return (line);
}

static void	readmap(int fd, t_map *map)
{
	char	*line;
	char	*mapstr;
	char	*temp;

	mapstr = readmap2(fd, map);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (verify_line_length(line, map->linelength) != true)
			errormsg(MAP_NOT_RECTANGULAR);
		temp = ft_strjoin(mapstr, line);
		if (temp == NULL)
			errormsg(ERROR_MALLOC);
		free(mapstr);
		mapstr = temp;
		map->lines++;
		free(line);
	}
	close(fd);
	map->mapdata = ft_split(mapstr, '\n');
	map->map_check_win = ft_split(mapstr, '\n');
	free(mapstr);
}

static int	check_file_ext(const char *filename, const char *file_ext)
{
	const char	*p;

	p = ft_strrchr(filename, '.');
	if (p == NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(p, file_ext, ft_strlen(file_ext) + 1) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	openmap(t_map *map)
{
	int		fd;

	if (check_file_ext(map->mapname, ".ber") != EXIT_SUCCESS)
		return (errormsg(MAP_END_DOT_BER));
	fd = open(map->mapname, O_RDONLY);
	if (fd == -1)
		errormsg(ERROR_OPEN_MAP);
	readmap(fd, map);
	return (0);
}
