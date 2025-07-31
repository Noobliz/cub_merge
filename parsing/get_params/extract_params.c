/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:12:36 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:04:19 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

// return 0 if alloc failed, comp = length of the ID + space
int	alloc_param_value(char *trimmed, char *id, char **target, int comp)
{
	if (ft_strncmp(trimmed, id, comp) == 0)
	{
		*target = ft_strtrim((trimmed + comp), " \n");
		if (!*target)
			return (0);
	}
	return (1);
}

//return 0 if alloc fails
int	alloc_param(char **infile, t_param *param)
{
	char	*trimmed;
	int		i;

	i = 0;
	while (infile && infile[i])
	{
		trimmed = skip_spaces(infile[i]);
		if (!alloc_param_value(trimmed, "SO ", &param->so_path, 3)
			|| !alloc_param_value(trimmed, "NO ", &param->no_path, 3)
			|| !alloc_param_value(trimmed, "WE ", &param->we_path, 3)
			|| !alloc_param_value(trimmed, "EA ", &param->ea_path, 3)
			|| !alloc_param_value(trimmed, "F ", &param->f_color_str, 2)
			|| !alloc_param_value(trimmed, "C ", &param->c_color_str, 2))
			return (0);
		i++;
	}
	return (1);
}

void	check_textures(char *trimmed, t_param *param, int i, int *flag)
{
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
	{
		param->so_flag++;
		param->so_index = i;
		*flag = 1;
	}
	else if (ft_strncmp(trimmed, "NO ", 3) == 0)
	{
		param->no_flag++;
		param->no_index = i;
		*flag = 1;
	}
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
	{
		param->we_flag++;
		param->we_index = i;
		*flag = 1;
	}
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
	{
		param->ea_flag++;
		param->ea_index = i;
		*flag = 1;
	}
}

void	check_colors(char *trimmed, t_param *param, int i)
{
	if (ft_strncmp(trimmed, "F ", 2) == 0)
	{
		param->f_flag++;
		param->f_index = i;
	}
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
	{
		param->c_flag++;
		param->c_index = i;
	}
}

//check if textures and colors are defined and allocate them in t_param
int	check_param(char **infile, t_param *param, int map_index)
{
	char	*trimmed;
	int		i;
	int		flag;

	i = 0;
	if (map_index == -1)
		return (write(2, "Error\nmap not found\n", 21), 0);
	while (infile && infile[i])
	{
		flag = 0;
		trimmed = skip_spaces(infile[i]);
		check_textures(trimmed, param, i, &flag);
		if (flag == 0)
			check_colors(trimmed, param, i);
		i++;
	}
	if (!has_all_params(*param) || !map_is_last(*param, map_index)
		|| !alloc_param(infile, param))
		return (0);
	return (1);
}
