/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:10:17 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:10:18 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game);
		if (!is_valid_map(argv[1], ".cub"))
			p_error("Map format is invalid!\n", &game);
		check_map(&game, argv[1]);
		render_game(&game);
	}
	else
		ft_putstr_fd("Error!\nProgramm accept only one argument!\n", 2);
	return (1);
}
