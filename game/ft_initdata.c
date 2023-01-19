/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:07 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:09 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	init_game_sub2(t_game *game)
{
	game->map_height = 0;
	game->map_width = 0;
	game->player = '\0';
	game->c[0] = -1;
	game->f[0] = -1;
	game->mouse = '\0';
	game->is_key = '0';
	game->sprite = '0';
	game->sprite_state = '1';
	game->key_py = 1;
	game->key_px = 0;
	game->d_x = -1;
	game->d_y = -1;
	game->angle = 60.0 / WIDTH;
}

void	init_game(t_game *game)
{
	int	array_counter;

	array_counter = -1;
	game->ea = NULL;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->img = NULL;
	game->line = NULL;
	game->map = NULL;
	game->win = NULL;
	game->door = NULL;
	game->minimap = NULL;
	game->key = NULL;
	game->key2 = NULL;
	game->mlx = NULL;
	while (array_counter < 9)
	{
		array_counter++;
		game->addr[array_counter] = NULL;
	}
	init_game_sub2(game);
}
