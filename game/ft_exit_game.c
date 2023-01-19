/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:08:23 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:08:24 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(EXIT_SUCCESS);
}
