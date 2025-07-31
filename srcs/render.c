/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:00:52 by thgaugai          #+#    #+#             */
/*   Updated: 2025/07/31 10:45:49 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render(t_data *data)
{
	clock_t	now;
	char	*fps_char;
	char	*tmp;

	tmp = NULL;
	fps_char = NULL;
	mlx_clear_window(data->mlx, data->win);
	raycasting(data->ray, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	data->frame_count++;
	now = clock();
	if (now - data->last_fps_time >= CLOCKS_PER_SEC)
	{
		data->fps = data->frame_count;
		data->frame_count = 0;
		data->last_fps_time = now;
	}
	fps_char = ft_itoa(data->fps);
	tmp = fps_char;
	fps_char = ft_strjoin(tmp, " fps");
	free(tmp);
	mlx_string_put(data->mlx, data->win, 100, 100, 0xFFFFFF, fps_char);
	free(fps_char);
	fps_char = NULL;
	return (0);
}
