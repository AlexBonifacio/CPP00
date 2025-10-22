
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp mapb.cpp mapb.hpp
OBJS = (patsubst %.cpp,obj/%.o,SRCS)
OBJ_DIR = obj

NAME = mapb

all: $(NAME)

$(NAME) : $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

