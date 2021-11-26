/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:20:48 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 19:32:32 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	wrong_map_exit(t_program_data *program_data, char	*str)
{
	printf("Error!\nInvalid map. %s\n", str);
	free(program_data->mlx_vars);
	free(program_data->img_data);
	free(program_data->window_size);
	free(program_data->read_data);
	exit(0);
}

void	map_values(t_program_data *program_data)
{
	int	i;

	i = 0;
	while (program_data->read_data->gnl_str[i] != '\0')
	{
		if (program_data->read_data->gnl_str[i] == 'P')
			program_data->read_data->start = True;
		if (program_data->read_data->gnl_str[i] == 'E')
			program_data->read_data->exit = True;
		if (program_data->read_data->gnl_str[i] == 'C')
			program_data->read_data->collectible = True;
		i++;
	}
	return ;
}

void	map_char_check(t_program_data *program_data)
{
	int	i;

	i = 0;
	while (program_data->read_data->gnl_str[i] != '\0')
	{
		if (program_data->read_data->gnl_str[i] != '1' && \
		program_data->read_data->gnl_str[i] != '0' && \
		program_data->read_data->gnl_str[i] != 'E' && \
		program_data->read_data->gnl_str[i] != 'C' \
		&& program_data->read_data->gnl_str[i] != 'P')
			wrong_map_exit(program_data, "The map has invalid characters.");
		i++;
	}
	return ;
}
