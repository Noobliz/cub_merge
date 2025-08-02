/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:30:16 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:00:19 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != '\n')
			return (0);
		i++;
	}
	if (i == 0 || ft_strspn(line, " \n") == i)
		return (0);
	return (1);
}

//malloc of new line in **tab, 1 for line 1 for \0
char	**add_line(char **map, char *line, int *count)
{
	int		i;
	char	**new_map;

	i = 0;
	if (line && (line[0] == '\0'))
		return (NULL);
	new_map = malloc(sizeof(char *) * (*count + 2));
	if (!new_map)
	{
		perror("malloc");
		return (NULL);
	}
	while (i < *count)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[*count] = line;
	new_map[*count + 1] = NULL;
	if (map)
		free(map);
	(*count)++;
	return (new_map);
}

int	copy_content(char *line, int fd, t_param *param, char ***map)
{
	int	count;
	int	map_found;

	count = 0;
	map_found = 0;
	line = get_next_line(fd);
	while (line)
	{
		find_map(&map_found, line, param, count);
		if (map_found)
		{
			if (line[0] == '\n' || line[0] == '\0' || line[0] == '\t')
			{
				map_found = 42;
				free(line);
				line = NULL;
				break ;
			}
			*map = add_line(*map, line, &count);
		}
		else if (line)
			*map = add_line(*map, line, &count);
		line = get_next_line(fd);
	}
	return (map_found);
}

//skip the textures lines and then copy into a **tab
//starting from the first valid char found (1 / 0 / N / S etc)
char	**get_infile(char *filename, t_param *param)
{
	int		fd;
	char	*line;
	char	**map;

	line = NULL;
	map = NULL;
	if (!open_fd(filename, &fd))
		return (0);
	if (copy_content(line, fd, param, &map) == 42)
	{
		write(2, "Error\nmap description must be last\n", 36);
		free_line_close_fd(line, &fd);
		free_map(map);
		return (NULL);
	}
	free_line_close_fd(line, &fd);
	if (!map)
		write(2, "Error\ninfile is empty\n", 23);
	return (map);
}
