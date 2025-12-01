/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:57:55 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:58:05 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_player
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_config
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		floor;
	t_color		ceiling;
	int			floor_set;
	int			ceiling_set;
}				t_config;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	char		player_dir;
	int			player_x;
	int			player_y;
}				t_map;

typedef struct s_ray
{
	t_vec2		dir;
	t_vec2		side_dist;
	t_vec2		delta_dist;
	t_vec2		map_pos;
	int			step_x;
	int			step_y;
	int			side;
	double		wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		textures[4];
	t_config	config;
	t_map		map;
	t_player	player;
	int			win_width;
	int			win_height;
}				t_game;

#endif
