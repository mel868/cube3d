/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:57:31 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:57:39 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

enum	e_directions
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
};

int		parse_file(t_game *game, char *filename);
int		parse_config_line(t_game *game, char *line);
int		parse_north_texture(t_game *game, char *line);
int		parse_south_texture(t_game *game, char *line);
int		parse_west_texture(t_game *game, char *line);
int		parse_east_texture(t_game *game, char *line);
int		parse_map(t_game *game, int fd, char *first_line);
int		validate_map(t_game *game);
char	*skip_spaces(char *str);
int		is_empty_line(char *line);

void	init_game(t_game *game);
void	init_player(t_game *game);
int		load_textures(t_game *game);

void	render_frame(t_game *game);
void	cast_ray(t_game *game, int x, t_ray *ray);
void	draw_column(t_game *game, int x, t_ray *ray);
int		get_texture_index(t_ray *ray);

int		key_press(int keycode, t_game *game);
int		close_window(t_game *game);
void	move_player(t_game *game, int key);
void	rotate_player(t_game *game, int key);

void	error_exit(char *msg);
void	cleanup_game(t_game *game);
void	free_map(char **map);
void	free_config(t_config *config);

int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		parse_color(char *str, t_color *color);
int		parse_texture_path(char *line, char **path);
int		is_valid_map_char(char c);
int		is_player_char(char c);

void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
int		create_color(int r, int g, int b);

#endif
