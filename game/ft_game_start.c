/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:08:44 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:08:46 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_map_render(t_game *game)
{
	t_ray		ray;

	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
	{
		write(2, "Error\nImage couldn't be created!\n", 32);
		exit_game(game);
	}
	game->addr[1] = mlx_get_data_addr(game->img, &game->bits_per_pixel[1],
			&game->line_length[1], &game->endian[1]);
	init_game_sprite(game);
	raycast(game, &ray);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	start_game(t_game *game)
{
	int	x;

	timer(game);
	ft_map_render(game);
	render_minimap(game->map, game);
	x = game->mouse_x;
	if (game->mouse_x > x)
		r_key(game);
	else if (game->mouse_x < x)
		l_key(game);
	if (game->is_open == '1' && game->step_num > 20
		&& ((int)game->px != game->d_x || (int)game->py != game->d_y))
		put_map_sym(game->d_x, game->d_y, game, 'D');
	return (0);
}
