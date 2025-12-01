/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:46 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:50 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_width(char **map_lines, int height)
{
	int	max_width;
	int	width;
	int	i;

	max_width = 0;
	i = 0;
	while (i < height)
	{
		width = ft_strlen(map_lines[i]);
		if (width > max_width)
			max_width = width;
		i++;
	}
	return (max_width);
}

static char	**allocate_map(int width, int height)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		j = 0;
		while (j < width)
			map[i][j++] = ' ';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	fill_map_line(char *dst, char *src, int width)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < width)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = '\0';
}

static char	**read_map_lines(int fd, char *first, int *height)
{
	char	**lines;
	char	*line;
	int		i;
	int		capacity;

	capacity = 100;
	lines = malloc(sizeof(char *) * capacity);
	if (!lines)
		return (NULL);
	lines[0] = ft_strdup(first);
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		lines[i++] = line;
		line = get_next_line(fd);
	}
	*height = i;
	lines[i] = NULL;
	return (lines);
}

int	parse_map(t_game *game, int fd, char *first_line)
{
	char	**temp_lines;
	int		height;
	int		i;

	temp_lines = read_map_lines(fd, first_line, &height);
	free(first_line);
	if (!temp_lines)
		return (-1);
	game->map.width = get_map_width(temp_lines, height);
	game->map.height = height;
	game->map.grid = allocate_map(game->map.width, height);
	if (!game->map.grid)
	{
		free_map(temp_lines);
		return (-1);
	}
	i = 0;
	while (i < height)
	{
		fill_map_line(game->map.grid[i], temp_lines[i], game->map.width);
		i++;
	}
	free_map(temp_lines);
	return (0);
}
