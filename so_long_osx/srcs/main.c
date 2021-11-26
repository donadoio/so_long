/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:12:50 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/25 15:25:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <keycodes_osx.h>

int	render_next_frame(t_program_data	*program_data)
{
	draw_player(program_data);
	draw_collectibles(program_data);
	mlx_put_image_to_window(program_data->mlx_vars->mlx, \
	program_data->mlx_vars->mlx_window, program_data->img_data->img, 0, 0);
	return (0);
}

int	keypressed(int keycode, t_program_data	*program_data)
{
	if (keycode == UP_KEY)
	{
		try_up(program_data);
		find_location(program_data);
	}
	else if (keycode == DOWN_KEY)
	{
		try_down(program_data);
		find_location(program_data);
	}
	else if (keycode == LEFT_KEY)
	{
		try_left(program_data);
		find_location(program_data);
	}
	else if (keycode == RIGHT_KEY)
	{
		try_right(program_data);
		find_location(program_data);
	}
	else if (keycode == ESC_KEY)
		safe_exit(program_data);
	return (0);
}

int	main(int av, char **argc)
{
	t_program_data	*data;

	data = malloc(sizeof(t_program_data));
	if (data == NULL)
		return (0);
	program_init(data, av, argc);
	data->mlx_vars->mlx = mlx_init();
	data->mlx_vars->mlx_window = mlx_new_window(data->mlx_vars->mlx, \
	data->window_size->width, data->window_size->height, \
	"Leprechaun Gold Hunter");
	data->img_data->img = mlx_new_image(data->mlx_vars->mlx, \
	data->window_size->width, data->window_size->height);
	data->img_data->addr = mlx_get_data_addr(data->img_data->img, \
	&(data->img_data->bits_per_pixel), &(data->img_data->line_length), \
	&(data->img_data->endian));
	set_textures(data);
	draw_constants(data);
	mlx_put_image_to_window(data->mlx_vars->mlx, \
	data->mlx_vars->mlx_window, data->exit->img, 0, 0);
	mlx_hook(data->mlx_vars->mlx_window, 2, 1L << 0, keypressed, data);
	mlx_hook(data->mlx_vars->mlx_window, 17, 0L, close_button, data);
	mlx_loop_hook(data->mlx_vars->mlx, render_next_frame, data);
	mlx_loop(data->mlx_vars->mlx);
	safe_exit(data);
	return (0);
}
