LIB_H   = ./includes
SRC_DIR = ./srcs
OBJ_DIR = ./obj

NAME    = libft.a

SRC     = $(shell find $(SRC_DIR) -name '*.c')
OBJ     = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:%.c=%.o))
DIRS  	= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(shell find $(SRC_DIR) -type d))

CC      = gcc
FLAGS   = -Wall -Wextra -Werror
INC     = -I $(LIB_H)

all: $(NAME)

$(NAME): $(DIRS) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo Library Libft created.

$(DIRS):
	@mkdir -p $(DIRS)

$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) 
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(DIRS)
	@echo Libft Object Files deleted.

fclean: clean
	rm -f $(NAME)
	@echo Libft Library deleted.

re: fclean all
