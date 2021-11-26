/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements_c.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 20:19:23 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 20:25:33 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	try_left_b(t_program_data *program_data)
{
	program_data->map[program_data->y][program_data->x - 1] = 'P';
	program_data->map[program_data->y][program_data->x] = '0';
	program_data->x -= 1;
	program_data->movements += 1;
	program_data->collectibles += 1;
	printf("Total movements: %u\n", program_data->movements);
	return ;
}

void	try_left(t_program_data *program_data)
{
	if (program_data->x == 1)
		return ;
	if (program_data->map[program_data->y][program_data->x - 1] == '0' || \
	program_data->map[program_data->y][program_data->x - 1] == 'C')
	{
		clear_position(program_data);
		program_data->map[program_data->y][program_data->x - 1] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->x -= 1;
		program_data->movements += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
	}
	else if (program_data->map[program_data->y][program_data->x - 1] == 'C')
	{
		clear_position(program_data);
		try_left_b(program_data);
		return ;
	}
	else if (program_data->map[program_data->y][program_data->x - 1] == 'E')
		valid_end(program_data);
	return ;
}

void	try_right(t_program_data *program_data)
{
	if (program_data->map[program_data->y][program_data->x + 1] == '0')
	{
		clear_position(program_data);
		program_data->map[program_data->y][program_data->x + 1] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->x += 1;
		program_data->movements += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
	}
	else if (program_data->map[program_data->y][program_data->x + 1] == 'C')
	{
		clear_position(program_data);
		program_data->map[program_data->y][program_data->x + 1] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->x += 1;
		program_data->movements += 1;
		program_data->collectibles += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
	}
	else if (program_data->map[program_data->y][program_data->x + 1] == 'E')
		valid_end(program_data);
	return ;
}
