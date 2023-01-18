/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:08:28 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:08:32 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	free_list(t_list *map)
{
	t_list	*tmp;

	if (!map)
		return ;
	tmp = map;
	while (map)
	{
		if (tmp->content)
			free(tmp->content);
		tmp->content = NULL;
		tmp = tmp->next;
		free(map);
		map = tmp;
	}
}

void	free_game_addr(char **addr)
{
	int	i;

	if (addr == NULL)
		return ;
	i = 0;
	while (i < 9)
	{
		free(addr[i]);
		addr[i] = NULL;
		i++;
	}
}

void	free_game(t_game *game)
{
	free_list(game->map);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	free(game->mlx);
	free_game_addr(game->addr);
	free(game->line);
}
