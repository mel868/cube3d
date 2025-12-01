/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:02 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:04 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	int	i;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error\nFailed to initialize MLX");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		error_exit("Error\nFailed to create window");
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->img.ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img.ptr)
		error_exit("Error\nFailed to create image");
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	game->config.no_texture = NULL;
	game->config.so_texture = NULL;
	game->config.we_texture = NULL;
	game->config.ea_texture = NULL;
	game->config.floor_set = 0;
	game->config.ceiling_set = 0;
	game->map.grid = NULL;
	i = 0;
	while (i < 4)
		game->textures[i++].ptr = NULL;
}
