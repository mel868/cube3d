/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:02:09 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 15:02:11 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

static int	game_loop(t_game *game)
{
	render_frame(game);
	return (0);
}

static void	setup_game(t_game *game, char *filename)
{
	if (parse_file(game, filename) != 0)
	{
		cleanup_game(game);
		error_exit("Error\nFailed to parse file");
	}
	if (validate_map(game) != 0)
	{
		cleanup_game(game);
		error_exit("Error\nInvalid map");
	}
	init_player(game);
	if (load_textures(game) != 0)
	{
		cleanup_game(game);
		error_exit("Error\nFailed to load textures");
	}
}

static void	start_game(t_game *game)
{
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./cub3D <map.cub>");
	if (!check_extension(argv[1]))
		error_exit("Error\nInvalid file extension (must be .cub)");
	init_game(&game);
	setup_game(&game, argv[1]);
	start_game(&game);
	return (0);
}
