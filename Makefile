# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/04/22 12:37:31 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Werror -Wextra -Wall -I /usr/X11/include -l mlx -framework OpenGL -framework AppKit

NAME	:= so_long

SRCS	:=	srcs/main.c \
			srcs/ft_puts.c \

OBJS	:= $(SRCS:.c=.o)

RM		:= rm -rf
AR		:= ar rcs

GREEN	:= "\033[0;32m"
CYAN	:= "\033[0;36m"
RESET	:= "\033[0m"

.c.o: $(SRCS)
	@echo $(GREEN)"[Compiling objects... <$<> ]"$(RESET)
	@$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@echo $(GREEN)"[Compiling binary file...]"$(RESET)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@echo $(CYAN)"[Erasing objects...]"$(RESET)
	@$(RM) $(OBJS)

fclean: clean
	@echo $(CYAN)"[Erasing binary file...]"$(RESET)
	@$(RM) $(NAME) bonus

re: fclean all

.PHONY: all clean fclean re
