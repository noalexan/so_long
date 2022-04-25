# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/04/25 13:10:45 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Werror -Wextra -Wall

NAME	:= libft.a

SRCS	:=	ft_atoi.c \
			ft_calloc.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_toupper.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memcmp.c  \
			ft_memmove.c \
			ft_strchr.c \
			ft_strjoin.c \
			ft_strlcpy.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

OBJS	:= $(SRCS:.c=.o)

GREEN	:= "\033[0;32m"
CYAN	:= "\033[0;36m"
RESET	:= "\033[0m"

RM		:= rm -rf
AR		:= ar rcs

.c.o:
	@echo $(GREEN)"[Compiling libft... <$<> ]"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	@echo $(CYAN)"[Compiling '$(NAME)'...]"$(RESET)
	@$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	@echo $(CYAN)"[Erasing libft...]"$(RESET)
	@$(RM) $(OBJS)

fclean: clean
	@echo $(CYAN)"[Erasing $(NAME)...]"$(RESET)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
