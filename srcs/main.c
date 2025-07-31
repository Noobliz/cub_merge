/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:56:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/07/31 13:19:49 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/parsing.h"

void    init_textures(t_data *data, t_param param)
{
    data->ea = param.ea_path;
    data->no = param.no_path;
    data->so = param.so_path;
    data->we = param.we_path;
}

void	init_player_pos(t_data *data)
{
    data->pi = 3.1415;
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
				data->player->x = j + 0.5; //* IMG_WIDTH + IMG_WIDTH/ 2;
				data->player->y = i + 0.5; //* IMG_WIDTH + IMG_WIDTH / 2;
				if (data->map[i][j] == 'N')
					data->orientation = 'N'; //3 * data->pi / 2;
				else if (data->map[i][j] == 'S')
					data->orientation = 'S';//data->pi / 2;
				else if (data->map[i][j] == 'E')
					data->orientation = 'E';//0;
				else if (data->map[i][j] == 'W')
					data->orientation = 'W';//data->pi;
                // data->player->p_delta_x = cos(data->player->p_angle) * data->player->speed;
                // data->player->p_delta_y = sin(data->player->p_angle) * data->player->speed;
			}
			j++;
		}
		i++;
	}
}

// int	counter_line(char *file)
// {
// 	int		fd;
// 	char	*line;
// 	int		counter;

// 	counter = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error: File descriptor is invalid!");
// 		exit(EXIT_FAILURE);
// 	}
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		counter++;
// 		free(line);
// 		line = NULL;
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (counter);
// }

// char	**map_init(char *file)
// {
// 	char	**map;
// 	char	*line;
// 	int		i;
// 	int		fd;
// 	int		count;

// 	count = counter_line(file);
// 	i = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_printf("Error: Cannot open file!\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	map = malloc(sizeof(char *) * (count + 1));
// 	if (!map)
// 	{
// 		ft_printf("Error: Memomy allocation failed!\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		map[i] = ft_strdup(line);
// 		if (!map[i])
// 		{
// 			ft_printf("Error: Memomy allocation failed!\n");
// 			ft_free_map(map);
// 		}
// 		free(line);
// 		line = NULL;
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	map[i] = NULL;
// 	close(fd);
// 	return (map);
// }

int guardian(t_data *data, t_param *param, int argc, char **argv)
{
    char **map_rect;
    map_rect = NULL;
    if (argc != 2)
    {
        write(2, "Error\nenter an infile .cub\n", 28);
        return (0);
    }
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
	// char	**map;
	// (void)ac;

	// map = map_init(av[1]);
	t_param param;
    t_data data;
	
	data.map = NULL;
    if (!guardian(&data, &param, ac, av))
        return (1);
    init_player_pos(&data);
    print_map(data.map);
	game_engine(data.map);
	free_map(data.map);
    free_param(data.param);
	return (0);
}
