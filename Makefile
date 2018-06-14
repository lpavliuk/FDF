# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 16:04:15 by opavliuk          #+#    #+#              #
#    Updated: 2018/06/08 13:37:57 by opavliuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CFLAGS=-Wall -Werror -Wextra
SRC=./leminsrc/algorithm.c \
	./leminsrc/validations.c \
	./leminsrc/work_with_list.c \
	./leminsrc/room_and_link.c \
	./leminsrc/write_road.c \
	./leminsrc/show_road.c \
	./leminsrc/main.c \
	./leminsrc/bonus.c
	
OBJ=$(SRC:.c=.o)
LIB = libft/libft.a
NAME=lem-in

all: $(NAME)

%.o: %.c
	@ $(CC) $(CFLAGS) -o $@ -c $< -I ./

$(NAME): $(LIB) $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@ printf "\e[37;1m[Program \e[34;1mlem-in \e[37;1mis \e[32;1mREADY!\e[37;1m]\e[0m🎅🏾🤙🏾🥃\n\n"
	@ ./lem-in --usage

$(LIB):
	@ printf "\e[32;1mCompiling libft.a ...\n"
	@ make -C libft/
	@ printf "\n\e[32;1mCompiling lem-in ...\n"

clean:
	@ rm -f $(OBJ)
	@ make clean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mleminsrc/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mCLEAN!\e[37;1m]\e[0m🗑\n"

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mlem-in/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mFCLEAN!\e[37;1m]\e[0m🗑\n"

re: fclean all

.PHONY: all, clean, fclean, re
