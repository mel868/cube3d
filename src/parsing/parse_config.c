/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:29 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:30 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_floor_color(t_game *game, char *line)
{
	if (game->config.floor_set)
		return (-1);
	line++;
	if (parse_color(line, &game->config.floor) != 0)
		return (-1);
	game->config.floor_set = 1;
	return (0);
}

static int	parse_ceiling_color(t_game *game, char *line)
{
	if (game->config.ceiling_set)
		return (-1);
	line++;
	if (parse_color(line, &game->config.ceiling) != 0)
		return (-1);
	game->config.ceiling_set = 1;
	return (0);
}

int	parse_config_line(t_game *game, char *line)
{
	line = skip_spaces(line);
	if (ft_strncmp(line, "NO", 2) == 0)
		return (parse_north_texture(game, line));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (parse_south_texture(game, line));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (parse_west_texture(game, line));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (parse_east_texture(game, line));
	else if (ft_strncmp(line, "F", 1) == 0)
		return (parse_floor_color(game, line));
	else if (ft_strncmp(line, "C", 1) == 0)
		return (parse_ceiling_color(game, line));
	return (-1);
}
