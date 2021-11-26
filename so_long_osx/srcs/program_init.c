/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:55:21 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/23 14:32:14 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	t_program_data	*set_struct(t_program_data *program_data)
{
	program_data->mlx_vars = malloc(sizeof(t_mlx_vars));
	program_data->img_data = malloc(sizeof(t_img_data));
	program_data->window_size = malloc(sizeof(t_window_size));
	program_data->read_data = malloc(sizeof(t_read_data));
	program_data->read_data->start = False;
	program_data->read_data->exit = False;
	program_data->read_data->collectible = False;
	program_data->mapped = False;
	program_data->mapped_pointers = False;
	program_data->read_data->gnl_str = NULL;
	program_data->movements = 0;
	program_data->collectibles = 0;
	return (program_data);
}

static	void	set_block_size(t_program_data *program_data)
{
	program_data->block_width = (program_data->window_size->width \
	/ (int)program_data->read_data->previous_len);
	program_data->block_length = program_data->window_size->height \
	/ program_data->read_data->line_number;
	return ;
}

static	void	arg_check(int av, char **argc)
{
	size_t	arg_len;
	char	*mapfile;

	if (av != 2)
	{
		printf("Error!\n Wrong number of arguments.\n");
		exit(0);
	}
	arg_len = ft_strlen(argc[1]);
	if (arg_len < 5)
	{
		printf("Error!\n Wrong map file format.\n");
		exit(0);
	}
	mapfile = ft_substr(argc[1], arg_len - 4, 4);
	if (ft_strncmp(mapfile, ".ber", 4) != 0)
	{
		printf("Error!\n Wrong map file format.\n");
		free(mapfile);
		exit(0);
	}
	free(mapfile);
	return ;
}

void	program_init(t_program_data *program_data, int av, char **argc)
{
	arg_check(av, argc);
	program_data = set_struct(program_data);
	map_check(program_data, argc);
	map_set(program_data);
	find_location(program_data);
	program_data->window_size->width = WINWIDTH;
	program_data->window_size->height = WINHEIGHT;
	set_block_size(program_data);
	return ;
}
