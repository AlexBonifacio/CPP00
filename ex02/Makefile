
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = Account.cpp tests.cpp
OBJ_DIR = obj
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

NAME = Account

all: $(NAME)

$(NAME) : $(OBJS) Makefile
	$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re