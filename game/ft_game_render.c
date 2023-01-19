/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:08:38 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:08:39 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_get_data_addr(t_game *game)
{
	if (!game->ea || !game->so || !game->we || !game->no || \
		!game->key || !game->door || !game->key2)
	{
		write(2, "Error! Image file could not found!\n", 35);
		free_list(game->map);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	game->addr[2] = mlx_get_data_addr(game->no, &game->bits_per_pixel[2],
			&game->line_length[2], &game->endian[2]);
	game->addr[3] = mlx_get_data_addr(game->so, &game->bits_per_pixel[3],
			&game->line_length[3], &game->endian[3]);
	game->addr[4] = mlx_get_data_addr(game->we, &game->bits_per_pixel[4],
			&game->line_length[4], &game->endian[4]);
	game->addr[5] = mlx_get_data_addr(game->ea, &game->bits_per_pixel[5],
			&game->line_length[5], &game->endian[5]);
	game->addr[6] = mlx_get_data_addr(game->door, &game->bits_per_pixel[6],
			&game->line_length[6], &game->endian[6]);
	game->addr[7] = mlx_get_data_addr(game->key, &game->bits_per_pixel[7],
			&game->line_length[7], &game->endian[7]);
	game->addr[8] = mlx_get_data_addr(game->key2, &game->bits_per_pixel[8],
			&game->line_length[8], &game->endian[8]);
}

void	file_to_image(t_game *game)
{
	int		i;
	char	*tmp;

	i = 64;
	tmp = game->no;
	game->no = mlx_xpm_file_to_image(game->mlx, game->no, &i, &i);
	free(tmp);
	tmp = game->so;
	game->so = mlx_xpm_file_to_image(game->mlx, game->so, &i, &i);
	free(tmp);
	tmp = game->we;
	game->we = mlx_xpm_file_to_image(game->mlx, game->we, &i, &i);
	free(tmp);
	tmp = game->ea;
	game->ea = mlx_xpm_file_to_image(game->mlx, game->ea, &i, &i);
	free(tmp);
	game->door = mlx_xpm_file_to_image(game->mlx, "t/door.xpm", &i, &i);
	game->key = mlx_xpm_file_to_image(game->mlx, "t/key_left.xpm", &i, &i);
	game->key2 = mlx_xpm_file_to_image(game->mlx, "t/key_right.xpm", &i, &i);
	ft_get_data_addr(game);
}

void	ft_player_game_control(t_game *game)
{
	if (game->player == '\0')
		p_error("Error! Position of player is not found!\n", game);
	if (game->player == 'E')
		game->pa = 0;
	else if (game->player == 'N')
		game->pa = 90;
	else if (game->player == 'W')
		game->pa = 180;
	else if (game->player == 'S')
		game->pa = 270;
}

void	ft_map_game_control(t_game *game)
{
	if (game->no == NULL)
		p_error("Error! Texture for 'NO' is not found!\n", game);
	if (game->ea == NULL)
		p_error("Error! Texture for 'EA' is not found!\n", game);
	if (game->we == NULL)
		p_error("Error! Texture for 'WE' is not found!\n", game);
	if (game->so == NULL)
		p_error("Error! Texture for 'SO' is not found!\n", game);
	if (game->c[0] < 0)
		p_error("Error! For ceiling RGB is not found!\n", game);
	if (game->f[0] < 0)
		p_error("Error! For floor RGB is not found!\n", game);
	if (!game->map)
		p_error("Error! Map is not found!\n", game);
	ft_player_game_control(game);
}

void	render_game(t_game *game)
{
	ft_map_game_control(game);
	game->pdx = cos(degree_to_radian(game->pa));
	game->pdy = -1 * sin(degree_to_radian(game->pa));
	if (game->is_key == '1')
	{
		game->sprite = '1';
		game->is_key = '0';
	}
	game->key_px += 0.5;
	game->key_py += 0.5;
	game->mlx = mlx_init();
	file_to_image(game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cube3d");
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 0, key_hooks, game);
	mlx_loop_hook(game->mlx, start_game, game);
	mlx_loop(game->mlx);
}
