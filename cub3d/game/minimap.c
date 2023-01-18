/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:45 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:47 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_wall_minimap(t_game *game, int x, int y, int k)
{
	int	j;
	int	i;

	i = 0;
	while (i <= WIDTH / 50)
	{
		j = 0;
		while (j <= HEIGHT / 50)
		{
			if (i == 0 || j == 0)
				put_pixel(game, i + x * WIDTH / 50,
					j + y * HEIGHT / 50, 0x0FF000000);
			else
				put_pixel(game, i + x * WIDTH / 50,
					j + y * HEIGHT / 50, k);
			j++;
		}
		i++;
	}
}

void	ft_player_minimap(t_game *game, double x, double y)
{
	double	j;
	double	i;

	i = 0.5 - WIDTH / 250;
	while (i <= WIDTH / 250)
	{
		j = 0.5 - HEIGHT / 250;
		while (j <= WIDTH / 250)
		{
			put_pixel(game, i + x * WIDTH / 50,
				j + y * HEIGHT / 50, 0x9c0606);
			j++;
		}
		i++;
	}
}

void	ft_player_init(t_game *game)
{
	double	x;
	double	y;

	if (game->px < 5)
		x = game->px;
	else if (game->map_width - game->px < 5)
		x = 10 - (game->map_width - game->px);
	else
		x = 4 + (game->px - (int)game->px);
	if (game->py < 5)
		y = game->py;
	else if (game->map_height - game->py < 5)
		y = 10 - (game->map_height - game->py);
	else
		y = 5 + (game->py - (int)game->py);
	ft_player_minimap(game, x, y);
}

void	ft_sub_minimap(t_list *map, t_game *game, double x)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while (map && j < 10)
	{
		line = map->content;
		i = 0;
		while (line[(int)x + i] && i < 10)
		{
			if (line[(int)x + i] == '1')
				ft_wall_minimap(game, i, j, 0x2202f2);
			else if (line[(int)x + i] == 'D')
				ft_wall_minimap(game, i, j, 0x038a30);
			else
				ft_wall_minimap(game, i, j, 0x00000000);
			i++;
		}
		j++;
		map = map->next;
	}
	ft_player_init(game);
}

void	render_minimap(t_list *map, t_game *game)
{
	double	y;
	double	x;

	if (game->minimap)
		mlx_destroy_image(game->mlx, game->minimap);
	game->minimap = mlx_new_image(game->mlx, WIDTH / 5, HEIGHT / 5);
	game->addr[1] = mlx_get_data_addr(game->minimap, &game->bits_per_pixel[0],
			&game->line_length[0], &game->endian[0]);
	y = 0;
	while (game->map_height > 11 && game->py > y + 6
		&& game->map_height > y + 10)
	{
		map = map->next;
		y++;
	}
	if (game->map_width < 11 || game->px <= 4)
		x = 0;
	else if (game->map_width - game->px <= 6)
		x = game->map_width - 10;
	else
		x = game->px - 4;
	ft_sub_minimap(map, game, x);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap, 0, 0);
}
