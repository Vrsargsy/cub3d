/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put_syms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:21 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:22 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"	

void	put_map_sym(int mx, int my, t_game *game, char c)
{
	char	*str;
	t_list	*map;

	if (mx < 0 || my < 0)
		return ;
	map = game->map;
	while (my > 0)
	{
		my--;
		map = map->next;
	}
	str = map->content;
	str[mx] = c;
}

char	get_map_sym(int mx, int my, t_game *game)
{
	t_list	*map;
	char	*s;

	if (mx < 0 || my < 0 || mx >= game->map_width || my >= game->map_height)
		return (' ');
	map = game->map;
	while (my > 0)
	{
		my--;
		map = map->next;
	}
	s = map->content;
	return (s[mx]);
}
