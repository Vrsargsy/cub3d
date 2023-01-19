/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:08:18 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:08:19 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	p_error(char *str, t_game *game)
{
	free_game(game);
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
