NAME = generator

# srcs, path and obj

SRC_N	=		main.c\
				looper.c\
				lists.c\
				key_events.c\
				initer.c\
				genevent.c\
				commands.c\
				buttons.c\
				add_map.c\
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
				load_param.c

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./inc/
HEADER			= $(addprefix $(INC_P), gen.h)

# libft

LIB_P			= ./libft/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ./libft
LNK_LIB			= -L ./libft -l ft

# mlx

INC_MLX			= -I ./frameworks/SDL2.framework/Headers/ -I ./frameworks/SDL2_image.framework/Headers/ -I ./frameworks/SDL2_ttf.framework/Headers -I ./frameworks/SDL2_mixer.framework/Headers -F frameworks/
LNK_MLX			=  -framework SDL2 -framework SDL2_ttf -framework SDL2_mixer -framework SDL2_image -rpath frameworks

# compiler

CC 				= gcc -Wall -Wextra -Werror

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
