/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:57 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:57 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	put_sprite_pixel(t_game *game, int x, int y)
{
	char	*dst;
	int		i;
	int		j;

	i = (int)game->t_x;
	j = (int)game->t_y;
	if (game->sprite_state == '1')
		dst = game->addr[7] + ((j * game->line_length[7])
				+ i * (game->bits_per_pixel[7] / 8));
	else
		dst = game->addr[8] + ((j * game->line_length[8])
				+ i * (game->bits_per_pixel[8] / 8));
	if (*(unsigned int *)dst != 0x000FF00FF)
		my_mlx_pixel_put(game, x, y, *(unsigned int *)dst);
}

void	init_game_sprite(t_game *game)
{
	t_sprite	spr;

	if (game->sprite == '0')
		return ;
	game->sx = (game->key_px - game->px) * 64;
	game->sy = (game->key_py - game->py) * 64;
	spr.z = 10;
	spr.cos = cos(degree_to_radian(game->pa));
	spr.sin = sin(degree_to_radian(game->pa));
	spr.x = game->sy * spr.cos + game->sx * spr.sin;
	spr.y = game->sx * spr.cos - game->sy * spr.sin;
	game->b = spr.y;
	game->sx = spr.x * 800 / spr.y + (WIDTH / 2);
	game->sy = spr.z * 800 / spr.y + (HEIGHT / 2);
	game->spr_scale = 5 * HEIGHT / game->b;
	if (game->spr_scale < 0)
		game->spr_scale = 0;
	else if (game->spr_scale > WIDTH / 2)
		game->spr_scale = WIDTH / 2;
	game->t_x = 0;
	game->t_x_step = 63.0 / game->spr_scale;
	game->t_y_step = 64.0 / game->spr_scale;
}

void	draw_sprite(t_game *game, int i)
{
	double	y;

	if (game->sprite == '0')
		return ;
	if (i >= (game->sx - game->spr_scale / 2)
		&& i < (game->sx + game->spr_scale / 2)
		&& game->b > 0 && game->b < game->dist)
	{
		game->t_y = 62;
		y = 0;
		while (y < game->spr_scale)
		{
			put_sprite_pixel(game, i, game->sy - y);
			game->t_y -= game->t_y_step;
			if (game->t_y < 0)
				game->t_y = 0;
			y++;
		}
		game->t_x += game->t_x_step;
	}
}
