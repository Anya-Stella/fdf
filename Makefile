# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 15:01:07 by tishihar          #+#    #+#              #
#    Updated: 2025/01/24 12:11:50 by tishihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#===============================================================================
#                                基本設定
#===============================================================================

# name of project
NAME := fdf

# compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror


# for dev and debug
DEVFLAGS := -O0 -g -fsanitize=address

# valgrind
VALGRIND := valgrind
VALGRINDFLAGS :=  --leak-check=full
ARGS ?=
#===============================================================================
#                               ディレクトリ設定
#===============================================================================

# source_code and object_code directory
SRC_DIR := src
OBJ_DIR := bin

# libft
LIBFT_DIR := libft
LIBFT_INC_DIR := $(LIBFT_DIR)

# mlx
MLX_DIR := minilibx-linux
MLX_INC_DIR := $(MLX_DIR)

# include
INC_DIR := include
INCLUDES := -I$(INC_DIR) -I$(LIBFT_INC_DIR) -I$(MLX_INC_DIR)
#===============================================================================
#                              ソースファイル設定
#===============================================================================

SRCS := \
	get_next_line.c \
	get_next_line_utils.c \
	init_project.c \
	init_matrix.c \
	init_width_height.c \
	draw_line.c \
	test.c \
    main.c \

# replace object (.c → .o)
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
#===============================================================================
#                              ライブラリ設定
#===============================================================================

# PATH of libft.a
LIBFT := $(LIBFT_DIR)/libft.a

# PATH of libmlx.a
MLX := $(MLX_INC_DIR)/libmlx_Linux.a 
MLX_FLAGS := -lXext -lX11

# Math frags
MATH_FRAGS := -lm

# frags
LIB_FLAGS := $(MLX_FRAGS) $(MATH_FRAGS)
#===============================================================================
#                    　---ここから下は基本変えなくていい---
#===============================================================================
#===============================================================================
#                                ルール定義
#===============================================================================

all: $(NAME)

# use: make dev
dev: CFLAGS += $(DEVFLAGS)
dev: LDFLAGS += $(DEVFLAGS)
dev: all

# use: make run ARGS="1 2 3" or make run
run: $(NAME)
	$(VALGRIND) $(VALGRINDFLAGS) ./$(NAME) $(ARGS)

# main(linker) rule
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT) $(MLX) $(LIB_FLAGS) $(LDFLAGS)

# compile rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# generate libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# cleans
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all
devre: fclean dev

# phony
.PHONY: all dev devre clean fclean re

