SRCS = main.c \
	parsing_carte.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g 

NAME = so_long

MINILIB = minilibx-linux/libmlx_Linux.a

FT_PRINTF = Libft_clone/ft_printf/libftprintf.a

LIBFT = Libft_clone/libft.a

all : $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C Libft_clone
	make -C minilibx-linux
	$(CC) ${CFLAGS} $(OBJS) $(MINILIB) $(FT_PRINTF) $(LIBFT)  -lXext -lX11 -o $(NAME)

clean :
	make clean -C Libft_clone
	make clean -C minilibx-linux
	rm -f *.o

fclean : clean
	make fclean -C Libft_clone
	rm -f $(NAME)

git : fclean
	git add *
	git commit
	git push

re : fclean all

.PHONY : all clean fclean re git