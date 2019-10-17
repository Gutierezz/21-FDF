NAME = fdf

SRC_DIR 	= ./srcs
OBJ_DIR 	= ./obj
LIB_DIR 	= ./libft
MLX_DIR 	= ../mlx_test

LIB 		= $(LIB_DIR)/libft.a

FLAGS 		= -Wall -Wextra -Werror
LIB_LINK	= -lm -L $(LIB_DIR) -lft
MLX_LINK 	= -L $(MLX_DIR) -lmlx -lXext -lX11 #-framework OpenGL -framework AppKit

SRC_FILES 	= main.c draw_map.c image_functions.c structs_init.c structs_clear.c pointlist.c parser.c projection.c rotation.c hook_commands.c key_commands.c \
			 palette_gradient.c

OBJ_FILES 	= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:%.c=%.o))

CC		  	= gcc
INC		  	= -I $(LIB_DIR)/includes -I includes -I $(MLX_DIR)

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(OBJ_FILES)
	@echo -n "EXE COMPILING!"
	$(CC) $(FLAGS) $(INC) $(OBJ_FILES) -o $(NAME) $(LIB_LINK) $(MLX_LINK)

$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
