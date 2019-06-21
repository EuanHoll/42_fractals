# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: euan <ehollidg@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:51:09 by euan           #+#    #+#                 #
#    Updated: 2019/06/11 11:12:50 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main end hookcontrols plot drawmap loop mousemove mandelbrot julia \
		doubletocolour drawinfo colourswitcher burningship sierpinskic \
		sierpinskit fractalchanger tricorn startfractol crosses tentacle \
		transformhandler
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = fractol
MINILIBX = -I minilibxMAC -L minilibxMAC -lmlx -framework OpenGL -framework Appkit
MINILOC = minilibxMAC
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

ifeq ($(shell uname -s ), Linux)
MINILIBX = -pthread -I minilibxLINUX -L minilibxLINUX -lmlx -lXext -lX11 
MINILOC = minilibxLINUX
endif

COLOURMAKE = \033[38;5;69m
COLOURCLEAN = \033[38;5;159m
COLOURFCLEAN = \033[38;5;117m
COlOURLIB = \033[38;5;111m
COLOURRESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCF)
	@echo "$(COlOURLIB)Compiling Libaries$(COLOURRESET)"
	@make -C libft/
	@make -C $(MINILOC)/
	@echo "$(COLOURMAKE)Compiling Program$(COLOURRESET)"
	@clang $(FLAGS) -I $(MINILOC) -I libft/includes -c $(SRCF) -g
	@clang -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) -g

clean:
	@echo "$(COLOURCLEAN)Cleaning Libaries$(COLOURRESET)"
	@make -C libft/ clean
	@make -C $(MINILOC)/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "$(COLOURFCLEAN)Removing Libaries and $(NAME) $(COLOURRESET)"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
