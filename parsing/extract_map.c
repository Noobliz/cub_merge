/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:39:07 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:06:13 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	one_player(char **map)
{
	int	player_count;
	int	walkable_count;
	int	i;
	int	j;

	player_count = 0;
	walkable_count = 0;
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				player_count++;
			if (map[i][j] == '0')
				walkable_count++;
			j++;
		}
		i++;
	}
	if (player_count > 1 || player_count == 0 || walkable_count == 0)
		return (0);
	return (1);
}

int	has_valid_char(char **map)
{
	int	i;

	i = 0;
	if (!one_player(map))
	{
		write(2, "Error\ninput 1 player max and at least 1 walkable\n", 50);
		free_map(map);
		return (0);
	}
	while (map && map[i])
	{
		if (!valid_char(map[i]))
		{
			write(2, "Error\ninvalid char\n", 20);
			free_map(map);
			return (0);
		}
		i++;
	}
	return (1);
}

//extract de map from **infile, removing all parameters lines
//return the new map
char	**extract_map(char **infile, int map_index)
{
	int		height;
	int		i;
	char	**map_lines;

	height = tab_size(infile, map_index);
	map_lines = ft_calloc(height + 1, sizeof(char *));
	if (!map_lines)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_lines[i] = ft_strdup(infile[map_index + i]);
		if (!map_lines[i])
		{
			free_map(map_lines);
			return (NULL);
		}
		i++;
	}
	map_lines[i] = NULL;
	return (map_lines);
}
