/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:38:23 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 19:53:41 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	valid_end(t_program_data *program_data)
{
	if (check_collectibles(program_data) == 0)
		end_game(program_data);
	else
		return ;
	return ;
}

int	check_collectibles(t_program_data *program_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < program_data->read_data->line_number)
	{
		j = 0;
		while (program_data->map[i][j] != '\0')
		{
			if (program_data->map[i][j] == 'C')
			{
				printf("You must collect all collectibles.\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	find_location(t_program_data *program_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < program_data->read_data->line_number)
	{
		j = 0;
		while (program_data->map[i][j] != '\0')
		{
			if (program_data->map[i][j] == 'P')
			{
				program_data->y = i;
				program_data->x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	end_game(t_program_data *program_data)
{
	program_data->movements++;
	program_data->score = (1000 / program_data->movements) * \
	program_data->collectibles;
	printf("YOU'VE COMPLETED THE GAME\n");
	printf("Total Movements: %u\n", program_data->movements);
	printf("Collectibles: %u \n", program_data->collectibles);
	printf("Score: %u\n", program_data->score);
	close_button(program_data);
	return ;
}

void	clear_position(t_program_data *data)
{
	t_draw_vars	draw_vars;

	draw_vars.x_init = data->x * data->block_width;
	draw_vars.x_end = (data->x * data->block_width) + data->block_width;
	draw_vars.y_init = data->y * data->block_length;
	draw_vars.y_end = (data->y * data->block_length) + data->block_length;
	draw_vars.j = draw_vars.y_init;
	draw_vars.i = draw_vars.x_init;
	while (draw_vars.j < draw_vars.y_end)
	{
		draw_vars.i = draw_vars.x_init;
		while (draw_vars.i < draw_vars.x_end)
		{
			my_mlx_pixel_put(data->img_data, \
			draw_vars.i, draw_vars.j, 0x00000000);
			draw_vars.i++;
		}
		draw_vars.j++;
	}
	return ;
}
