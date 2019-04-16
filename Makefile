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

NAME = wolf3d

# srcs, path and obj

SRC_N			= main.c\
				  exit.c\
				  game_start.c\
				  mouse_param.c\
				  keys_param.c\
				  checker.c\
				  map_checker.c\
				  bonus.c\
				  painting.c\
				  tiray.c\
				  wallandfl.c\
				  mouse_control.c\
				  HUD.c

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

INC_MLX			= -I ./frameworks/SDL2.framework/Headers/ -I ./frameworks/SDL2_image.framework/Headers/ -F ./frameworks/  
LNK_MLX			=  -framework SDL2  -rpath frameworks  -L ./frameworks/SDL2_image.framework/Headers/  -framework SDL2_image
# compiler

CC 				= gcc -g  -Wall -Wextra -Werror

all: obj $(ADD_LIB) $(NAME)

obj:
	mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	@$(CC)  $(INC_MLX) $(INC_LIB) -I $(INC_P) -o $@ -c $<
	@printf "Compiling $@\n"

$(ADD_LIB):
	@make -C $(LIB_P)



$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(INC_MLX) $(LNK_MLX) $(LNK_LIB)  -lm -o $(NAME)  
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
