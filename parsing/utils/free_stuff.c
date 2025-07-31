/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:34:14 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:04:53 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	if (map)
		free (map);
	map = NULL;
}

void	free_param(t_param *param)
{
	if (param->no_path)
		free(param->no_path);
	if (param->so_path)
		free(param->so_path);
	if (param->we_path)
		free(param->we_path);
	if (param->ea_path)
		free(param->ea_path);
	if (param->c_color_str)
		free(param->c_color_str);
	if (param->f_color_str)
		free(param->f_color_str);
}
