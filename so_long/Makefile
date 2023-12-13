# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:59:06 by aalatzas          #+#    #+#              #
#    Updated: 2023/12/13 15:55:49 by aalatzas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX = ./libmlx42.a -Iinclude -lglfw
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
OBJ_DIR = obj/
LIBFT_OBJ_DIR = libft/obj/
SRC_DIR = Mandatory_part/
LIBFT_SRC_DIR = libft/src/

SRC = $(SRC_DIR)read_map_data.c $(SRC_DIR)map_error.c \
$(SRC_DIR)check_map_valid.c $(SRC_DIR)texture.c $(SRC_DIR)so_long.c

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))


# SO_LONG RULES
all: $(NAME)

$(NAME): mlx42 $(OBJ) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm MLX42.h
	@rm libmlx42.a 

t:
	@./$(NAME) ./maps/map1.ber

re: fclean all

test: all
	./$(NAME) ./maps/map1.ber

# MLX42 BUILD RULES
mlx42:
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42; cmake -B build; cmake --build build -j4
	mv MLX42/build/libmlx42.a ./
	mv MLX42/include/MLX42/MLX42.h ./
	rm -rf MLX42

# LIBFT RULES
$(LIBFT_OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c
	@mkdir -p $(LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@cd libft && make

re_libft:
	@cd libft && make re

clean_libft:
	@cd libft && make clean

fclean_libft: clean_libft
	@cd libft && make fclean

.PHONY: all clean fclean re start test libft re_libft clean_libft fclean_libft
