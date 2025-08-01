/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:46:57 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/01 18:16:25 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ray_direction(t_data *data, t_player *player, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)data->size_x - 1;
	ray->dir_x = player->dir_x + player->plane_x * camera_x;
	ray->dir_y = player->dir_y + player->plane_y * camera_x;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

static void	ray_distance(t_ray	*ray, t_player *player, int *map_x, int *map_y)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - *map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (*map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - *map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (*map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

static void	check_hit_wall(t_data *data, t_ray *ray, int *map_x, int *map_y)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			*map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			*map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[*map_y][*map_x] == '1')
			ray->hit = 1;
	}
}

static void	perpendicular_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	raycasting(t_ray *ray, t_data *data)
{
	int	x;
	int	map_x;
	int	map_y;

	x = -1;
	while (++x < data->size_x)
	{
		ray->hit = 0;
		map_x = (int)data->player->x;
		map_y = (int)data->player->y;
		ray_direction(data, data->player, ray, x);
		ray_distance(ray, data->player, &map_x, &map_y);
		check_hit_wall(data, ray, &map_x, &map_y);
		perpendicular_distance(ray);
		draw_vertical_line(data->player, data, ray, x);
	}
}
