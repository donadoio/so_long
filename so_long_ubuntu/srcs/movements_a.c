/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:40:24 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 20:26:53 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	try_up_b(t_program_data *program_data)
{
	program_data->map[program_data->y - 1][program_data->x] = 'P';
	program_data->map[program_data->y][program_data->x] = '0';
	program_data->y -= 1;
	program_data->movements += 1;
	program_data->collectibles += 1;
	printf("Total movements: %u\n", program_data->movements);
	return ;
}

void	try_up(t_program_data *program_data)
{
	if (program_data->y == 1)
		return ;
	if (program_data->map[program_data->y - 1][program_data->x] == '0')
	{
		clear_position(program_data);
		program_data->map[program_data->y - 1][program_data->x] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->y -= 1;
		program_data->movements += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
	}
	else if (program_data->map[program_data->y - 1][program_data->x] == 'C')
	{
		clear_position(program_data);
		try_up_b(program_data);
		return ;
	}
	else if (program_data->map[program_data->y - 1][program_data->x] == 'E')
		valid_end(program_data);
	return ;
}

void	try_down(t_program_data *program_data)
{
	if (program_data->map[program_data->y + 1][program_data->x] == '0')
	{
		clear_position(program_data);
		program_data->map[program_data->y + 1][program_data->x] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->y += 1;
		program_data->movements += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
	}
	else if (program_data->map[program_data->y + 1][program_data->x] == 'C')
	{
		clear_position(program_data);
		program_data->map[program_data->y + 1][program_data->x] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->y += 1;
		program_data->movements += 1;
		program_data->collectibles += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
	}
	else if (program_data->map[program_data->y + 1][program_data->x] == 'E')
		valid_end(program_data);
	return ;
}
