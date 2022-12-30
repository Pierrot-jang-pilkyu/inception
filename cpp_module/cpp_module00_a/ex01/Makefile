NAME	=	phonebook
CLANG	=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic

SRCS	= 	./srcs/Contact.cpp \
			./srcs/PhoneBook.cpp \
			./srcs/main.cpp

OBJS	= $(SRCS:.cpp=.o)
RM		= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CLANG) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CLANG) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)
	@echo "Object files removed."

fclean : clean
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all clean fclean re