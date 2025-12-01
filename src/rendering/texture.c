/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:01:06 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 15:01:06 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture(t_game *game, char *path, int index)
{
	game->textures[index].ptr = mlx_xpm_file_to_image(game->mlx, path,
			&game->textures[index].width, &game->textures[index].height);
	if (!game->textures[index].ptr)
		return (-1);
	game->textures[index].addr = mlx_get_data_addr(game->textures[index].ptr,
			&game->textures[index].bpp, &game->textures[index].line_len,
			&game->textures[index].endian);
	return (0);
}

int	load_textures(t_game *game)
{
	if (load_texture(game, game->config.no_texture, NORTH) != 0)
		return (-1);
	if (load_texture(game, game->config.so_texture, SOUTH) != 0)
		return (-1);
	if (load_texture(game, game->config.we_texture, WEST) != 0)
		return (-1);
	if (load_texture(game, game->config.ea_texture, EAST) != 0)
		return (-1);
	return (0);
}

int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray->dir.y < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
}
