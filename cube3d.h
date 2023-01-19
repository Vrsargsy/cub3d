/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:10:29 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:10:30 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define HEIGHT   1000
# define WIDTH    1000
# define KEYS     '0'

# include "libft/libft.h"
# include "minilibx/mlx.h"
//# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_ray {
	int		depth;
	double	xo;
	double	yo;
	double	ra;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	double	px;
	double	py;
	double	rx;
	double	ry;
	int		zeros;
	int		zerosh;
	double	atan_ra;
	double	tan_ra;
}				t_ray;

typedef struct s_sprite {
	double	x;
	double	y;
	double	z;
	double	sin;
	double	cos;
}				t_sprite;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	void	*minimap;
	void	*key;
	void	*key2;
	void	*door;
	char	*addr[9];
	int		bits_per_pixel[9];
	int		line_length[9];
	int		endian[9];
	int		c[3];
	int		f[3];
	char	*line;
	char	player;
	double	map_width;
	double	map_height;
	int		mouse_x;
	int		mouse_y;
	char	mouse;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	dist;
	int		zeros;
	int		ray;
	double	stepy;
	int		linelen;
	char	is_key;
	int		d_x;
	int		d_y;
	int		step_num;
	char	is_open;
	char	sprite;
	double	key_px;
	double	key_py;
	double	spr_scale;
	double	t_x;
	double	t_y;
	double	t_x_step;
	double	t_y_step;
	double	b;
	double	sy;
	double	sx;
	double	angle;
	int		loop;
	char	sprite_state;
	t_list	*map;
}				t_game;

void	p_error(char *s, t_game *game);
void	free_game(t_game *game);
int		exit_game(t_game *game);
void	free_list(t_list *map);
void	check_map(t_game *game, char *argv);
void	read_map(t_game *game, char *line, int fd);
void	map_control(t_list	*tmp, t_game *game);
void	init_map(char *line, t_game *game, int fd);
void	init_game(t_game *game);
void	render_minimap(t_list *map, t_game *game);
void	put_pixel(t_game *game, int x, int y, int clr);
void	init_game_sprite(t_game *game);
void	draw_sprite(t_game *game, int i);
int		start_game(t_game *game);
void	render_game(t_game *game);
int		key_hooks(int key, t_game *game);
void	raycast(t_game *game, t_ray *ray);
void	vert_ray(t_game *game, t_ray *ray);
void	draw_line(t_game *game, int i);
char	get_map_sym(int mx, int my, t_game *game);
void	put_map_sym(int mx, int my, t_game *game, char c);
void	my_mlx_pixel_put(t_game *game, int x, int y, int clr);
double	calc_dist(t_ray *ray);
double	degree_to_radian(double game);
double	replace_angle_360(double game);
void	l_key(t_game *game);
void	r_key(t_game *game);
void	key_e(t_game *game);
void	timer(t_game *game);
int		is_valid_map(char *str, char *s2);
void	p_error(char *str, t_game *game);
void	free_game(t_game *game);
char	*gnl(int fd);
//char	*get_next_line(int fd);
#endif
