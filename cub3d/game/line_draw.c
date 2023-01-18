/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:27 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:28 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int clr)
{
	char	*dst;

	dst = game->addr[1] + ((y * game->line_length[1]) + x
			* (game->bits_per_pixel[1] / 8));
	*(unsigned int *)dst = clr;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_texture_pixel(t_game *game, int x, int y, int k)
{
	char	*dst;
	int		i;
	int		j;

	if (game->linelen == 0)
		return ;
	i = game->ray;
	k = k + game->stepy;
	j = (k << 6) / game->linelen;
	dst = game->addr[game->zeros] + ((j * game->line_length[game->zeros])
			+ i * (game->bits_per_pixel[game->zeros] / 8));
	my_mlx_pixel_put(game, x, y, *(unsigned int *)dst);
}

void	draw_line_2(t_game *game, int i, int lineh, int lineoff)
{
	int	k;
	int	y;

	k = -1;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < lineoff)
			my_mlx_pixel_put(game, i, y,
				create_trgb(0, game->c[0], game->c[1], game->c[2]));
		else if (y > lineh + lineoff)
			my_mlx_pixel_put(game, i, y,
				create_trgb(0, game->f[0], game->f[1], game->f[2]));
		else
			put_texture_pixel(game, i, y, k++);
		y++;
	}
}

void	draw_line(t_game *game, int i)
{
	int	lineh;
	int	lineoff;

	lineh = (HEIGHT << 5) / game->dist;
	game->stepy = 0;
	game->linelen = lineh;
	if (lineh > HEIGHT)
	{
		game->stepy = ((lineh - HEIGHT) >> 1);
		lineh = HEIGHT;
	}
	lineoff = (HEIGHT - lineh) >> 1;
	draw_line_2(game, i, lineh, lineoff);
}
