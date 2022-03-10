NAME	= cub3d

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
OBJ = $(SRC:%.c=%.o)

LIBFT_OBJS	= $(LIBFT:%.c=%.o)

SRC		= src/ft_atoi.c \
		src/main.c \
		src/monit_dead.c \
		src/parser_init.c \
		src/philo_life.c \
		src/philo_time.c \
		src/start_philo.c \
		

.PHONY:	all clean fclean re libft

HEADER		= cub3d.h 

LIBFT_A		= libft/libft.a

.o: .c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

all:	${NAME}

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(OBJ) $(LIBFT_A) -o $@

libft:
	make -C libft
		
clean:
		rm -f ${OBJ}
		rm -f src_bonus/*.o
		
fclean:	clean
		rm -f ${NAME}
		rm -rf a.out*
		rm -rf */a.out*
		rm -rf *.gch
		rm -rf */*.gch
		
re:		fclean all