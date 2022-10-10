# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2022/10/10 19:33:35 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	-L ./libft/ -lft -L ./mlx/ -lmlx -framework OpenGL -framework AppKit
MLX		=	mlx/libmlx.a
LFT		=	libft/libft.a
SRCS	= 	./src/ft_mlx_img.c \
			./src/game_clear.c \
			./src/game_close.c \
			./src/get_linelen.c \
			./src/get_map.c \
			./src/get_player_position.c \
			./src/inits.c \
			./src/keypress.c \
			./src/main.c \
			./src/map_check.c \
			./src/map_regen.c \
			./src/move.c \
			./src/put_error.c 

B_SRCS	= 	./bonus/ft_mlx_img_bonus.c \
			./bonus/game_clear_bonus.c \
			./bonus/game_fail_bonus.c \
			./bonus/game_close_bonus.c \
			./bonus/get_linelen_bonus.c \
			./bonus/get_map_bonus.c \
			./bonus/get_player_position_bonus.c \
			./bonus/inits_bonus.c \
			./bonus/keypress_bonus.c \
			./bonus/main_bonus.c \
			./bonus/map_check_bonus.c \
			./bonus/map_regen_bonus.c \
			./bonus/move_bonus.c \
			./bonus/put_error_bonus.c 

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

BONUS	= $(NAME)

ifdef WITH_BONUS
OBJS_FILES	= $(B_OBJS)
else
OBJS_FILES	= $(OBJS)
endif

all : $(MLX) $(LFT) $(NAME)

$(NAME) : $(OBJS_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)

$(MLX) : 
	@make -s -C mlx
	@echo "MLX Success."

$(LFT) :
	@make -s bonus -C libft
	@echo "Libft Success."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	@make -s $@ -C mlx
	@make -s $@ -C libft
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C libft
	@make -s $@ -C mlx
	@rm -f $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all bonus clean fclean re