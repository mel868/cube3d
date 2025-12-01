NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I./includes -I./mlx
MLXFLAGS	= -L./mlx -lmlx -lXext -lX11 -lm

MLX_DIR		= mlx
MLX_LIB		= $(MLX_DIR)/libmlx.a

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/parsing/parse_file.c \
			  $(SRC_DIR)/parsing/parse_config.c \
			  $(SRC_DIR)/parsing/parse_map.c \
			  $(SRC_DIR)/parsing/validate_map.c \
			  $(SRC_DIR)/parsing/parse_utils.c \
			  $(SRC_DIR)/parsing/parse_color.c \
			  $(SRC_DIR)/parsing/parse_textures.c \
			  $(SRC_DIR)/rendering/render.c \
			  $(SRC_DIR)/rendering/raycasting.c \
			  $(SRC_DIR)/rendering/draw.c \
			  $(SRC_DIR)/rendering/texture.c \
			  $(SRC_DIR)/events/keyboard.c \
			  $(SRC_DIR)/events/window.c \
			  $(SRC_DIR)/init/init_game.c \
			  $(SRC_DIR)/init/init_player.c \
			  $(SRC_DIR)/utils/error.c \
			  $(SRC_DIR)/utils/cleanup.c \
			  $(SRC_DIR)/utils/string_utils.c \
			  $(SRC_DIR)/utils/string_utils2.c \
			  $(SRC_DIR)/utils/color_utils.c \
			  $(SRC_DIR)/utils/get_next_line.c \
			  $(SRC_DIR)/utils/get_next_line_utils.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
