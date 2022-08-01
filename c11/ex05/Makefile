CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op 
SRCS = ./srcs/main.c ./srcs/math.c ./srcs/utils.c

$(NAME) : $(SRCS) 
	$(CC) $(CFLAGS) $^ -I./includes -o $@

all : $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
