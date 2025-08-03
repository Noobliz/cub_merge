/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:57:11 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/03 16:49:37 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ray	*ray_init(t_data *data)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		error("Error\nMemory allocation failed!", data);
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0.0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->screen_heigth = 0;
	return (ray);
}

void	window_init(t_data	*data)
{
	data->img_data = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		error("Error\nMinilibx: Initializing failed!", data);
	data->win = mlx_new_window(data->mlx, data->size_x, data->size_y, "Cub3d");
	if (!data->win)
		error("Error\nMinilibx: Window creation failed!", data);
	data->img = mlx_new_image(data->mlx, data->size_x, data->size_y);
	if (!data->img)
		error("Error\nMinilibx: Image creation failed!", data);
	data->img_data = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->ray = ray_init(data);
}

t_data	*data_init(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		error("Error\nMemory allocation failed!", data);
	data->size_x = SIZE_X;
	data->size_y = SIZE_Y;
	player_init(data);
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->sprites_load = 0;
	data->fps = 0;
	data->last_fps_time = 0;
	data->frame_count = 0;
	data->draw_end = 0;
	data->draw_start = 0;
	data->img = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->ray = NULL;
	window_init(data);
	return (data);
}
