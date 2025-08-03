/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:57:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/03 17:07:56 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= data->size_x || y < 0 || y >= data->size_y)
		return ;
	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	dst = data->img_data + offset;
	*(unsigned int *)dst = color;
}

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	wall_heigth(t_ray *ray, t_data *data)
{
	int	line_heigth;

	if (ray->perp_wall_dist <= 0.1)
		ray->perp_wall_dist = 0.1;
	line_heigth = (int)(data->size_y / ray->perp_wall_dist);
	data->draw_start = -line_heigth / 2 + data->size_y / 2;
	data->draw_end = line_heigth / 2 + data->size_y / 2;
}
