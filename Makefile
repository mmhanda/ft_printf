# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 09:20:31 by mhanda            #+#    #+#              #
#    Updated: 2021/12/14 15:07:10 by mhanda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c	\
	   ft_printhex.c	\
	   ft_printhex_check.c	\
	   ft_putchar.c		\
	   ft_putnbr.c		\
	   ft_putnbr_usit.c		\
	   ft_putstr.c

OBJS = $(SRCS:.c=.o)

RM			= rm -f
CFLAGS		= cc -Wall -Wextra -Werror
NAME		= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:%.c ft_printf.h
	${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
