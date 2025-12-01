/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:00:18 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 15:00:19 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_floor_ceiling(t_game *game, int x, t_ray *ray)
{
	int	y;
	int	floor_color;
	int	ceiling_color;

	floor_color = create_color(game->config.floor.r, game->config.floor.g,
			game->config.floor.b);
	ceiling_color = create_color(game->config.ceiling.r, game->config.ceiling.g,
			game->config.ceiling.b);
	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(&game->img, x, y, ceiling_color);
		y++;
	}
	y = ray->draw_end + 1;
	while (y < WIN_HEIGHT)
	{
		put_pixel(&game->img, x, y, floor_color);
		y++;
	}
}

void	draw_column(t_game *game, int x, t_ray *ray)
{
	int		y;
	int		tex_idx;
	int		tex_x;
	double	step;
	double	tex_pos;

	draw_floor_ceiling(game, x, ray);
	tex_idx = get_texture_index(ray);
	tex_x = (int)(ray->wall_x * (double)game->textures[tex_idx].width);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		tex_x = game->textures[tex_idx].width - tex_x - 1;
	step = 1.0 * game->textures[tex_idx].height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		put_pixel(&game->img, x, y, get_pixel(&game->textures[tex_idx], tex_x,
				(int)tex_pos & (game->textures[tex_idx].height - 1)));
		tex_pos += step;
		y++;
	}
}
