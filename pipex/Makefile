# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <pjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2022/11/07 21:23:02 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

LIBC	=	-L ./libft/ -lft
LFT		=	libft/libft.a
SRCS	= 	./srcs/execute.c \
			./srcs/arg_devide.c \
			./srcs/init.c \
			./srcs/init_2.c \
			./srcs/main.c \
			./srcs/parsing.c \
			./srcs/pipex.c \
			./srcs/put_error.c \
			./srcs/redirection.c \
			./srcs/safety_free.c \
			./srcs/valid.c

B_SRCS	= 	./bonus/execute_bonus.c \
			./bonus/arg_devide_bonus.c \
			./bonus/here_doc_bonus.c \
			./bonus/init_bonus.c \
			./bonus/init_2_bonus.c \
			./bonus/main_bonus.c \
			./bonus/parsing_bonus.c \
			./bonus/pipex_bonus.c \
			./bonus/put_error_bonus.c \
			./bonus/redirection_bonus.c \
			./bonus/safety_free_bonus.c \
			./bonus/valid_bonus.c

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)
RM		= rm -f

ifdef WITH_BONUS
OBJ_FILES = $(B_OBJS)
else
OBJ_FILES = $(OBJS)
endif

all : $(LFT) $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)

$(LFT) :
	@make -s bonus -C libft
	@echo "Libft Success."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	@make -s $@ -C libft
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C libft
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all bonus clean fclean re