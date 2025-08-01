/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:01:11 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/01 18:16:34 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_player *player)
{
	double	speed_rot;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	speed_rot = 0.1;
	player->dir_x = player->dir_x * cos(speed_rot)
		- player->dir_y * sin(speed_rot);
	player->dir_y = old_dir_x * sin(speed_rot)
		+ player->dir_y * cos(speed_rot);
	player->plane_x = player->plane_x * cos(speed_rot)
		- player->plane_y * sin(speed_rot);
	player->plane_y = old_plane_x * sin(speed_rot)
		+ player->plane_y * cos(speed_rot);
}

void	rotate_right(t_player *player)
{
	double	speed_rot;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	speed_rot = 0.1;
	player->dir_x = player->dir_x * cos(-speed_rot)
		- player->dir_y * sin(-speed_rot);
	player->dir_y = old_dir_x * sin(-speed_rot)
		+ player->dir_y * cos(-speed_rot);
	player->plane_x = player->plane_x * cos(-speed_rot)
		- player->plane_y * sin(-speed_rot);
	player->plane_y = old_plane_x * sin(-speed_rot)
		+ player->plane_y * cos(-speed_rot);
}
