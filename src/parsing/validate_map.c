/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:00:10 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 15:00:12 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_player(t_game *game)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (is_player_char(game->map.grid[i][j]))
			{
				game->map.player_dir = game->map.grid[i][j];
				game->map.player_x = j;
				game->map.player_y = i;
				player_count++;
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

static int	check_valid_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (!is_valid_map_char(game->map.grid[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_surrounded(t_game *game, int y, int x)
{
	if (y <= 0 || y >= game->map.height - 1)
		return (0);
	if (x <= 0 || x >= game->map.width - 1)
		return (0);
	if (game->map.grid[y - 1][x] == ' ')
		return (0);
	if (game->map.grid[y + 1][x] == ' ')
		return (0);
	if (game->map.grid[y][x - 1] == ' ')
		return (0);
	if (game->map.grid[y][x + 1] == ' ')
		return (0);
	return (1);
}

static int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == '0'
				|| is_player_char(game->map.grid[i][j]))
			{
				if (!is_surrounded(game, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_valid_chars(game))
		return (-1);
	if (!check_player(game))
		return (-1);
	if (!check_walls(game))
		return (-1);
	return (0);
}
