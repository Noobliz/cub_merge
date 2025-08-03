/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:26:23 by lguiet            #+#    #+#             */
/*   Updated: 2025/08/03 16:03:09 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMS = COLORS AND TEXTURES
// MAP = the map itself

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "cub3d.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// define the value used to make the map rectangle
# ifndef HOLE
#  define HOLE 'Q'

struct	s_data;

typedef struct s_param
{
	int		no_flag;
	int		so_flag;
	int		we_flag;
	int		ea_flag;

	int		f_flag;
	int		c_flag;

	int		no_index;
	int		so_index;
	int		we_index;
	int		ea_index;

	int		f_index;
	int		c_index;

	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	char	*f_color_str;
	char	*c_color_str;

	int		map_index;

}			t_param;

typedef struct s_mlx_win
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	void	*time_value;
}			t_mlx_win;
//----[GET_PARAMS/extract_params]-----
int			check_param(char **infile, t_param *param, int map_index);
int			is_color(char *color_str, int color_int[3]);
int			check_all_textures(struct s_data *data);
//-----get_params/params_utils---
void		print_param(t_param param);
void		init_params_flags(t_param *param);
int			tab_size(char **tab, int map_index);
int			has_all_params(t_param param);
int			map_is_last(t_param param, int map_index);

//-----[GET_INFILE]-----
char		**get_infile(char *filename, t_param *param);
int			is_map_line(char *line);
//-----get_infile/utils----
int			valid_name(char *name);
void		find_map(int *map_found, char *line, t_param *param, int count);
void		free_line_close_fd(char *line, int *fd);
int			open_fd(char *filename, int *fd);
int			ft_strspn(const char *s, const char *accept);

// skip the textures lines and then copy into 
// a **tab starting from the map index(where the map was found)
char		**extract_map(char **infile, int map_index);
int			one_player(char **map);
int			has_valid_char(char **map);

// make the original map rectangle
char		**map_to_rectangle(char **map);
int			has_valid_char(char **map);
int			check_holes(char **map);

// valid_chars
void		map_is_valid(char ***map_rect, char *argv, t_param *param);

// free_stuff
void		free_map(char **map);
void		free_param(t_param *param);

// utils
void		print_map(char **map);
int			valid_char(char *line);
int			is_player(char c);
int			get_height(char **map);
// int		 ft_strcmp(const char *s1, const char *s2);
char		*skip_spaces(char *line);

# endif
#endif
