NAME = so_long

SRC =	main.c\
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

FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lm -Lmlx -framework OpenGL -framework AppKit -lm -g

CC = clang

LIBS = libft/libft.a libmlx.dylib

HDRS = -I mlx -I libft/hdrs -I includes/

OBJS := $(SRCS:.c=.o)

OPT_FLAGS = -O2

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C  libft/ all
	@$(MAKE) -C mlx/ all
	@mv mlx/libmlx.dylib ./libmlx.dylib
	@$(CC) -o $@ $^ $(LIBS) $(HDRS) $(MLX_FLAGS) $(FLAGS)
	@echo "\033[1m\033[32mSuccessfully Compiled\033[39m"

%.o: %.c
	@$(CC) -o $@ -c $<  $(HDRS) $(FLAGS)

clean: 
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C mlx/ clean
	@rm $(OBJS)
	@echo "\033[1m\033[33mCleaning Object Files\033[39m"

fclean: 
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C mlx/ clean
	@rm -f $(OBJS)
	@rm -f libmlx.dylib
	@rm -f $(NAME)
	@echo "\033[1m\033[31mPurged Objects and Executables\033[39m"

re: fclean all

.PHONY: all clean fclean re so_long