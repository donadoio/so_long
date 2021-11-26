/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_textures.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 20:01:56 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/23 14:01:50 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	resize_loop(t_program_data *data, \
t_img_data *texture, t_draw_vars draw_vars)
{
	int	i;

	while (draw_vars.i < draw_vars.width)
	{
		draw_vars.j = 0;
		draw_vars.j2 = 0;
		while (draw_vars.j < draw_vars.height)
		{
			i = 0;
			while (i < 3)
			{
				texture->addr[draw_vars.j * texture->line_length + \
				draw_vars.i * texture->bits_per_pixel / 8 + i] = \
				data->temp->addr[draw_vars.j2 * \
				data->temp->line_length + draw_vars.i2 * \
				data->temp->bits_per_pixel / 8 + i];
				i++;
			}
			draw_vars.j++;
			draw_vars.j2 += draw_vars.span_y;
		}
		draw_vars.i++;
		draw_vars.i2 += draw_vars.span_x;
	}
	return ;
}

static	t_img_data	*resize_image(t_program_data *data, t_img_data *texture)
{
	t_draw_vars	draw_vars;

	draw_vars.height = data->block_length;
	draw_vars.width = data->block_width;
	texture = malloc(sizeof(t_img_data));
	texture->img = mlx_new_image(data->mlx_vars->mlx, \
	draw_vars.width, draw_vars.height);
	texture->addr = mlx_get_data_addr(texture->img, \
	&texture->bits_per_pixel, &texture->line_length, \
	&texture->endian);
	draw_vars.span_x = 1000 / draw_vars.width;
	draw_vars.span_y = 1000 / draw_vars.height;
	draw_vars.i = 0;
	draw_vars.i2 = 0;
	resize_loop(data, texture, draw_vars);
	return (texture);
}

static	void	set_constants(t_program_data *data)
{
	data->temp = malloc(sizeof(t_img_data));
	data->temp->img = \
	mlx_xpm_file_to_image(data->mlx_vars->mlx, \
	"./img/wall.xpm", &data->temp->width, &data->temp->height);
	data->temp->addr = mlx_get_data_addr(data->temp->img, \
	&data->temp->bits_per_pixel, &data->temp->line_length, \
	&data->temp->endian);
	data->wall = resize_image(data, data->wall);
	mlx_destroy_image(data->mlx_vars->mlx, data->temp->img);
	free(data->temp);
	data->temp = malloc(sizeof(t_img_data));
	data->temp->img = \
	mlx_xpm_file_to_image(data->mlx_vars->mlx, \
	"./img/exit.xpm", &data->temp->width, &data->temp->height);
	data->temp->addr = mlx_get_data_addr(data->temp->img, \
	&data->temp->bits_per_pixel, &data->temp->line_length, \
	&data->temp->endian);
	data->exit = resize_image(data, data->exit);
	mlx_destroy_image(data->mlx_vars->mlx, data->temp->img);
	free(data->temp);
	return ;
}

void	set_textures(t_program_data *data)
{
	set_constants(data);
	data->temp = malloc(sizeof(t_img_data));
	data->temp->img = \
	mlx_xpm_file_to_image(data->mlx_vars->mlx, \
	"./img/player.xpm", &data->temp->width, \
	&data->temp->height);
	data->temp->addr = mlx_get_data_addr(data->temp->img, \
	&data->temp->bits_per_pixel, &data->temp->line_length, \
	&data->temp->endian);
	data->player = resize_image(data, data->player);
	mlx_destroy_image(data->mlx_vars->mlx, data->temp->img);
	free(data->temp);
	data->temp = malloc(sizeof(t_img_data));
	data->temp->img = \
	mlx_xpm_file_to_image(data->mlx_vars->mlx, \
	"./img/collect.xpm", &data->temp->width, \
	&data->temp->height);
	data->temp->addr = mlx_get_data_addr(data->temp->img, \
	&data->temp->bits_per_pixel, &data->temp->line_length, \
	&data->temp->endian);
	data->collect = resize_image(data, data->collect);
	return ;
}
