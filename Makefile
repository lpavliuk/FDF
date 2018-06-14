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
SRC=./fdfsrc/atoi_base_16.c \
	./fdfsrc/validation.c \
	./fdfsrc/work_with_net.c \
	./fdfsrc/work_with_coord.c \
	./fdfsrc/key_hook.c \
	./fdfsrc/main.c 
	
OBJ=$(SRC:.c=.o)
LIB = libft/libft.a
NAME=fdf

all: $(NAME)

%.o: %.c
	@ $(CC) $(CFLAGS) -o $@ -c $< -I ./

$(NAME): $(LIB) $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIB) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I /usr/local/include 
	@ printf "\e[37;1m[Program \e[34;1mfdf \e[37;1mis \e[32;1mREADY TO SHOW!\e[37;1m]\e[0m🎅🏾🤙🏾🥃\n"

$(LIB):
	@ printf "\e[32;1mCompiling libft.a ...\n"
	@ make -C libft/
	@ printf "\n\e[32;1mCompiling fdf ...\n"

clean:
	@ rm -f $(OBJ)
	@ make clean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mfdfsrc/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mCLEAN!\e[37;1m]\e[0m🗑\n"

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mfdf/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mFCLEAN!\e[37;1m]\e[0m🗑\n"

re: fclean all

.PHONY: all, clean, fclean, re
