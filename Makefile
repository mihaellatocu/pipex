NAME = pipex
CC=cc
FLAGS=-Wall -Wextra -Werror -g
OBJ_DIR = obj
SRC_DIR = src

SOURCES = main.c processes.c utils.c ft_split.c
#SRC_PATH = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJECTS =  $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))


all: $(NAME)
$(NAME) : $(OBJECTS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "==== $(GREEN)$(NAME) created!$(DEFAULT) ===="
	
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(NAME) has been removed$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

#Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
DEFAULT = \033[0m