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

NAME_G = generator

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
				  choose_map.c\
				  pic_structure.c

SRC_G	=		main.c\
				looper.c\
				lists.c\
				key_events.c\
				initer.c\
				genevent.c\
				commands.c\
				buttons.c\
				add_map.c\
				add_map2.c\
				add_map3.c\
				add_map4.c\
				other.c\
				alt_join.c\
				bb.c\
				second_onerow_funct.c\
				malloc_alt.c\
				onerow_funct.c\
				get_info.c\
				bucket.c\
				paint.c\
				text_param.c\
				ttf_param.c\
				load_param.c\
				lbox_operations.c\
				scan.c\
				this_generus.c\
				list_operations.c\
				key_params.c

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./includes/
HEADER			= $(addprefix $(INC_P), doomnukem.h)

# libft

LIB_P			= ./libft/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ./libft
LNK_LIB			= -L ./libft -l ft

# mlx

INC_MLX			= -I ./frameworks/SDL2.framework/Headers/ -I ./frameworks/SDL2_image.framework/Headers/ -I ./frameworks/SDL2_ttf.framework/Headers -I ./frameworks/SDL2_mixer.framework/Headers -F frameworks/
LNK_MLX			=  -framework SDL2 -framework SDL2_ttf -framework SDL2_mixer -framework SDL2_image -rpath frameworks


SRC_P_G 		= ./map_generator/src/
F_MAP_G			= ./generator
OBJ_G 			= $(addprefix $(OBJ_P_G),$(SRC_G:.c=.o))
OBJ_P_G			= ./map_generator/obj/
INC_G 			= $(addprefix -I, $(INC_P_G))
INC_P_G			= ./map_generator/inc/
HEADER_G		= $(addprefix $(INC_P_G), gen.h)

# compiler

CC 				= gcc -g -Wall -Wextra -Werror

all: obj $(ADD_LIB) $(NAME_G) $(NAME)

obj:
	mkdir -p $(OBJ_P) $(OBJ_P_G)

obj_g:
	mkdir -p $(OBJ_P_G)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	@$(CC)  $(INC_MLX) $(INC_LIB) -I $(INC_P) -o $@ -c $<
	@printf "Compiling $@\n"

$(OBJ_P_G)%.o:$(SRC_P_G)%.c $(HEADER_G)
	@$(CC)  $(INC_MLX) $(INC_LIB) -I $(INC_P) -o $@ -c $<
	@printf "Compiling $@\n"

$(ADD_LIB):
	@make -C $(LIB_P)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(INC_MLX) $(LNK_MLX) $(LNK_LIB) -lm -o $(NAME)
	@printf '\033[32m[ Done ] %s\n\033[0m'

$(NAME_G): $(OBJ_G)
	@$(CC) $(OBJ_G) $(INC_MLX) $(LNK_MLX) $(LNK_LIB) -lm -o $(NAME_G)

clean:
	@rm -rf $(OBJ_P)
	@rm -rf $(OBJ_P_G)
	@make -C $(LIB_P) clean
	@printf '\033[31m[ clean ] %s\n\033[0m'

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(F_MAP_G)
	@make -C $(LIB_P) fclean
	@printf '\033[31m[ fclean ] %s\n\033[0m'

re: fclean all

.PHONY: all clean fclean re
