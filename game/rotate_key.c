/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:53 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:54 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	r_key(t_game *a)
{
	a->pa -= 5;
	a->pa = replace_angle_360(a->pa);
	a->pdx = cos(degree_to_radian(a->pa));
	a->pdy = -1 * sin(degree_to_radian(a->pa));
}

void	l_key(t_game *a)
{
	a->pa += 5;
	a->pa = replace_angle_360(a->pa);
	a->pdx = cos(degree_to_radian(a->pa));
	a->pdy = -1 * sin(degree_to_radian(a->pa));
}

void	key_e(t_game *game)
{
	int		my;
	int		mx;

	mx = game->px + (game->pdx * 0.5);
	my = game->py + (game->pdy * 0.5);
	if (get_map_sym(mx, my, game) == 'D' && game->is_key == '1')
	{
		game->d_x = mx;
		game->d_y = my;
		put_map_sym(mx, my, game, '0');
		game->is_open = '1';
		game->step_num = 1;
	}
	else if (mx == game->d_x && my == game->d_y && game->is_key == '1'
		&& ((int)game->px != game->d_x || (int)game->py != game->d_y))
	{
		if (game->is_open == '1')
		{
			game->is_open = '0';
			put_map_sym(mx, my, game, 'D');
		}
	}
}
