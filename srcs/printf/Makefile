# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/04/23 12:44:59 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Werror -Wextra -Wall

NAME	:= objs/printf/printf.a

SRCS	:=	srcs/printf/ft_printf.c \
			srcs/printf/ft_printf_utils.c \

OBJS	:= $(SRCS:.c=.o)

RM		:= rm -rf
AR		:= ar rcs

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(subst srcs, objs, $(<:.c=.o)) -I.

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(subst srcs, objs, $(OBJS))

all: $(NAME)

clean:
	@$(RM) $(subst srcs, objs, $(OBJS))

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
