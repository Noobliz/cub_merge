/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:47:20 by thgaugai          #+#    #+#             */
/*   Updated: 2025/07/31 13:37:15 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "X11/X.h"
# include "X11/Xlib.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>

# define IMG_WIDTH 64
# define SIZE_X 1920
# define SIZE_Y 1080
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT_ARR 65361
# define RIGHT_ARR 65363

typedef struct s_param t_param;
/*
typedef struct s_data_map
{
	char			**map;
	char			*path_texture1;
	char			*path_texture2;
	char			*path_texture3;
	char			*path_texture4;
	int				size_x;
	int				size_y;
	int				C[3];//couleur du sol (RGB) ex: C[0] = 255, C[1] = 128, C[0] = 0
	int				F[3];
	
}					t_data_map;*/

typedef struct s_player
{
	double 			x;
	double			y;
	double 			dir_x;
	double			dir_y;
	double 			plane_x;
	double			plane_y;
	double			move_speed;
}					t_player;

typedef struct s_ray
{
	double			dir_x;
	double			dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perp_wall_dist;
	int				screen_heigth;
}					t_ray;

typedef struct s_data
{
	t_player		*player;
	t_ray			*ray;
	void			*mlx;
	void			*win;
	void			*img;
	char			**map;
	int				draw_start;
	int				draw_end;
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
	int				c[3];
	int				f[3];
	int				size_x;
	int				size_y;
	int				tex_x;
	int				tex_y;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	char			*img_data;
	int				sprites_load;
	int				frame_count;
	clock_t			last_fps_time;
	int				fps;
	struct s_param	*param;
    char        orientation;
	double		pi;

}					t_data;

void				error(char *mess, t_data *data);
void				ft_free_map(char **map);
void				ft_exit(t_data *data);
int					close_window(t_data *data);
int					ft_keypress(int keycode, t_data *data);
void				game_engine(char **map, t_data *data);
void				draw_vertical_line(t_player *player,
						t_data *data, t_ray *ray, int x);
int					render(t_data *data);
void				raycasting(t_ray *ray, t_data *data);
void				wall_heigth(t_ray *ray, t_data *data);
int					get_texture_pixel(void *texture, int x, int y);
void				*get_wall_texture(t_data *data, t_ray *ray);
void				load_sprites(t_data *data);
void				put_pixel_to_image(t_data *data, int x, int y, int color);
int					create_color(int r, int g, int b);
void				wall_heigth(t_ray *ray, t_data *data);
void				rotate_right(t_player *player);
void				rotate_left(t_player *player);

void				init_player_pos(t_data *data);
#endif