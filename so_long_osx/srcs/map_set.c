/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_set.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:25:57 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 19:25:58 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	delete_multiplayer(int i, int j, t_program_data *program_data)
{
	while (program_data->map[i][j] != '\0')
	{
		if (program_data->map[i][j] == 'P')
			program_data->map[i][j] = '0';
		j++;
	}
	i++;
	while (i < program_data->read_data->line_number)
	{
		j = 0;
		while (program_data->map[i][j] != '\0')
		{
			if (program_data->map[i][j] == 'P')
				program_data->map[i][j] = '0';
			j++;
		}
		i++;
	}
	return ;
}

static	void	set_player(t_program_data *program_data)
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
				j++;
				delete_multiplayer(i, j, program_data);
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

static void	dupe_str(t_program_data *program_data)
{
	program_data->read_data->gnl_return = \
	get_next_line(program_data->read_data->fd, \
	&program_data->read_data->gnl_str);
	if (program_data->read_data->gnl_return == -1)
		unexpected_error(program_data);
	program_data->map[program_data->read_data->line_number] = \
	ft_strdup(program_data->read_data->gnl_str);
	if (program_data->map[program_data->read_data->line_number] == NULL)
		unexpected_error(program_data);
	program_data->mapped = True;
	program_data->read_data->line_number++;
	return ;
}

void	map_set(t_program_data	*program_data)
{
	int	i;
	int	line;

	line = program_data->read_data->line_number;
	program_data->map = malloc(line * 8);
	if (program_data->map == NULL)
		unexpected_error(program_data);
	program_data->mapped_pointers = True;
	i = 0;
	program_data->read_data->line_number = 0;
	program_data->read_data->fd = open(program_data->map_name, O_RDONLY);
	if (program_data->read_data->fd == -1)
		unexpected_error(program_data);
	while (i < line)
	{
		dupe_str(program_data);
		if (program_data->read_data->gnl_return != -1)
			free(program_data->read_data->gnl_str);
		i++;
	}
	set_player(program_data);
	return ;
}
