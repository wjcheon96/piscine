# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 20:44:04 by yeongo            #+#    #+#              #
#    Updated: 2022/05/04 21:19:18 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = bsq

SRC_DIR = srcs
INC_DIR = includes

SRCS = $(SRC_DIR)/main.c	\
	   $(SRC_DIR)/tool.c	\
	   $(SRC_DIR)/map.c		\
	   $(SRC_DIR)/init.c
OBJS = $(SRCS:.c=.o)

%.c : %.o
	$(CC) $(CFLAGS) -c $@ -o $< -I $(INC_DIR)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
