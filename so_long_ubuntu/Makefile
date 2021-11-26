NAME = so_long

SRC = 	main.c\
		program_init.c\
	 	map_check.c\
		map_check_utils.c\
		map_set.c\
		set_textures.c\
		mlx_functions.c\
		movements_a.c\
		movements_b.c\
		movements_c.c\
		draw_constants.c\
		draw_variables.c\
		exit_handlers.c

SRC_MAP = srcs/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

HDRS = -I includes/ -I libft/hdrs -I mlx

OBJS=$(SRCS:.c=.o)

LIBS = libft/libft.a libmlx.a

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all: libft mlx $(NAME)

$(NAME): $(OBJS)
	@clang -o $@ $^  $(LIBS) $(HDRS) -lm -Lmlx -lXext -lX11 -lm -lz $(FLAGS)

%.o: %.c
	@clang -c $(FLAGS) -o $@ $< $(HDRS)

libft:
	@echo "\033[1m\033[32mLibft library generated.\033[39m"
	@$(MAKE) -C libft/ all

mlx:
	@echo "\033[1m\033[32mMlx library generated.\033[39m"
	@$(MAKE) -C mlx/ all
	@mv mlx/libmlx.a ./libmlx.a

clean:
	@echo "\033[1m\033[31mObject files removed.\033[39m"
	@$(RM) $(OBJS)
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C mlx/ clean

fclean: clean
	@echo "\033[1m\033[31mExecutable deleted.\033[39m"
	@$(RM) $(NAME)
	@$(MAKE) -C libft/ fclean
	@$(RM) libmlx.a mlx/libmlx.a

re: fclean all

.PHONY: libft so_long all clean fclean re mlx
