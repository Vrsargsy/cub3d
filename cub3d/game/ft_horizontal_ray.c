/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:01 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:02 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_horizontal_dist_check(t_game *game, t_ray *ray, char c)
{
	double	disth;

	disth = calc_dist(ray);
	if (disth < game->dist)
	{
		game->zeros = ray->zerosh;
		if (c == 'D')
			game->zeros = 6;
		game->dist = disth;
	}
	else
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
	}
	ray->depth = game->map_height;
}

void	ft_horizontal_ray_2(t_game *game, t_ray *ray)
{
	int		mx;
	int		my;
	char	c;

	if (sin(degree_to_radian(ray->ra)) < 0.0001
		&&sin(degree_to_radian(ray->ra)) > -0.0001)
	{
		ray->depth = game->map_height;
		ray->rx = ray->px;
		ray->ry = ray->py;
	}
	while (ray->depth < game->map_height)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		c = get_map_sym(mx, my, game);
		if (c == '1' || c == 'D')
			ft_horizontal_dist_check(game, ray, c);
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->depth += 1;
		}
	}
}

void	ft_horizontal_ray(t_game *game, t_ray *ray)
{
	ray->atan_ra = 1.0 / tan(degree_to_radian(ray->ra));
	ray->depth = 0;
	if (sin(degree_to_radian(ray->ra)) > 0.0001)
	{
		ray->zerosh = 2;
		ray->ry = (((int)ray->py >> 6) << 6) - 0.0001;
		ray->rx = (ray->py - ray->ry) * ray->atan_ra + ray->px;
		ray->yo = -64;
		ray->xo = 64 * ray->atan_ra;
	}
	else if (sin(degree_to_radian(ray->ra)) < -0.0001)
	{
		ray->zerosh = 3;
		ray->ry = (((int)ray->py >> 6) << 6) + 64;
		ray->rx = (ray->py - ray->ry) * ray->atan_ra + ray->px;
		ray->yo = 64;
		ray->xo = -64 * ray->atan_ra;
	}
	ft_horizontal_ray_2(game, ray);
}

void	raycast(t_game *game, t_ray *ray)
{
	int		i;

	ray->ra = replace_angle_360(game->pa + 30);
	i = 0;
	ray->px = game->px * 64;
	ray->py = game->py * 64;
	while (i < WIDTH)
	{
		game->dist = 1000000;
		vert_ray(game, ray);
		ft_horizontal_ray(game, ray);
		game->dist = game->dist * cos(degree_to_radian
				(replace_angle_360(game->pa - ray->ra)));
		if (game->zeros > 3 && game->zeros != 6)
			game->ray = (int)(ray->vy) % 64;
		else
			game->ray = (int)(ray->rx) % 64;
		draw_line(game, i);
		draw_sprite(game, i);
		ray->ra = replace_angle_360(ray->ra - game->angle);
		i++;
	}
}
