NAME	= account
CPP		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic

SRCS	= 	./Account.cpp \
			./test.cpp

OBJS = $(SRCS:.cpp=.o)

RM		= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
	@echo "Object files removed."

fclean : clean
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all bonus clean fclean re