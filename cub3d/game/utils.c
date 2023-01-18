/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:10:00 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:10:01 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	put_pixel(t_game *a, int x, int y, int clr)
{
	char	*dst;

	dst = a->addr[1] + ((y * a->line_length[0])
			+ x * (a->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = clr;
}

void	timer(t_game *game)
{
	game->loop += 1;
	if (game->loop % 20 == 0)
	{
		if (game->sprite_state == '1')
			game->sprite_state = '2';
		else
			game->sprite_state = '1';
	}
	if (game->loop == 401)
		game->loop = 1;
}
