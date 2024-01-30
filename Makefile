# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:39:30 by ecorvisi          #+#    #+#              #
#    Updated: 2023/10/20 14:35:11 by ecorvisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -g3
CPPFLAGS = -Iinc -I ./MLX42/include

NAME = cub3D
LIB = libft/libft.a
LIBFT_FLAGS = -L libft -lft
LIBMLX	:= ./MLX42

SRC_DIR = src
OBJ_DIR = obj
DIR_OBJS = mkdir -p $(@D)

SRC = 	main.c\
		init/init_game.c \
		init/init_texture.c \
		init/init_RGB.c \
		init/init_RGB_utils.c \
		init/init_map.c\
		init/init_utils.c \
		gnl/get_next_line_cub.c\
		gnl/get_next_line_utils_cub.c\
		utils/utils.c \
		utils/ft_strdup_without_nl.c\
		parsing/parsing.c \
		parsing/parsing_utils.c \
		parsing/parsing_utils2.c \
		parsing/parsing_texture.c \
		texture/load_texture.c \
		texture/check_texture.c \
		free/free.c \
		free/return_error.c \
		execution/execution.c \
		execution/cub_hook.c \
		execution/draw_cub.c \
		execution/player.c \
		execution/draw_map.c \
		execution/draw_map_partial.c \
		execution/draw_square.c \
		execution/player_directions.c \
		execution/player_view_angle.c \
		execution/draw_line.c \
		execution/draw_rubikscube.c \
		execution/draw_rays.c \
		execution/movement_impossible.c \
		execution/hex_to_decimal.c \
		execution/get_pixel_color.c \
		
SRCS = $(SRC:%=$(SRC_DIR)/%)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	@echo "\033[1;4m\033[1;33m                       \033[0m"
	@echo "\033[1;4m\033[1;33m\033[1;1m*      COMPILING      *\033[0m"
	@make bonus -s -C libft
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(LIB) $(CPPFLAGS) $(LIBS) -lreadline
	@echo "\033[1;4m\033[1;32m                            \033[0m"
	@echo "\033[1;4m\033[1;32m\033[1;1m*      CUB3D COMPILED      *\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@make clean -s -C libft
	@rm -rf $(LIBMLX)/build
	@echo "\033[1;4m\033[1;34m                                     \033[0m"
	@echo "\033[1;4m\033[1;34m\033[1;1m*      DELETING OBJS DIRECTORY      *\033[0m"
	
fclean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@rm -rf $(NAME)
	@make fclean -s -C libft
	@rm -rf $(LIBMLX)/build
	@echo "\033[1;4m\033[1;31m                                 \033[0m"
	@echo "\033[1;4m\033[1;31m\033[1;1m*      CLEANING ALL BINARY      *\033[0m"

re: fclean all

run:all
	./cub3D maps/8-8_easy.cub

run2:all
	valgrind ./cub3D maps/8-8_easy.cub

.PHONY: all clean fclean re
