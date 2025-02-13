NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server:
	$(CC) $(CFLAGS) server.c $(SRC) -o server

client:
	$(CC) $(CFLAGS) client.c $(SRC) -o client

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f server client

re: fclean all