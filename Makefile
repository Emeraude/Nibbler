NAME		= 	nibbler

DIR		=	src

SRC		+=  	$(DIR)/main.cpp
SRC		+=  	$(DIR)/Snake.cpp
SRC		+=  	$(DIR)/Core.cpp
SRC		+=  	$(DIR)/DynamicLoader.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	+= 	-W -Wall -Wextra
CXXFLAGS	+= 	-I includes
CXXFLAGS	+= 	-I interfaces

LDXXFLAGS	+=	-ldl

RM		= 	rm -f

CC		= 	g++

%.o: %.cpp
		@$(CC) -c -o $@ $<  $(CXXFLAGS)
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | sed "s/ /./2g"

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LDXXFLAGS)
		@printf "\n"
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | sed "s/ /./5g"
		@printf "\n"

clean:
		@$(RM) $(OBJ)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | sed "s/ /./3g"
		@printf "\n"

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;35mdeleted\033[0m] % 30s\n" $(NAME) | sed "s/ /./3g"
		@printf "\n"

re:		fclean all

.PHONY:		all clean fclean re
