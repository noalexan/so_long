# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/04/23 17:08:00 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Werror -Wextra -Wall -I /usr/X11/include -l mlx -framework OpenGL -framework AppKit

NAME	:= so_long

SRCS	:=	srcs/main.c \
			srcs/ft_puts.c \
			srcs/ft_utils.c \
			srcs/map.c \
			srcs/get_next_line/get_next_line.c \
			srcs/get_next_line/get_next_line_utils.c \

OBJS	:= $(SRCS:.c=.o)

LIBS	:=	objs/libft/libft.a \
			objs/printf/printf.a \

RM		:= rm -rf
AR		:= ar rcs

GREEN	:= "\033[0;32m"
CYAN	:= "\033[0;36m"
RESET	:= "\033[0m"

.c.o: $(SRCS)
	@echo $(GREEN)"[Compiling objects... <$<> ]"$(RESET)
	@$(CC) -c $< -o $(subst srcs, objs, $(<:.c=.o))

$(NAME): $(OBJS)
	@echo $(GREEN)"[Compiling libft...]"$(RESET)
	@make -f srcs/libft/Makefile
	@echo $(GREEN)"[Compiling printf...]"$(RESET)
	@make -f srcs/printf/Makefile
	@echo $(GREEN)"[Compiling binary file...]"$(RESET)
	@$(CC) $(CFLAGS) $(subst srcs, objs, $(OBJS)) $(LIBS) -o $(NAME)

all: $(NAME)

test_parser: fclean $(OBJS)
	@echo $(GREEN)"[Compiling libft...]"$(RESET)
	@make -f srcs/libft/Makefile
	@echo $(GREEN)"[Compiling printf...]"$(RESET)
	@make -f srcs/printf/Makefile
	@echo $(GREEN)"[Compiling parse test binary file...]"$(RESET)
	@$(CC) $(CFLAGS) $(subst objs/main.o, test/test_parser.c, $(subst srcs, objs, $(OBJS))) $(LIBS) -o $(NAME)

clean:
	@echo $(CYAN)"[Erasing objects...]"$(RESET)
	@$(RM) $(subst srcs, objs, $(OBJS))
	@echo $(CYAN)"[Erasing libft...]"$(RESET)
	@make -f srcs/libft/Makefile fclean
	@echo $(CYAN)"[Erasing printf...]"$(RESET)
	@make -f srcs/printf/Makefile fclean

fclean: clean
	@echo $(CYAN)"[Erasing binary file...]"$(RESET)
	@$(RM) $(NAME) test_parser

re: fclean all

.PHONY: all clean fclean re
