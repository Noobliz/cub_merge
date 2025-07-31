/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:27:46 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 11:04:29 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	print_param(t_param param)
{
	printf("so = %d\n", param.so_flag);
	printf("no = %d\n", param.no_flag);
	printf("we = %d\n", param.we_flag);
	printf("ea = %d\n", param.ea_flag);
	printf("F = %d\n", param.f_flag);
	printf("C = %d\n", param.c_flag);
}

int	has_all_params(t_param param)
{
	if (param.c_flag == 1 && param.f_flag == 1 && param.ea_flag == 1
		&& param.no_flag == 1 && param.so_flag == 1 && param.we_flag == 1)
		return (1);
	write(2,
		"Error\nmake sure all parameters are described correctly\n",
		56);
	return (0);
}

int	map_is_last(t_param param, int map_index)
{
	int	max;

	max = -1;
	if (param.c_index >= max)
		max = param.c_index;
	if (param.f_index >= max)
		max = param.f_index;
	if (param.so_index >= max)
		max = param.so_index;
	if (param.no_index >= max)
		max = param.no_index;
	if (param.we_index >= max)
		max = param.we_index;
	if (param.ea_index >= max)
		max = param.ea_index;
	if (max > map_index)
	{
		write(2, "Error\nmap description should be last\n", 38);
		return (0);
	}
	return (1);
}

void	init_params_flags(t_param *param)
{
	param->no_flag = 0;
	param->no_index = -1;
	param->so_flag = 0;
	param->so_index = -1;
	param->we_flag = 0;
	param->we_index = -1;
	param->ea_flag = 0;
	param->ea_index = -1;
	param->c_flag = 0;
	param->c_index = -1;
	param->f_flag = 0;
	param->f_index = -1;
	param->no_path = NULL;
	param->so_path = NULL;
	param->we_path = NULL;
	param->ea_path = NULL;
	param->c_color_str = NULL;
	param->f_color_str = NULL;
}

int	tab_size(char **tab, int map_index)
{
	int	i;
	int	height;

	i = map_index;
	height = 0;
	while (tab && tab[i])
	{
		height++;
		i++;
	}
	return (height);
}
