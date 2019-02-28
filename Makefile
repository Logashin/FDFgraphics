NAME = fdf

SRC = main.c \
	scanmap.c \
	valmap.c \
	trash.c  \
	graphic.c \
	funbres.c \
	button.c \
	graphic2.c \
	button2.c \

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	gcc -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME) -L minilibx/ -lmlx -framework OpenGL -framework AppKit

clean: 
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f fdf

re: fclean all
