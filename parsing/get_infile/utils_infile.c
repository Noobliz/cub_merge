/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:44:34 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:00:31 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

//better than strchr because avoid finding the occurence anywhere
int	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	match;

	i = 0;
	while (s[i])
	{
		match = 0;
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break ;
			}
			j++;
		}
		if (!match)
			break ;
		i++;
	}
	return (i);
}

int	open_fd(char *filename, int *fd)
{
	if (!valid_name(filename))
		return (0);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		write(2, "Error\nopening map\n", 19);
		return (0);
	}
	return (1);
}

void	free_line_close_fd(char *line, int *fd)
{
	line = get_next_line(*fd);
	while (line)
	{
		free(line);
		line = get_next_line(*fd);
	}
	close(*fd);
}

void	find_map(int *map_found, char *line, t_param *param, int count)
{
	if (*map_found == 0 && is_map_line(line))
	{
		param->map_index = count;
		*map_found = 1;
	}
}

int	valid_name(char *name)
{
	int		len;
	char	*extension;

	len = ft_strlen(name);
	if (len < 5)
	{
		write(2, "Error\ninput must be : <name.cub>\n", 34);
		return (0);
	}
	len = len - 4;
	extension = name + len;
	if (ft_strcmp(extension, ".cub") != 0)
	{
		write(2, "Error\nextension format : <.cub>\n", 33);
		return (0);
	}
	return (1);
}
