/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:08:50 by thomas            #+#    #+#             */
/*   Updated: 2025/07/31 10:45:53 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_sprites(t_data *data)
{
	int	w;

	w = IMG_WIDTH;
	data->ea = mlx_xpm_file_to_image(data->mlx, "textures/wood.xpm", &w, &w);
	data->we = mlx_xpm_file_to_image(data->mlx, "textures/wood.xpm", &w, &w);
	data->so = mlx_xpm_file_to_image(data->mlx, "textures/wood.xpm", &w, &w);
	data->no = mlx_xpm_file_to_image(data->mlx, "textures/wood.xpm", &w, &w);
	if (!data->ea || !data->we || !data->so || !data->no)
		error("Error: Image loading failed!", data);
	data->f[0] = 64;
	data->f[1] = 64;
	data->f[2] = 64;
	data->c[0] = 135;
	data->c[1] = 205;
	data->c[2] = 235;
	data->sprites_load = 1;
}

int	get_texture_pixel(void *texture, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 0;
	size_line = 0;
	endian = 0;
	data = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	return (*(int *)(data + (y * size_line + x * (bpp / 8))));
}

void	*get_wall_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (data->ea);
		else
			return (data->we);
	}
	else
	{
		if (ray->dir_y > 0)
			return (data->so);
		else
			return (data->no);
	}
}
