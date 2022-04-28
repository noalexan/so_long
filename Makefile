# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/04/28 14:29:09 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
OFLAGS	:= -Werror -Wextra -Wall -g
CFLAGS	:= -I /usr/X11/include -l mlx -framework OpenGL -framework AppKit

NAME	:= so_long

SRCS	:=	srcs/main.c \
			srcs/settings.c \
			srcs/game.c \
			srcs/nogui.c \
			srcs/ft_puts.c \
			srcs/ft_utils.c \
			srcs/map.c \
			srcs/menu.c \
			srcs/set_exit.c \
			srcs/print_map.c \
			srcs/animation.c \
			srcs/place_objects.c \
			srcs/get_next_line/get_next_line.c \
			srcs/get_next_line/get_next_line_utils.c \

OBJS	:= $(SRCS:.c=.o)

LIBS	:=	srcs/libft/libft.a \
			srcs/printf/printf.a \

RM		:= rm -rf
AR		:= ar rcs

GREEN	:= "\033[0;32m"
CYAN	:= "\033[0;36m"
YELLOW	:= "\033[0;33m"
RESET	:= "\033[0m"

.c.o: $(SRCS)
	@echo $(GREEN)"[Compiling objects... "$(YELLOW)"<$<>"$(GREEN)" ]"$(RESET)
	@$(CC) $(OFLAGS) -c $< -o $(<:.c=.o) -g

$(NAME): $(OBJS)
	@make -C srcs/libft
	@make -C srcs/printf
	@echo $(CYAN)"[Compiling '$(NAME)'...]"$(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I include/ -o $(NAME)

test_parser: fclean $(OBJS)
	@make -C srcs/libft
	@make -C srcs/printf
	@echo $(CYAN)"[Compiling parse test binary file...]"$(RESET)
	@$(CC) $(CFLAGS) $(subst srcs/main.o, test/test_parser.c, $(OBJS)) $(LIBS) -I include/ -o $(NAME) -g

all: $(NAME)

clean:
	@echo $(CYAN)"[Erasing objects...]"$(RESET)
	@$(RM) $(OBJS)
	@make -C srcs/libft fclean
	@make -C srcs/printf fclean

fclean: clean
	@echo $(CYAN)"[Erasing binary file...]"$(RESET)
	@$(RM) $(NAME) test_parser

re: fclean all

.PHONY: all clean fclean re
