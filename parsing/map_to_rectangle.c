/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:41:54 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:05:29 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	get_biggest_line(char **map)
{
	size_t	max;
	int		i;

	max = 0;
	i = 0;
	while (map && map[i])
	{
		if (ft_strlen(map[i]) > max)
		{
			max = ft_strlen(map[i]);
		}
		i++;
	}
	return (max);
}

void	rm_newline(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	while (map && map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
}

void	filling_holes(int i, char **map, char **new_map, int max_width)
{
	int	k;
	int	j;

	j = ft_strlen(map[i]);
	k = 0;
	while (new_map[i] && new_map[i][k])
	{
		if (new_map[i][k] == ' ')
			new_map[i][k] = HOLE;
		k++;
	}
	while (j < max_width)
	{
		new_map[i][j] = HOLE;
		j++;
	}
	new_map[i][max_width] = '\n';
	new_map[i][max_width + 1] = '\0';
}

int	alloc_map(int *height, int *max_width, char ***new_map, char **map)
{
	rm_newline(map);
	*max_width = get_biggest_line(map);
	if (*max_width <= 1)
	{
		write (2, "map should have more than one column\n", 38);
		free_map(map);
		return (0);
	}
	*height = get_height(map);
	*new_map = ft_calloc(((*height) + 1), sizeof(char *));
	if (!(*new_map))
	{
		write(2, "Error\nallocating map\n", 22);
		free_map(map);
		return (0);
	}
	return (1);
}

char	**map_to_rectangle(char **map)
{
	char	**new_map;
	int		max_width;
	int		height;
	int		i;

	i = 0;
	if (!alloc_map(&height, &max_width, &new_map, map))
		return (NULL);
	while (i < height)
	{
		new_map[i] = ft_calloc(max_width + 2, sizeof(char));
		if (!new_map[i])
		{
			write(2, "Error\nallocating line\n", 23);
			free_map(new_map);
			free_map(map);
			return (NULL);
		}
		ft_strlcpy(new_map[i], map[i], ft_strlen(map[i]) + 1);
		filling_holes(i, map, new_map, max_width);
		i++;
	}
	new_map[height] = NULL;
	free_map(map);
	return (new_map);
}
