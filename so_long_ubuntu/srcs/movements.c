#include <so_long.h>

void	end_game(t_program_data *program_data)
{
	program_data->movements++;
	program_data->score = (1000 / program_data->movements) * program_data->collectibles;
	printf("YOU ROCKSTAR! YOU'VE PASSED THE GAME\nTotal Movements: %u\nCollectibles: %u \nScore: %u\n", program_data->movements, program_data->collectibles, program_data->score);
	close_button(program_data);
	return ;
}

void	clear_position(t_program_data *program_data)
{
	int x_init;
	int x_end;
	int y_init;
	int y_end;
	int i;
	int j;

	x_init = program_data->x * program_data->block_width;
	x_end = (program_data->x * program_data->block_width) + program_data->block_width;
	y_init = program_data->y * program_data->block_length;
	y_end = (program_data->y * program_data->block_length) + program_data->block_length;
	j = y_init;
	i = x_init;

	while (j < y_end)
	{
		i = x_init;
		while (i < x_end)
		{
			my_mlx_pixel_put(program_data->img_data, i, j, 0x00000000);
			i++;
		}
		j++;
	}
	return ;
}

int	check_collectibles(t_program_data *program_data)
{
	int i;
	int j;

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
	int i;
	int j;

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
		program_data->map[program_data->y - 1][program_data->x] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->y -= 1;
		program_data->movements += 1;
		program_data->collectibles += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
	}
	else if (program_data->map[program_data->y - 1][program_data->x] == 'E')
	{
		if (check_collectibles(program_data) == 0)
			end_game(program_data);
		else
			return ;
	}
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
	{
		if (check_collectibles(program_data) == 0)
			end_game(program_data);
		else
			return ;
	}
	return ;
}

void	try_left(t_program_data *program_data)
{
	if (program_data->x == 1)
		return ;
	if (program_data->map[program_data->y][program_data->x - 1] == '0' ||\
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
		program_data->map[program_data->y][program_data->x - 1] = 'P';
		program_data->map[program_data->y][program_data->x] = '0';
		program_data->x -= 1;
		program_data->movements += 1;
		program_data->collectibles += 1;
		printf("Total movements: %u\n", program_data->movements);
		return ;
		}
	else if (program_data->map[program_data->y][program_data->x - 1] == 'E')
	{
		if (check_collectibles(program_data) == 0)
			end_game(program_data);
		else
			return ;
	}
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
	{
		if (check_collectibles(program_data) == 0)
			end_game(program_data);
		else
			return ;
	}
	return ;
}