/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:58 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:59 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_north_texture(t_game *game, char *line)
{
	if (game->config.no_texture)
		return (-1);
	line += 2;
	line = skip_spaces(line);
	return (parse_texture_path(line, &game->config.no_texture));
}

int	parse_south_texture(t_game *game, char *line)
{
	if (game->config.so_texture)
		return (-1);
	line += 2;
	line = skip_spaces(line);
	return (parse_texture_path(line, &game->config.so_texture));
}

int	parse_west_texture(t_game *game, char *line)
{
	if (game->config.we_texture)
		return (-1);
	line += 2;
	line = skip_spaces(line);
	return (parse_texture_path(line, &game->config.we_texture));
}

int	parse_east_texture(t_game *game, char *line)
{
	if (game->config.ea_texture)
		return (-1);
	line += 2;
	line = skip_spaces(line);
	return (parse_texture_path(line, &game->config.ea_texture));
}
