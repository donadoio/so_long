/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_constants.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 18:40:32 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 20:02:34 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	draw_loop(t_program_data *program_data, \
t_draw_vars draw_vars, t_img_data *img)
{
	while (draw_vars.j < draw_vars.y_end)
	{
		draw_vars.i = draw_vars.x_init;
		draw_vars.i2 = 0;
		while (draw_vars.i < draw_vars.x_end)
		{
			pixel_put(program_data->img_data, img, draw_vars);
			draw_vars.i++;
			draw_vars.i2++;
		}
		draw_vars.j2++;
		draw_vars.j++;
	}
}

void	draw_wall_block(int y, int x, t_program_data *program_data)
{
	t_draw_vars	draw_vars;

	draw_vars.x_init = x * program_data->block_width;
	draw_vars.x_end = (x * program_data->block_width) \
	+ program_data->block_width;
	draw_vars.y_init = y * program_data->block_length;
	draw_vars.y_end = (y * program_data->block_length) \
	+ program_data->block_length;
	draw_vars.j = draw_vars.y_init;
	draw_vars.i = draw_vars.x_init;
	draw_vars.i2 = 0;
	draw_vars.j2 = 0;
	draw_loop(program_data, draw_vars, program_data->wall);
	return ;
}

void	draw_end_block(int y, int x, t_program_data *program_data)
{
	t_draw_vars	draw_vars;

	draw_vars.x_init = x * program_data->block_width;
	draw_vars.x_end = (x * program_data->block_width) \
	+ program_data->block_width;
	draw_vars.y_init = y * program_data->block_length;
	draw_vars.y_end = (y * program_data->block_length) \
	+ program_data->block_length;
	draw_vars.j = draw_vars.y_init;
	draw_vars.i = draw_vars.x_init;
	draw_vars.i2 = 0;
	draw_vars.j2 = 0;
	draw_loop(program_data, draw_vars, program_data->exit);
	return ;
}

void	draw_constants(t_program_data *program_data)
{
	int	y;
	int	x;

	y = 0;
	while (y < program_data->read_data->line_number)
	{
		x = 0;
		while (program_data->map[y][x] != '\0')
		{
			if (program_data->map[y][x] == '1')
				draw_wall_block(y, x, program_data);
			if (program_data->map[y][x] == 'E')
				draw_end_block(y, x, program_data);
			x++;
		}
		y++;
	}
	return ;
}
