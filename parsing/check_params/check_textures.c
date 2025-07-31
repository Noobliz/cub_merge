/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:23:29 by lguiet            #+#    #+#             */
/*   Updated: 2025/07/31 13:57:45 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/cub3d.h"

int	check_texture_path(void *mlx_ptr, char *texture_path)
{
	int		width;
	int		height;
	void	*img;

	if (!texture_path)
	{
		write(2, "Error\ntexture path is NULL\n", 28);
		return (0);
	}
	img = mlx_xpm_file_to_image(mlx_ptr, texture_path, &width, &height);
	if (!img)
	{
		write(2, "Error\ninvalid texture path\n", 28);
		return (0);
	}
	mlx_destroy_image(mlx_ptr, img);
	return (1);
}

int	check_all_textures(t_data *data)
{
	t_mlx_win	mlx_win;

	mlx_win.mlx_ptr = mlx_init();
	if (!mlx_win.mlx_ptr)
	{
		write(2, "Error\nfailed to init mlx\n", 26);
		return (0);
	}
	if (!check_texture_path(mlx_win.mlx_ptr, data->path_no)
		|| !check_texture_path(mlx_win.mlx_ptr, data->path_so)
		|| !check_texture_path(mlx_win.mlx_ptr, data->path_we)
		|| !check_texture_path(mlx_win.mlx_ptr, data->path_ea))
	{
		mlx_destroy_display(mlx_win.mlx_ptr);
		free(mlx_win.mlx_ptr);
		return (0);
	}
	mlx_destroy_display(mlx_win.mlx_ptr);
	free(mlx_win.mlx_ptr);
	return (1);
}
