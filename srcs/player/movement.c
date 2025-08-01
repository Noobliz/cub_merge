/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:45:18 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/01 18:16:39 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_forward(t_player *player, t_data *data)
{
	if (data->map[(int)player->y][(int)(player->x + player->dir_x
		* player->move_speed)] != '1')
		player->x += player->dir_x * player->move_speed;
	if (data->map[(int)(player->y + player->dir_y
			* player->move_speed)][(int)player->x] != '1')
		player->y += player->dir_y * player->move_speed;
}

void	ft_backward(t_player *player, t_data *data)
{
	if (data->map[(int)player->y][(int)(player->x - player->dir_x
		* player->move_speed)] != '1')
		player->x -= player->dir_x * player->move_speed;
	if (data->map[(int)(player->y - player->dir_y
			* player->move_speed)][(int)player->x] != '1')
		player->y -= player->dir_y * player->move_speed;
}

void	ft_leftward(t_player *player, t_data *data)
{
	double	left_x;
	double	left_y;

	left_x = -player->dir_y;
	left_y = player->dir_x;
	if (data->map[(int)player->y][(int)(player->x + left_x
		* player->move_speed)] != '1')
		player->x += left_x * player->move_speed;
	if (data->map[(int)(player->y + left_y
			* player->move_speed)][(int)player->x] != '1')
		player->y += left_y * player->move_speed;
}

void	ft_rightward(t_player *player, t_data *data)
{
	double	right_x;
	double	right_y;

	right_x = player->dir_y;
	right_y = -player->dir_x;
	if (data->map[(int)player->y][(int)(player->x + right_x
		* player->move_speed)] != '1')
		player->x += right_x * player->move_speed;
	if (data->map[(int)(player->y + right_y
			* player->move_speed)][(int)player->x] != '1')
		player->y += right_y * player->move_speed;
}

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		ft_forward(data->player, data);
	else if (keycode == S)
		ft_backward(data->player, data);
	else if (keycode == A)
		ft_leftward(data->player, data);
	else if (keycode == D)
		ft_rightward(data->player, data);
	else if (keycode == LEFT_ARR)
		rotate_left(data->player);
	else if (keycode == RIGHT_ARR)
		rotate_right(data->player);
	return (0);
}
