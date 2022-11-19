# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <pjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 02:21:12 by pjang             #+#    #+#              #
#    Updated: 2022/11/19 14:40:11 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

READLINE_PATH = /Users/pjang/.brew/Cellar/readline/8.2.1
READLINE_LIB = -L$(READLINE_PATH)/lib -lreadline

LIBC	=	-L ./libft/ -lft
LFT		=	libft/libft.a
SRCS	= 	./srcs/main.c \
			./srcs/utils/init.c \
			./srcs/utils/ft_pow.c \
			./srcs/utils/put_error.c \
			./srcs/utils/safety_free.c \
			./srcs/parsing/parsing.c \
			./srcs/parsing/divide_quote.c \
			./srcs/parsing/divide_pts.c \
			./srcs/parsing/divide_logical.c \
			./srcs/parsing/divide_pipe.c \
			./srcs/parsing/divide_redirection.c \
			./srcs/parsing/is_seq.c \
			./srcs/parsing/run_cmd.c \
			./srcs/parsing/is_builtin.c \
			./srcs/parsing/token.c \
			./srcs/parsing/tree.c \
			./srcs/parsing/in_tree.c \

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
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC) $(READLINE_LIB)

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