SRCDIR = src
OBJDIR = points_o

SRCS = parsing_carte.c \
	utils.c \
	verif_chemin.c \
	main.c \
	mouvements.c \
	utils_mouvements.c \
	fenetre.c \
	creation_map.c

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

NAME = so_long

MINILIB = minilibx-linux/libmlx_Linux.a

FT_PRINTF = Libft_clone/ft_printf/libftprintf.a

LIBFT = Libft_clone/libft.a

all : $(NAME)

$(NAME): $(OBJS) | $(OBJDIR)
	make -C Libft_clone
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(MINILIB) $(FT_PRINTF) $(LIBFT) -lXext -lX11 -o $@
	clear
	@echo "🧚 tout est prêt 🧚"

$(OBJDIR)/%.o:%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean :
	make clean -C Libft_clone
	make clean -C minilibx-linux
	rm -rf $(OBJDIR)

fclean : clean
	make fclean -C Libft_clone
	rm -f $(NAME)
	clear
	@echo "🧚 tout propre 🧚"

git : fclean
	git add *
	git commit
	git push

re : fclean all

.PHONY : all clean fclean re git

.SILENT : all clean fclean re git $(NAME) $(OBJDIR)
