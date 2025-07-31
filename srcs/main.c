/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:56:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/07/31 15:34:48 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/parsing.h"

void    init_textures(t_data *data, t_param param)
{
    data->path_ea = param.ea_path;
    data->path_no = param.no_path;
    data->path_so = param.so_path;
    data->path_we = param.we_path;
}

void	init_player_pos(t_data *data)
{
	int i;
    int j;

    i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_player(data->map[i][j]))
			{
				data->player->x = j;
				data->player->y = i;
				if (data->map[i][j] == 'N')
				{
					data->player->dir_x = 0.0;
					data->player->dir_y = -1.0;
					data->player->plane_x = -0.66;
					data->player->plane_y = 0.0;
				}
				else if (data->map[i][j] == 'S')
				{
					data->player->dir_x = 0.0;
					data->player->dir_y = 1.0;
					data->player->plane_x = 0.66;
					data->player->plane_y = 0.0;
				}
				else if (data->map[i][j] == 'E')
				{
					data->player->dir_x = 1.0;
					data->player->dir_y = 0.0;
					data->player->plane_x = 0.0;
					data->player->plane_y = -0.66;
				}
				else if (data->map[i][j] == 'W')
				{
					data->player->dir_x = -1.0;
					data->player->dir_y = 0.0;
					data->player->plane_x = 0.0;
					data->player->plane_y = 0.66;
				}
			}
			j++;
		}
		i++;
	}
}



int guardian(t_data *data, t_param *param, int argc, char **argv)
{
    char **map_rect;
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
    if (!is_color(param->f_color_str, data->f)
    || !is_color(param->c_color_str, data->c) 
    || !check_all_textures(data))
    {
        free_map(data->map);
        free_param(param);
        return (0);
    }
    return (1);
}

int	main(int ac, char **av)
{
	t_param     param;
    t_data      data;

	data.map = NULL;
    if (!guardian(&data, &param, ac, av))
        return (1);
    print_map(data.map);
	game_engine(&data);
	free_map(data.map);
    free_param(data.param);
	return (0);
}
