/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_handlers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:05:02 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 19:07:05 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	basic_frees(t_program_data *program_data)
{
	free(program_data->img_data);
	free(program_data->mlx_vars);
	free(program_data->window_size);
	free(program_data->map_name);
	free(program_data->temp);
	free(program_data->wall);
	free(program_data->player);
	free(program_data->collect);
	free(program_data->exit);
	return ;
}

void	free_values(t_program_data *program_data)
{
	int	i;

	i = 0;
	if (program_data != NULL)
	{
		basic_frees(program_data);
		if (program_data->mapped == True)
		{
			while (i < program_data->read_data->line_number)
			{
				free(program_data->map[i]);
				i++;
			}
		}
		free(program_data->read_data);
		if (program_data->mapped_pointers == True)
			free(program_data->map);
		free(program_data);
		program_data = NULL;
	}
	return ;
}

void	safe_exit(t_program_data *data)
{
	printf("Exiting program.\n");
	mlx_destroy_image(data->mlx_vars->mlx, data->player->img);
	mlx_destroy_image(data->mlx_vars->mlx, data->img_data->img);
	mlx_destroy_image(data->mlx_vars->mlx, data->wall->img);
	mlx_destroy_image(data->mlx_vars->mlx, data->temp->img);
	mlx_destroy_image(data->mlx_vars->mlx, data->collect->img);
	mlx_destroy_image(data->mlx_vars->mlx, data->exit->img);
	mlx_destroy_window(data->mlx_vars->mlx, data->mlx_vars->mlx_window);
	free_values(data);
	exit(0);
	return ;
}

int	close_button(t_program_data *program_data)
{
	safe_exit(program_data);
	return (0);
}

void	unexpected_error(t_program_data *program_data)
{
	printf("Error\n Unexpected! Exiting program.\n");
	free_values(program_data);
	exit (0);
	return ;
}
