# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/04/25 08:56:13 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Werror -Wextra -Wall

NAME	:= objs/printf/printf.a

SRCS	:=	srcs/printf/ft_printf.c \
			srcs/printf/ft_printf_utils.c \

OBJS	:= $(SRCS:.c=.o)

GREEN	:= "\033[0;32m"
CYAN	:= "\033[0;36m"
RESET	:= "\033[0m"

RM		:= rm -rf
AR		:= ar rcs

.c.o:
	@echo $(GREEN)"[Compiling printf... <$<> ]"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $(subst srcs, objs, $(<:.c=.o)) -I.

$(NAME): $(OBJS)
	@echo $(GREEN)"[Compiling printf.a...]"$(RESET)
	@$(AR) $(NAME) $(subst srcs, objs, $(OBJS))

all: $(NAME)

clean:
	@echo $(CYAN)"[Erasing printf...]"$(RESET)
	@$(RM) $(subst srcs, objs, $(OBJS))

fclean: clean
	@echo $(CYAN)"[Erasing $(NAME)...]"$(RESET)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
