# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <pjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2022/10/18 06:37:39 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

LIBC	=	-L ./libft/ -lft
LFT		=	libft/libft.a
SRCS	= 	./srcs/execute.c\
			./srcs/init.c \
			./srcs/main.c \
			./srcs/parsing.c \
			./srcs/pipex.c \
			./srcs/put_error.c \
			./srcs/redirection.c \
			./srcs/safety_free.c \
			./srcs/valid.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f

all : $(LFT) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)

$(LFT) :
	@make -s bonus -C libft
	@echo "Libft Success."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -s $@ -C libft
	$(RM) $(OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C libft
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all clean fclean re