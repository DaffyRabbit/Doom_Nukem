# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arykov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 00:12:27 by arykov            #+#    #+#              #
#    Updated: 2018/10/31 18:17:29 by arykov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

# srcs, path and obj

SRC_N			= main.c\
				  exit.c\
				  game_start.c\
				  keys_param.c\
				  checker.c\
				  map_checker.c\
				  bonus.c\
				  painting.c\
				  tiray.c\
				  wallandfl.c\
				  mouse_control.c\
				  hud.c\
				  hud_changing.c\
				  hud_painting.c\
				  hud_param.c\
				  hud_animations.c\
				  ft_freee.c\
				  music.c\
				  dead.c\
				  sprite.c\
				  sprite_sort.c\
				  do_sprite.c\
				  error.c\
				  pic_loaders.c\
				  menu_map_add.c\
				  load_maps.c\
				  health_n_doors_messages.c\
				  walking.c\
				  swap_n_add_sprite.c\
				  floor_n_ceiling.c\
				  skydome_n_intens.c\
				  render_text.c\
				  apply_surface.c\
				  game_loop.c\
				  choose_map.c

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./includes/
HEADER			= $(addprefix $(INC_P), wolf3d.h)

# libft

LIB_P			= ./libft/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ./libft
LNK_LIB			= -L ./libft -l ft

# mlx

INC_MLX			= -I ./frameworks/SDL2.framework/Headers/ -I ./frameworks/SDL2_image.framework/Headers/ -I ./frameworks/SDL2_ttf.framework/Headers -I ./frameworks/SDL2_mixer.framework/Headers -F frameworks/
LNK_MLX			=  -framework SDL2 -framework SDL2_ttf -framework SDL2_mixer -framework SDL2_image -rpath frameworks

# compiler

CC 				= gcc -g -Wall -Wextra -Werror

all: obj $(ADD_LIB) $(NAME)

obj:
	mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	@$(CC)  $(INC_MLX) $(INC_LIB) -I $(INC_P) -o $@ -c $<
	@printf "Compiling $@\n"

$(ADD_LIB):
	@make -C $(LIB_P)



$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(INC_MLX) $(LNK_MLX) $(LNK_LIB) -lm -o $(NAME)
	@printf '\033[32m[ Done ] %s\n\033[0m'

clean:
	@rm -rf $(OBJ_P)
	@make -C $(LIB_P) clean
	@printf '\033[31m[ clean ] %s\n\033[0m'

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB_P) fclean
	@printf '\033[31m[ fclean ] %s\n\033[0m'

re: fclean all

.PHONY: all clean fclean re
