/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:56:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/03 16:43:14 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	guardian(t_data *data, t_param *param, int argc, char **argv)
{
	char	**map_rect;

	map_rect = NULL;
	if (argc != 2)
	{
		write(2, "Error\nenter an infile .cub\n", 28);
		return (0);
	}
	data->param = param;
	map_is_valid(&map_rect, argv[1], param);
	if (!map_rect)
		return (0);
	data->map = map_rect;
	init_textures(data, *param);
	if (!is_color(param->f_color_str, data->f) || !is_color(param->c_color_str,
			data->c) || !check_all_textures(data))
	{
		free_map(data->map);
		free_param(param);
		return (0);
	}
	return (1);
}

void	game_engine(t_data *data)
{
	data_init(data);
	load_sprites(data);
	mlx_hook(data->win, 2, 1L << 0, ft_keypress, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_param	param;
	t_data	data;

	data.map = NULL;
	if (!guardian(&data, &param, ac, av))
		return (1);
	game_engine(&data);
	free_map(data.map);
	free_param(data.param);
	return (0);
}
