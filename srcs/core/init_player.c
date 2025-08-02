/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:08:40 by thomas            #+#    #+#             */
/*   Updated: 2025/08/02 12:00:50 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	finish_init(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'S')
	{
		data->player->dir_x = 0.0;
		data->player->dir_y = 1.0;
		data->player->plane_x = 0.66;
		data->player->plane_y = 0.0;
	}
	else if (data->map[i][j] == 'E')
	{
		data->player->dir_x = 1.0;
		data->player->dir_y = 0.0;
		data->player->plane_x = 0.0;
		data->player->plane_y = -0.66;
	}
	else if (data->map[i][j] == 'W')
	{
		data->player->dir_x = -1.0;
		data->player->dir_y = 0.0;
		data->player->plane_x = 0.0;
		data->player->plane_y = 0.66;
	}
}

static void	set_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_player(data->map[i][j]))
			{
				data->player->x = j;
				data->player->y = i;
				if (data->map[i][j] == 'N')
				{
					data->player->dir_x = 0.0;
					data->player->dir_y = -1.0;
					data->player->plane_x = -0.66;
					data->player->plane_y = 0.0;
				}
				finish_init(data, i, j);
			}
			j++;
		}
	}
}

void	player_init(t_data *data)
{
	data->player->x = 0;
	data->player->y = 0;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	set_player_pos(data);
	data->player->x += 0.5;
	data->player->y += 0.5;
	data->player->move_speed = 0.1;
}
