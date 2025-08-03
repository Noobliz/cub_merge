/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:23:37 by lguiet            #+#    #+#             */
/*   Updated: 2025/08/03 16:00:20 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	has_holes(char **map, int i, int j)
{
	if ((j == 0 && (map[i][j] != '1' && map[i][j] != HOLE && map[i][j] != '\n'))
		|| (i == 0 && (map[0][j] != '1' && map[0][j] != HOLE
		&& map[0][j] != '\n')))
		return (1);
	if (map[i][j] == '0' || is_player(map[i][j]))
	{
		if (map[i][j + 1] && map[i][j + 1] == HOLE)
			return (1);
		if (j > 0 && map[i][j - 1] == HOLE)
			return (1);
		if (i > 0 && map[i - 1][j] == HOLE)
			return (1);
		if (map[i + 1] && map[i + 1][j] == HOLE)
			return (1);
	}
	return (0);
}

int	end_with_walls(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map && map[i])
	{
		if (map[i][len - 2] != '1' && map[i][len - 2] != HOLE)
		{
			write(2, "doesn't end with walls\n", 24);
			free_map(map);
			return (0);
		}
		i++;
	}
	return (1);
}

// check if player or 0 is next to a hole and that first colums is wall
int	check_holes(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!end_with_walls(map))
		return (0);
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (has_holes(map, i, j))
			{
				write(2, "hole in the map\n", 17);
				free_map(map);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	init_and_get_input(t_param *param, char ***infile, char *argv)
{
	param->map_index = -1;
	*infile = get_infile(argv, param);
	if (!(*infile))
		return (0);
	init_params_flags(param);
	if (!check_param(*infile, param, param->map_index))
	{
		free_param(param);
		free_map(*infile);
		return (0);
	}
	return (1);
}

void	map_is_valid(char ***map_rect, char *argv, t_param *param)
{
	char	**infile;
	char	**map;

	map = NULL;
	infile = NULL;
	if (!init_and_get_input(param, &infile, argv))
		return ;
	map = extract_map(infile, param->map_index);
	if (!map)
	{
		free_param(param);
		free_map(infile);
		return ;
	}
	free_map(infile);
	*map_rect = map_to_rectangle(map);
	if (!*map_rect || !has_valid_char(*map_rect) || !check_holes(*map_rect))
	{
		free_param(param);
		*map_rect = NULL;
		return ;
	}
}
