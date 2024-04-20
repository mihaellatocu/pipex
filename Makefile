NAME = pipex
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
OBJ_DIR = obj

SOURCES = \
		main.c processes.c utils.c ft_split.c

#OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
OBJECTS = $(SOURCES:.c=.o)

DEPS=pipex.h

all: $(NAME)
$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@
	
# $(CC) $(FLAGS) $(OBJECTS:%=$(OBJ_DIR)/%) -o $@

#$(OBJ_DIR)/%.o:%.c
%.o:%.c
#@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re