# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasajj <sasajj@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 18:40:39 by egiles            #+#    #+#              #
#    Updated: 2020/02/17 21:04:48 by sasajj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_count_words.c ft_skip_ws.c ft_nbrlen.c ft_lstnew.c ft_lstdelone.c \
ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sqrt.c ft_swap.c get_next_line.c

OBJCTS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
HDRS = libft.h

all: $(NAME)

%.o: %.c $(HDRS)
	gcc $(FLAGS) -c $< $(HDRS)

$(NAME): $(OBJCTS)
	ar rc $(NAME) $(OBJCTS)
	ranlib $(NAME)

.PHONY : all clean fclean re

clean:
	/bin/rm -f $(OBJCTS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
