/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:42 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:42 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double	degree_to_radian(double degree)
{
	return (degree * 3.14159 / 180.0);
}

double	replace_angle_360(double degree)
{
	if (degree >= 360)
		degree = degree - 360;
	else if (degree <= -1)
		degree = degree + 360;
	return (degree);
}

double	calc_dist(t_ray *ray)
{
	double	x;

	x = cos(degree_to_radian(ray->ra)) * (ray->rx - ray->px)
		- sin(degree_to_radian(ray->ra)) * (ray->ry - ray->py);
	return (x);
}
