/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:36 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:38 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_config_set(t_game *game)
{
	if (!game->config.no_texture)
		return (0);
	if (!game->config.so_texture)
		return (0);
	if (!game->config.we_texture)
		return (0);
	if (!game->config.ea_texture)
		return (0);
	if (!game->config.floor_set)
		return (0);
	if (!game->config.ceiling_set)
		return (0);
	return (1);
}

static int	is_map_line(char *line)
{
	line = skip_spaces(line);
	if (*line == '1' || *line == '0')
		return (1);
	return (0);
}

static int	process_line(t_game *game, int fd, char *line)
{
	if (is_map_line(line))
	{
		if (!all_config_set(game))
		{
			free(line);
			return (-1);
		}
		return (parse_map(game, fd, line));
	}
	if (parse_config_line(game, line) != 0)
	{
		free(line);
		return (-1);
	}
	return (0);
}

static int	read_config(t_game *game, int fd)
{
	char	*line;
	int		result;

	line = get_next_line(fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (is_map_line(line))
				return (process_line(game, fd, line));
			result = process_line(game, fd, line);
			if (result != 0)
				return (result);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (-1);
}

int	parse_file(t_game *game, char *filename)
{
	int	fd;
	int	result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	result = read_config(game, fd);
	close(fd);
	get_next_line_cleanup();
	if (result != 0)
		return (-1);
	return (0);
}
