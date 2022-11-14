# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <pjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2022/11/14 09:33:34 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

SRCS	= 	./srcs/put_error.c \
			./srcs/philo_status.c \
			./srcs/ft_atoi.c \
			./srcs/init.c \
			./srcs/philo.c \
			./srcs/main.c \
			./srcs/utility.c \
			./srcs/utility2.c \
			./srcs/parsing.c \

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

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	@echo "Object files removed."

fclean : clean
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all bonus clean fclean re