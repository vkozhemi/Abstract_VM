NAME = avm

CC = g++
FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Parsing.cpp Factory.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

OBJ_DIR = ./objects/
SRC_DIR = ./srcs/

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@tput setaf 2; echo made

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@$(CC) -c $< -o $@ $(FLAGS)

clean:
	@rm -f $(OBJ)
	@tput setaf 4; echo cleaned

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@tput setaf 1; echo fcleaned

re: fclean all