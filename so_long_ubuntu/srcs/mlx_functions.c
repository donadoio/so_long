/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:26:16 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 19:28:48 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pixel_put(t_img_data *data, t_img_data *pxd, t_draw_vars draw_vars)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		data->addr[draw_vars.j * data->line_length + \
		draw_vars.i * data->bits_per_pixel / 8 + i] = \
		pxd->addr[draw_vars.j2 * pxd->line_length + \
		draw_vars.i2 * pxd->bits_per_pixel / 8 + i];
		i++;
	}
	return ;
}

void	clear_screen(t_program_data	*data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->window_size->width)
	{
		y = 0;
		while (y < data->window_size->height)
		{
			my_mlx_pixel_put(data->img_data, x, y, 0x00000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_vars->mlx, \
	data->mlx_vars->mlx_window, data->img_data->img, 0, 0);
	return ;
}
