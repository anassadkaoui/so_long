# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 17:54:26 by asadkaou          #+#    #+#              #
#    Updated: 2025/01/12 19:27:12 by asadkaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_Xxp.c ft_id.c ft_u.c ft_s.c ft_c.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	ar -rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
