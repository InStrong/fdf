# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasajj <sasajj@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 21:09:54 by sasajj            #+#    #+#              #
#    Updated: 2020/02/17 21:20:00 by sasajj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
INCLUDES := includes/ 
CC := gcc

SRC_PATH := src/
FILES := main.c draw.c read_file.c
SRC := $(patsubst %, $(SRC_PATH)%, $(FILES))
OBJ := $(patsubst %.c, %.o, $(FILES))

LIB_FLAG := -Llibft -lft
MLX_FLAGS := -lmlx -framework OpenGL -framework AppKit
CFLAGS := -Wall -Werror -Wextra
.PHONY: all clean fclean re

all: $(NAME)

%.o : $(SRC_PATH)%.c includes/fdf.h
	@$(CC) -c $(CFLAGS) -I$(INCLUDES) $< -o $@
	@echo $(patsubst src/%.c, %, $<)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(LIB_FLAG) $(CFLAGS) $(MLX_FLAGS) $(OBJ)
	@echo "Done"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)