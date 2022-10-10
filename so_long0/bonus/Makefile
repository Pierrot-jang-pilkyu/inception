# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2022/10/10 17:39:54 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long_bonus
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	-L ../libft/ -lft -L ../mlx/ -lmlx -framework OpenGL -framework AppKit
MLX		=	../mlx/libmlx.a
LFT		=	../libft/libft.a
SRCS	= 	ft_mlx_img_bonus.c \
			game_clear_bonus.c \
			game_fail_bonus.c \
			game_close_bonus.c \
			get_linelen_bonus.c \
			get_map_bonus.c \
			get_player_position_bonus.c \
			inits_bonus.c \
			keypress_bonus.c \
			main_bonus.c \
			map_check_bonus.c \
			map_regen_bonus.c \
			move_bonus.c \
			put_error_bonus.c 

OBJS	= $(SRCS:.c=.o)
RM		= rm -f

all : $(MLX) $(LFT) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)

$(MLX) : 
	@make -s -C ../mlx
	@echo "MLX Success."

$(LFT) :
	@make -s bonus -C ../libft
	@echo "Libft Success."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -s $@ -C ../mlx
	@make -s $@ -C ../libft
	$(RM) $(OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C ../libft
	@make -s $@ -C ../mlx
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all clean fclean re