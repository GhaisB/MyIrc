NAME    =       client

NAME1   =       serveur

SRC     =       Client/src/main.c \
		Client/src/init.c \
		Client/src/tools.c \
		Client/src/graph.c \
		Client/src/handle.c \
		Client/src/buffer.c

SRC1    =       Serveur/src/server.c \
		Serveur/src/connection.c \
		Serveur/src/list.c \
		Serveur/src/command.c \
		Serveur/src/command_bis.c \
		Serveur/src/tool.c \
		Serveur/src/chan_func.c \
		Serveur/src/set_func.c

 OBJ     =       $(SRC:.c=.o)

OBJ1    =       $(SRC1:.c=.o)


CFLAGS  =       -g -W -Wall -Wextra -lpthread `pkg-config --cflags --libs gtk+-2.0`

LDFLAGS =	`pkg-config --cflags --libs gtk+-2.0`

all:            $(NAME) $(NAME1)

$(NAME):        $(OBJ)

	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAME1):       $(OBJ1)

	gcc -o $(NAME1) $(OBJ1)

clean:
	rm -f $(OBJ1) $(OBJ)

fclean: clean
	rm -f $(NAME1) $(NAME)

re:     fclean all
