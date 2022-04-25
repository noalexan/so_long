# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/04/25 08:55:39 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Werror -Wextra -Wall

NAME	:= objs/libft/libft.a

SRCS	:=	srcs/libft/ft_atoi.c \
			srcs/libft/ft_calloc.c \
			srcs/libft/ft_isalpha.c \
			srcs/libft/ft_isdigit.c \
			srcs/libft/ft_memchr.c \
			srcs/libft/ft_memcpy.c \
			srcs/libft/ft_memset.c \
			srcs/libft/ft_strdup.c \
			srcs/libft/ft_strlcat.c \
			srcs/libft/ft_strlen.c \
			srcs/libft/ft_strnstr.c \
			srcs/libft/ft_substr.c \
			srcs/libft/ft_toupper.c \
			srcs/libft/ft_bzero.c \
			srcs/libft/ft_isalnum.c \
			srcs/libft/ft_isascii.c \
			srcs/libft/ft_isprint.c \
			srcs/libft/ft_memcmp.c  \
			srcs/libft/ft_memmove.c \
			srcs/libft/ft_strchr.c \
			srcs/libft/ft_strjoin.c \
			srcs/libft/ft_strlcpy.c \
			srcs/libft/ft_strncmp.c \
			srcs/libft/ft_strrchr.c \
			srcs/libft/ft_tolower.c \
			srcs/libft/ft_strtrim.c \
			srcs/libft/ft_split.c \
			srcs/libft/ft_itoa.c \
			srcs/libft/ft_strmapi.c \
			srcs/libft/ft_striteri.c \
			srcs/libft/ft_putchar_fd.c \
			srcs/libft/ft_putstr_fd.c \
			srcs/libft/ft_putendl_fd.c \
			srcs/libft/ft_putnbr_fd.c \

OBJS	:= $(SRCS:.c=.o)

GREEN	:= "\033[0;32m"
CYAN	:= "\033[0;36m"
RESET	:= "\033[0m"

RM		:= rm -rf
AR		:= ar rcs

.c.o:
	@echo $(GREEN)"[Compiling libft... <$<> ]"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $(subst srcs, objs, $(<:.c=.o)) -I.

$(NAME): $(OBJS)
	@echo $(GREEN)"[Compiling libft.a...]"$(RESET)
	@$(AR) $(NAME) $(subst srcs, objs, $(OBJS))

all: $(NAME)

clean:
	@echo $(CYAN)"[Erasing libft...]"$(RESET)
	@$(RM) $(subst srcs, objs, $(OBJS))

fclean: clean
	@echo $(CYAN)"[Erasing $(NAME)...]"$(RESET)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
