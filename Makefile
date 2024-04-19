NAME = pipex
SOURCES = \
		main.c processes.c utils.c ft_split.c

OBJECTS = $(SOURCES:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror
DEPS=pipex.h

all: $(NAME)
$(NAME) : $(OBJECTS)

obj/%.o:%.c
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) 

clean:
	rm -rf $(OBJECTS)