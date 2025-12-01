/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:11 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:13 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_direction_north(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = 0.66;
	player->plane.y = 0;
}

static void	set_direction_south(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = -0.66;
	player->plane.y = 0;
}

static void	set_direction_west(t_player *player)
{
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = -0.66;
}

static void	set_direction_east(t_player *player)
{
	player->dir.x = 1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
}

void	init_player(t_game *game)
{
	game->player.pos.x = (double)game->map.player_x + 0.5;
	game->player.pos.y = (double)game->map.player_y + 0.5;
	game->player.move_speed = MOVE_SPEED;
	game->player.rot_speed = ROT_SPEED;
	if (game->map.player_dir == 'N')
		set_direction_north(&game->player);
	else if (game->map.player_dir == 'S')
		set_direction_south(&game->player);
	else if (game->map.player_dir == 'W')
		set_direction_west(&game->player);
	else if (game->map.player_dir == 'E')
		set_direction_east(&game->player);
}
