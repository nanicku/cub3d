NAME	= cub3d
HEADER	= cub3d.h

CC		= cc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I.
OPTFLAGS = -O2

SRC		= main.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

LIBFT_OBJS	= $(LIBFT:%.c=%.o)
LIBFT_A		= libft/libft.a

.PHONY:	all clean fclean re libft

.o: .c $(HEADER)
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

all:	libft ${NAME}

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(OBJ) $(LIBFT_A) -o $@

libft:
	make -C libft
		
clean:
		@rm -f $(OBJ)
		make -C libft clean
		
fclean:	clean
		@rm -f ${NAME}
		rm -rf a.out*
		rm -rf */a.out*
		rm -rf *.gch
		rm -rf */*.gch
		rm -f libft/libft.a
		
re:		fclean all