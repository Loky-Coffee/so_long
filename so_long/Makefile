# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:59:06 by aalatzas          #+#    #+#              #
#    Updated: 2023/12/14 01:04:54 by aalatzas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
######################### SO_LONG MANDATORY_PART RULES #########################
################################################################################
NAME = so_long
OBJ_DIR = obj/object_mandatory/
SRC_DIR = Mandatory_part/

SRC = \
			$(SRC_DIR)read_map_data.c \
			$(SRC_DIR)map_error.c \
			$(SRC_DIR)check_map_valid.c \
			$(SRC_DIR)texture.c \
			$(SRC_DIR)so_long.c
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

t:
	@./$(NAME) ./maps/map1.ber

re: fclean all

test: all
	./$(NAME) ./maps/map1.ber
########################### SO_LONG BONUS_PART RULES ###########################
################################################################################
NAME_BONUS = so_long_bonus
OBJ_DIR_BONUS = obj/object_bonus/
SRC_DIR_BONUS = bonus/

SRC_BONUS = \
			$(SRC_DIR_BONUS)read_map_data_bonus.c \
			$(SRC_DIR_BONUS)map_error_bonus.c \
			$(SRC_DIR_BONUS)check_map_valid_bonus.c \
			$(SRC_DIR_BONUS)texture_bonus.c \
			$(SRC_DIR_BONUS)so_long_bonus.c

OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(notdir $(SRC_BONUS:.c=.o)))

all_bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) libft
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLX)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean_bonus:
	@rm -f $(OBJ_BONUS)

fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS)

tb:
	@./$(NAME_BONUS) ./maps/map1.ber

re_bonus: fclean_bonus all_bonus

test_bonus: all_bonus
	@./$(NAME_BONUS) ./maps/map1.ber
############################## MLX42_BUILD RULES ###############################
################################################################################
MLX = ./libmlx42.a -Iinclude -lglfw
mlx:
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42; cmake -B build; cmake --build build -j4
	mv MLX42/build/libmlx42.a ./
	mv MLX42/include/MLX42/MLX42.h ./
	rm -rf MLX42
clean_mlx:
	rm -rf MLX42
	rm MLX42.h
	rm libmlx42.a
############################### LIBFT_BUILD RULES ##############################
################################################################################
LIBFT = ./libft/libft.a
LIBFT_OBJ_DIR = libft/obj/
LIBFT_SRC_DIR = libft/src/

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
################################################################################
.PHONY: all clean fclean re start test libft re_libft clean_libft fclean_libft \
		mlx clean_mlx tb t re_bonus all_bonus clean_bonus fclean_bonus \
		re_bonus test_bonus
fcleanall: fclean fclean_libft fclean_bonus clean_mlx