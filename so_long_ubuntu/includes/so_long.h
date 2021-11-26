/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 18:38:26 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/23 14:49:30 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WINWIDTH 962
# define WINHEIGHT 601
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <mlx.h>

typedef enum e_bool{
	False,
	True
}		t_bool;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img_data;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*mlx_window;
}				t_mlx_vars;

typedef struct s_window_size {
	int	width;
	int	height;
}				t_window_size;

typedef struct s_read_data {
	int		fd;
	int		gnl_return;
	char	*gnl_str;
	int		line_number;
	size_t	previous_len;
	t_bool	start;
	t_bool	exit;
	t_bool	collectible;
}				t_read_data;

typedef struct s_draw_vars
{
	int	x_init;
	int	x_end;
	int	y_init;
	int	y_end;
	int	i;
	int	j;
	int	i2;
	int	j2;
	int	height;
	int	width;
	int	span_x;
	int	span_y;
}				t_draw_vars;

typedef struct s_program_data {
	t_mlx_vars		*mlx_vars;
	t_img_data		*img_data;
	t_img_data		*wall;
	t_img_data		*player;
	t_img_data		*collect;
	t_img_data		*exit;
	t_img_data		*temp;
	t_window_size	*window_size;
	t_read_data		*read_data;
	char			*map_name;
	size_t			map_name_len;
	char			**map;
	t_bool			mapped_pointers;
	t_bool			mapped;
	int				x;
	int				y;
	unsigned int	movements;
	unsigned int	collectibles;
	unsigned int	score;
	int				block_width;
	int				block_length;
}				t_program_data;

void	program_init(t_program_data *program_data, int av, char **argc);
void	map_check(t_program_data *program_data, char **argc);
void	wrong_map_exit(t_program_data *program_data, char	*str);
void	map_values(t_program_data *program_data);
void	map_set(t_program_data	*program_data);
void	map_char_check(t_program_data *program_data);
void	try_up(t_program_data *program_data);
void	try_down(t_program_data *program_data);
void	try_left(t_program_data *program_data);
void	try_right(t_program_data *program_data);
void	valid_end(t_program_data *program_data);
int		check_collectibles(t_program_data *program_data);
void	clear_position(t_program_data *program_data);
void	end_game(t_program_data *program_data);
void	find_location(t_program_data *program_data);
void	set_textures(t_program_data *program_data);

//drawing
void	draw_constants(t_program_data *program_data);
void	draw_collectibles(t_program_data *program_data);
void	draw_player(t_program_data *program_data);

//exit handlers
void	free_values(t_program_data *program_data);
int		close_button(t_program_data *program_data);
void	unexpected_error(t_program_data *program_data);
void	safe_exit(t_program_data *program_data);

//Graphic stuff
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	pixel_put(t_img_data *data, t_img_data *pxd, t_draw_vars draw_vars);
void	clear_screen(t_program_data	*program_data);

#endif