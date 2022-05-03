# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/05/03 08:49:18 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
OFLAGS	:= -Werror -Wextra -Wall
CFLAGS	:= -I /usr/X11/include -l mlx -framework OpenGL -framework AppKit

NAME	:= so_long

SRCS	:=	srcs/map.c \
			srcs/main.c \
			srcs/menu.c \
			srcs/init.c \
			srcs/swap.c \
			srcs/game.c \
			srcs/nogui.c \
			srcs/ft_puts.c \
			srcs/ft_utils.c \
			srcs/settings.c \
			srcs/set_exit.c \
			srcs/ennemies.c \
			srcs/print_map.c \
			srcs/animation.c \
			srcs/parse_wall.c \
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

DIR		:= "\"$(shell pwd)/\""

.c.o: $(SRCS)
	@echo $(GREEN)"[Compiling objects... "$(YELLOW)"<$<>"$(GREEN)" ]"$(RESET)
	@$(CC) $(OFLAGS) -D DIR=$(DIR) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make -C srcs/libft
	@make -C srcs/printf
	@echo $(CYAN)"[Compiling '$(NAME)'...]"$(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I include/ -o $(NAME)

bonus:
	@make -f bonus

test_parser: fclean $(OBJS)
	@make -C srcs/libft
	@make -C srcs/printf
	@echo $(CYAN)"[Compiling parse test binary file...]"$(RESET)
	@$(CC) $(CFLAGS) $(subst srcs/main.o, test/test_parser.c, $(OBJS)) $(LIBS) -I include/ -o $(NAME)

all: $(NAME)

clean:
	@echo $(CYAN)"[Erasing objects...]"$(RESET)
	@$(RM) $(OBJS)
	@make -C srcs/libft fclean
	@make -C srcs/printf fclean

clean_bonus:
	@echo $(CYAN)"[Erasing bonus...]"$(RESET)
	@make -f bonus clean

fclean: clean
	@echo $(CYAN)"[Erasing binary file...]"$(RESET)
	@$(RM) $(NAME) test_parser

fclean_bonus: clean_bonus
	@echo $(CYAN)"[Force erasing bonus...]"$(RESET)
	@make -f bonus clean

clean_all: clean clean_bonus

fclean_all: fclean fclean_bonus

re: fclean all

re_bonus: fclean_bonus bonus

norm:
	@norminette -R CheckForbiddenSourceHeader -R CheckDefine

.PHONY: all clean fclean re bonus
