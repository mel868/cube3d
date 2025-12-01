/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:58:40 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:58:42 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_new_pos(t_game *game, int key, double *x, double *y)
{
	*x = game->player.pos.x;
	*y = game->player.pos.y;
	if (key == KEY_W)
	{
		*x += game->player.dir.x * game->player.move_speed;
		*y += game->player.dir.y * game->player.move_speed;
	}
	else if (key == KEY_S)
	{
		*x -= game->player.dir.x * game->player.move_speed;
		*y -= game->player.dir.y * game->player.move_speed;
	}
	else if (key == KEY_A)
	{
		*x += game->player.dir.y * game->player.move_speed;
		*y -= game->player.dir.x * game->player.move_speed;
	}
	else if (key == KEY_D)
	{
		*x -= game->player.dir.y * game->player.move_speed;
		*y += game->player.dir.x * game->player.move_speed;
	}
}

void	move_player(t_game *game, int key)
{
	double	new_x;
	double	new_y;

	calc_new_pos(game, key, &new_x, &new_y);
	if (game->map.grid[(int)new_y][(int)new_x] != '1')
	{
		game->player.pos.x = new_x;
		game->player.pos.y = new_y;
	}
}

void	rotate_player(t_game *game, int key)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = game->player.rot_speed;
	if (key == KEY_LEFT)
		rot_speed = -rot_speed;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot_speed)
		- game->player.dir.y * sin(rot_speed);
	game->player.dir.y = old_dir_x * sin(rot_speed) + game->player.dir.y
		* cos(rot_speed);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(rot_speed)
		- game->player.plane.y * sin(rot_speed);
	game->player.plane.y = old_plane_x * sin(rot_speed) + game->player.plane.y
		* cos(rot_speed);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		cleanup_game(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(game, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_player(game, keycode);
	return (0);
}
