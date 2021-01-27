/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:54:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/26 17:13:48 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"
# include "../includes/mlx/mlx.h"
# include "../includes/libft/libft.h"
# include "get_next_line.h"
# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF

typedef struct	s_data
{
	int			width;
	int			height;
	int			bits_per_pxl;
	int			line_length;
	int			endian;
	int			width_verif;
	int			height_verif;
	int			r_sky;
	int			g_sky;
	int			b_sky;
	int			r_ground;
	int			g_ground;
	int			b_ground;
	char		*addr;
	char		*path_sprite;
	char		*path_north;
	char		*path_south;
	char		*path_east;
	char		*path_west;
	int			r_sky_verif;
	int			g_sky_verif;
	int			b_sky_verif;
	int			r_ground_verif;
	int			g_ground_verif;
	int			b_ground_verif;
	int			path_sprite_verif;
	int			path_north_verif;
	int			path_south_verif;
	int			path_east_verif;
	int			path_west_verif;
	void		*mlx;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			**map;
	int			parsed;
	int			line_map;
	t_list		*lst_line;
	t_list		*first_token;
}				t_data;

typedef struct	s_map
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			width;
	int			width2;
	int			height;
	int			height2;
	int			height_tmp;
	int			**real_map;
	int			color_r;
	int			color_g;
	int			color_b;
	int			position;
	int			**actual_pos;
	int			stock_c;
}				t_map;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_pos
{
	int			i;
	t_vec		dir;
	t_vec		plane_cam;
	t_vec		camera;
	double		ttime;
	double		oldtime;
	double		newtime;
}				t_pos;

typedef struct	s_ray
{
	t_vec		dir;
}				t_ray;

typedef struct	s_move
{
	int			hit; //wall hit?
	int			side; //hit = N/S or E/W?
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		perp_wall_dist; //len of ray from one x/y to next x/y
	t_vec		map; //wich box of the map we're in
	t_vec		step; //direction of the step (x/y)(+1/-1)
	t_vec		d_dist; //len of ray from one x/y to next x/y
	t_vec		side_dist; //len of ray from current pos to next x/y-side
}				t_move;

/*
** PARSING/MAIN.C
*/

int					main(int ac, char const **av);
int					ft_error_msg(char *s);
void				ft_error_exit(char *s);

/*
** PARSING/PARSING.C
*/

t_data				*ft_data(char *file, int ac, t_map *map, t_pos *pos, t_data *data);
int					ft_get_data(t_data *data, char *file, t_map *map, t_pos *pos);
int					ft_gnl(int fd, char *line, t_data *data, t_map *map, t_pos *pos);
int					ft_parsing_data(t_list *el, t_data *data, t_map *map, t_pos *pos);

/*
** PARSING/SPRITES_PATH/RESOLUTION.C
*/

int					ft_resolution(t_data *data, char *line);
void				ft_error_resolution_1(char *line);
unsigned long int	ft_uli_error(const char *line);
void				ft_error_resolution_3(char *line);
void				ft_error_resolution_4(char *line);

/*
** PARSING/SPRITES_PATH/OBSTACLE.C
*/

int					ft_sprite(t_data *data, char *line);

/*
** PARSING/SPRITES_PATH/SKY.C
*/

int					ft_color_sky(t_data *data, char *line);
void				ft_error_skyground_1(char *line);
void				ft_empty_line(char *strs);
t_data				*ft_error_skyg_2(t_data *data);

/*
** PARSING/SPRITES_PATH/GROUND.C
*/

int					ft_color_ground(t_data *data, char *line);
t_data				*ft_error_ground(t_data *data);
void				ft_error_skyground_5(t_data *data);
char				**split_rgb_ground(char *line);
void				ft_error_skyground_6(char **strs);

/*
** PARSING/SPRITES_PATH/DIRECTIONS.C
*/

int					ft_north(t_data *data, char *line);
int					ft_south(t_data *data, char *line);
int					ft_west(t_data *data, char *line);
int					ft_east(t_data *data, char *line);

/*
** PARSING/MAP_PARSING/MAP.C
*/

int					ft_map(t_list *el, t_data *data, t_map *map, t_pos *pos);
t_map				*ft_get_map_hw(t_map *map, t_list *el, t_data *data);
t_map				*ft_map_data(t_map *map, t_list *el, t_pos *pos);
t_map				*ft_map_asign(t_list *el, t_map *map, t_pos *pos);
void				ft_position_asign(int c, t_map *map, t_pos *pos);

/*
** PARSING/MAP_PARSING/VERIF_MAP.C
*/

int					ft_verif_map(t_map *map);
int					ft_verif_char(t_map *map);
int					ft_verif_holes(t_map *map);
void				ft_verif_holes_2(t_map *map, int i, int j);
void				ft_dir_to_vec(int c, t_pos *pos);

/*
** VISUALS/TIME.C
*/

void				ft_time_diff(t_pos *pos);

/*
** PARSING/EVENT.C
*/

int					ft_event(t_data *data);
int					ft_exit_hook(void *x);

/*
** PARSING/FREE.C
*/

void				ft_free_data(t_data *data, char *str);

void				ft_mlx_pxl_put(t_data *data, int x, int y, int color);

#endif
