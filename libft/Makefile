# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ehollidg <ehollidg@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/21 14:51:46 by ehollidg       #+#    #+#                 #
#    Updated: 2019/06/07 13:12:12 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = atoi bzero isalnum isalpha isascii isdigit isprint itoa memalloc memccpy \
	  memchr memcmp memcpy memdel memrchr memset putchar_fd putchar \
	  putendl_fd putendl putnbr_fd putnbr putstr_fd putstr strcat strchr strclr \
	  strcmp strcpy strdel strdup strlcat strlen strncat strncmp strncpy strnew \
	  strnstr strrchr strrev strstr tolower toupper skipwhitespace toabs \
	  memmove striter striteri strjoin iswhitespace strtrim strcc strsplit \
	  strskip strmap strmapi strnequ strequ strsub lstnew lstadd lstdel lstiter \
	  lstcpyelm lstdelone lstmap strcontains lstcnt min max floor ceil realloc \
	  strtail strtailf strfroc strjoinf strextend struntil get_next_line \
	  strgetoc
SRCF = $(SRC:%=ft_%.c)
OBJ = $(SRCF:%.c=%.o)
NAME = libft.a

all: $(NAME)

$(NAME):
	@echo "Compiling $(NAME)"
	@gcc -Wall -Werror -Wextra -c $(SRCF) -g -I ./includes
	@ar -rcsv $(NAME) $(OBJ)
	@echo "Compilied $(NAME)"

clean:
	@echo "Cleaning"
	@rm -f $(OBJ) ./includes/libft.gch
	@echo "Finished"

mclean: $(NAME) clean

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@echo "Finished"

re: fclean all
