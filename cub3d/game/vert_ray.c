/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:10:03 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:10:04 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_vertical_dist_check(t_game *game, t_ray *ray, char c)
{
	game->dist = calc_dist(ray);
	game->zeros = ray->zeros;
	if (c == 'D')
		game->zeros = 6;
	ray->depth = game->map_width;
}

void	vert_ray_2(t_game *game, t_ray *ray)
{
	int		mx;
	int		my;
	char	val;

	while (ray->depth < game->map_width)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		val = get_map_sym(mx, my, game);
		if (val == '1' || val == 'D')
			ft_vertical_dist_check(game, ray, val);
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->depth += 1;
		}
	}
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}

void	vert_ray(t_game *game, t_ray *ray)
{
	ray->tan_ra = tan(degree_to_radian(ray->ra));
	ray->depth = 0;
	if (cos(degree_to_radian(ray->ra)) > 0.0001)
	{
		ray->zeros = 5;
		ray->rx = (((int)ray->px >> 6) << 6) + 64;
		ray->ry = (ray->px - ray->rx) * ray->tan_ra + ray->py;
		ray->xo = 64;
		ray->yo = -64 * ray->tan_ra;
	}
	else if (cos(degree_to_radian(ray->ra)) < -0.0001)
	{
		ray->zeros = 4;
		ray->rx = (((int)ray->px >> 6) << 6) - 0.0001;
		ray->ry = (ray->px - ray->rx) * ray->tan_ra + ray->py;
		ray->xo = -64;
		ray->yo = 64 * ray->tan_ra;
	}
	else if (cos(degree_to_radian(ray->ra)) == 0)
	{
		ray->depth = game->map_width;
		ray->rx = ray->px;
		ray->ry = ray->py;
	}
	vert_ray_2(game, ray);
}
