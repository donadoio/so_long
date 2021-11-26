/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:23:15 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/24 14:23:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <unistd.h>

static	void	wall_edges(t_program_data *program_data)
{
	size_t	len;

	len = ft_strlen(program_data->read_data->gnl_str);
	if (program_data->read_data->gnl_str[0] != '1' || \
	program_data->read_data->gnl_str[len - 1] != '1')
		wrong_map_exit(program_data, "Missing walls.");
	if (ft_strlen(program_data->read_data->gnl_str) \
	!= program_data->read_data->previous_len)
		wrong_map_exit(program_data, "The map is not a perfect rectangle.");
	map_char_check(program_data);
	map_values(program_data);
	return ;
}

static	void	wall_top_bottom(t_program_data *program_data)
{
	int	i;

	i = 0;
	while (program_data->read_data->gnl_str[i] != '\0')
	{
		if (program_data->read_data->gnl_str[i] != '1')
			wrong_map_exit(program_data, "Missing walls.");
		i++;
	}
	return ;
}

static	void	wall_check(t_program_data *data)
{
	data->read_data->gnl_return = \
	get_next_line(data->read_data->fd, &data->read_data->gnl_str);
	if (data->read_data->gnl_return == -1)
		unexpected_error(data);
	if (ft_strlen(data->read_data->gnl_str) == 0)
	{
		data->read_data->gnl_return = 0;
		wrong_map_exit(data, "No empty lines in the map please!");
	}
	if (data->read_data->line_number == 0)
	{
		data->read_data->previous_len = ft_strlen(data->read_data->gnl_str);
		wall_top_bottom(data);
	}
	if (ft_strlen(data->read_data->gnl_str) < 3)
		wrong_map_exit(data, "Map is way too small to be valid.");
	if (data->read_data->line_number > 0)
		wall_edges(data);
	data->read_data->line_number++;
	return ;
}

static void	map_check_loop(t_program_data *data)
{
	while (data->read_data->gnl_return != -1 && \
	data->read_data->gnl_return != 0)
	{
		wall_check(data);
		if (data->read_data->gnl_return != 0)
		{
			free(data->read_data->gnl_str);
			data->read_data->gnl_str = NULL;
		}
	}
}

void	map_check(t_program_data *data, char **argc)
{
	data->map_name_len = ft_strlen(argc[1]);
	data->map_name = ft_substr(argc[1], 0, data->map_name_len);
	data->read_data->fd = open(data->map_name, O_RDONLY);
	if (data->read_data->fd == -1)
		wrong_map_exit(data, "Unable to read from map file.");
	data->read_data->gnl_return = 1;
	data->read_data->line_number = 0;
	map_check_loop(data);
	wall_top_bottom(data);
	if (data->read_data->gnl_str != NULL && data->read_data->gnl_return == 0)
		free(data->read_data->gnl_str);
	if (data->read_data->start != True || data->read_data->exit \
	!= True || data->read_data->collectible != True)
		wrong_map_exit(data, \
		"Not enough starting positions, exits, or collectibles.");
	if (data->read_data->line_number > WINHEIGHT || \
	(int)data->read_data->previous_len > WINWIDTH)
		wrong_map_exit(data, "The map can't be bigger than the \
established window size.");
	close(data->read_data->fd);
	return ;
}
