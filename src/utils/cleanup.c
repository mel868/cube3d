/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:01:14 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 15:01:15 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_config(t_config *config)
{
	free(config->no_texture);
	free(config->so_texture);
	free(config->we_texture);
	free(config->ea_texture);
}

static void	destroy_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].ptr)
			mlx_destroy_image(game->mlx, game->textures[i].ptr);
		i++;
	}
}

void	cleanup_game(t_game *game)
{
	if (game->img.ptr)
		mlx_destroy_image(game->mlx, game->img.ptr);
	destroy_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map.grid);
	free_config(&game->config);
}
