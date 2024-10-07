RM	=	rm -rf

CC	=	g++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I ./inc
DEBUG	=	-g3 -fsanitize=address

NAME	=	iter

SRC	=	main.cpp
SRC_DIR	=	src/

OBJ_DIR	=	./obj/
OBJ_FILES	=	$(SRC:.cpp=.o)
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

##########COLORES##########
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

##########REGLAS##########
all: $(OBJ_DIR) $(NAME)
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(G)Program compiled!$(DEF_COLOR)-> $@\n"

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_DIR)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)
	@echo "$(R)OBJ directory removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
