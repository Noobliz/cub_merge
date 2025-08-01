/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:21:20 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/01 18:16:16 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(t_data *data, int y, int x)
{
	int	ceiling_color;

	ceiling_color = create_color(data->c[0], data->c[1], data->c[2]);
	while (y < data->draw_start)
	{
		put_pixel_to_image(data, x, y, ceiling_color);
		y++;
	}
}

void	draw_floor(t_data *data, int x, int y)
{
	int	floor_color;

	floor_color = create_color(data->f[0], data->f[1], data->f[2]);
	y = data->draw_end;
	while (y < data->size_y)
	{
		put_pixel_to_image(data, x, y, floor_color);
		y++;
	}
}

void	draw_wall(t_data *data, void *texture, int x, int y)
{
	int	color;

	color = 0;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)((double)(y - data->draw_start)
				/ (data->draw_end - data->draw_start) * IMG_WIDTH);
		color = get_texture_pixel(texture, data->tex_x, data->tex_y);
		put_pixel_to_image(data, x, y, color);
		y++;
	}
}

void	draw_vertical_line(t_player *player, t_data *data, t_ray *ray, int x)
{
	void	*texture;
	int		y;
	double	wall_x;

	y = 0;
	wall_x = 0;
	wall_heigth(ray, data);
	draw_ceiling(data, y, x);
	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->dir_x;
	wall_x = wall_x - floor(wall_x);
	data->tex_x = (int)(wall_x * IMG_WIDTH);
	texture = get_wall_texture(data, ray);
	draw_wall(data, texture, x, y);
	draw_floor(data, x, y);
}
