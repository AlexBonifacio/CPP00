
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

SRCS = main.cpp contact.cpp phonebook.cpp
OBJS = $(patsubst %.cpp,obj/%.o,$(SRCS))
OBJ_DIR = obj

NAME = phonebook

all: $(NAME)

$(NAME) : $(OBJS) Makefile
	$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re tidy

