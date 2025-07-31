/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:36:39 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:05:03 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	is_player(char c)
{
	return (((c) == 'N' || (c) == 'S' || (c) == 'E' || (c) == 'W'));
}

int	valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != HOLE && line[i] != '\0' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

char	*skip_spaces(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}
