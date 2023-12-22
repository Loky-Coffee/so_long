# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loky <loky@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:59:06 by aalatzas          #+#    #+#              #
#    Updated: 2023/12/22 20:57:49 by loky             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIB_MLX = libmlx42.a
######################### SO_LONG_MANDATORY_PART_RULES #########################
################################################################################
NAME = so_long
OBJ_DIR = obj/object_mandatory/
SRC_DIR = mandatory_part/

SRC = \
			$(SRC_DIR)read_map_data.c \
			$(SRC_DIR)map_error.c \
			$(SRC_DIR)check_map_valid.c \
			$(SRC_DIR)key_hook.c \
			$(SRC_DIR)so_long.c \
			$(SRC_DIR)find_locations.c \
			$(SRC_DIR)load_texure.c
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)
$(NAME): $(OBJ) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(LIB_MLX)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

t1: $(NAME)
	./$(NAME) ./maps/maps_mandatory/map1.ber
t2: $(NAME)
	./$(NAME) ./maps/maps_mandatory/map2.ber
t3: $(NAME)
	./$(NAME) ./maps/maps_mandatory/map3.ber
t4: $(NAME)
	./$(NAME) ./maps/maps_mandatory/map4.ber
t5: $(NAME)
	./$(NAME) ./maps/maps_mandatory/map5.ber
t6: $(NAME)
	./$(NAME) ./maps/maps_mandatory/map6.ber

re: fclean all

test: all
	./$(NAME) ./maps/map1.ber
########################### SO_LONG BONUS_PART_RULES ###########################
################################################################################
NAME_BONUS = so_long_bonus
OBJ_DIR_BONUS = obj/object_bonus/
SRC_DIR_BONUS = bonus/

SRC_BONUS = \
			$(SRC_DIR_BONUS)read_map_data_bonus.c \
			$(SRC_DIR_BONUS)map_error_bonus.c \
			$(SRC_DIR_BONUS)check_map_valid_bonus.c \
			$(SRC_DIR_BONUS)load_texure_bonus.c \
			$(SRC_DIR_BONUS)so_long_bonus.c \
			$(SRC_DIR_BONUS)find_locations_bonus.c \
			$(SRC_DIR_BONUS)key_hook_bonus.c \
			$(SRC_DIR_BONUS)loop_hook_bonus.c \
			$(SRC_DIR_BONUS)print_on_terminal.c \

OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(notdir $(SRC_BONUS:.c=.o)))

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) libft
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLX)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(LIB_MLX)
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean_bonus:
	@rm -f $(OBJ_BONUS)

fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS)

tb1:
	@./$(NAME_BONUS) ./maps/maps_bonus/map1.ber
tb2:
	@./$(NAME_BONUS) ./maps/maps_bonus/map2.ber
tb3:
	@./$(NAME_BONUS) ./maps/maps_bonus/map3.ber
tb4:
	@./$(NAME_BONUS) ./maps/maps_bonus/map4.ber
tb5:
	@./$(NAME_BONUS) ./maps/maps_bonus/map5.ber
tb6:
	@./$(NAME_BONUS) ./maps/maps_bonus/map6.ber

re_bonus: fclean_bonus bonus

test_bonus: bonus
	@./$(NAME_BONUS) ./maps/map1.ber
############################## MLX42_BUILD_RULES ###############################
################################################################################
MLX = ./libmlx42.a -Iinclude -lglfw
$(LIB_MLX):
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42; cmake -B build; cmake --build build -j4
	mv MLX42/build/libmlx42.a ./
	mv MLX42/include/MLX42/MLX42.h ./
	rm -rf MLX42
clean_mlx:
	rm -rf MLX42
	rm MLX42.h
	rm libmlx42.a
############################### LIBFT_BUILD_RULES ##############################
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
################################# EXTRA_RULES ##################################
################################################################################
.PHONY: all clean fclean re start test libft re_libft clean_libft fclean_libft \
		mlx clean_mlx tb t re_bonus all_bonus clean_bonus fclean_bonus \
		re_bonus test_bonus
fcleanall: fclean fclean_libft fclean_bonus clean_mlx
