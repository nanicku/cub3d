NAME	= cub3d
HEADER	= cub3d.h

CC		= cc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I. -Imlx -Ilibft
OPTFLAGS = -O2

SRC		= main.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

.PHONY:	all clean fclean re libft mlx

.o: .c $(HEADER)
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

all:	mlx libft ${NAME}

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(OBJ) -Llibft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

mlx:
	make -C mlx/

libft:
	make -C libft/

clean:
		@rm -f $(OBJ)
		make -C libft/ clean
		make -C mlx/ clean
		
fclean:	clean
		@rm -f ${NAME}
		rm -f libft/libft.a
		rm -f mlx/libmlx.a
		rm -rf a.out*
		rm -rf */a.out*
		rm -rf *.gch
		rm -rf */*.gch
		
re:		fclean all
