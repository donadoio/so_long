/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_variables.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:01:16 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 19:04:01 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	draw_player(t_program_data *program_data)
{
	t_draw_vars	draw_vars;

	draw_vars.x_init = program_data->x * program_data->block_width;
	draw_vars.x_end = (program_data->x * program_data->block_width) \
	+ program_data->block_width;
	draw_vars.y_init = program_data->y * program_data->block_length;
	draw_vars.y_end = (program_data->y * program_data->block_length) \
	+ program_data->block_length;
	draw_vars.j = draw_vars.y_init;
	draw_vars.i = draw_vars.x_init;
	draw_vars.j2 = 0;
	while (draw_vars.j < draw_vars.y_end)
	{
		draw_vars.i = draw_vars.x_init;
		draw_vars.i2 = 0;
		while (draw_vars.i < draw_vars.x_end)
		{
			pixel_put(program_data->img_data, program_data->player, draw_vars);
			draw_vars.i++;
			draw_vars.i2++;
		}
		draw_vars.j++;
		draw_vars.j2++;
	}
	return ;
}

static	void	draw_collectible_block(int y, int x, t_program_data *data)
{
	t_draw_vars	draw_vars;

	draw_vars.x_init = x * data->block_width;
	draw_vars.x_end = (x * data->block_width) \
	+ data->block_width;
	draw_vars.y_init = y * data->block_length;
	draw_vars.y_end = (y * data->block_length) \
	+ data->block_length;
	draw_vars.j = draw_vars.y_init;
	draw_vars.i = draw_vars.x_init;
	draw_vars.j2 = 0;
	while (draw_vars.j < draw_vars.y_end)
	{
		draw_vars.i2 = 0;
		draw_vars.i = draw_vars.x_init;
		while (draw_vars.i < draw_vars.x_end)
		{
			pixel_put(data->img_data, data->collect, draw_vars);
			draw_vars.i2++;
			draw_vars.i++;
		}
		draw_vars.j2++;
		draw_vars.j++;
	}
	return ;
}

void	draw_collectibles(t_program_data *program_data)
{
	int	y;
	int	x;

	y = 0;
	while (y < program_data->read_data->line_number)
	{
		x = 0;
		while (program_data->map[y][x] != '\0')
		{
			if (program_data->map[y][x] == 'C')
				draw_collectible_block(y, x, program_data);
			x++;
		}
		y++;
	}
	return ;
}
