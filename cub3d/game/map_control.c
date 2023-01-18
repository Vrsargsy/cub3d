/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:32 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:33 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_wall_control(char *s, t_game *game)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] != '1')
		p_error("Error! Map content is invalid!\n", game);
	while (s[i] == ' ' || s[i] == '1')
		i++;
	if (s[i] && s[i] != '\n')
		p_error("Error! Map content is invalid!\n", game);
}

void	algorithm_door_key(char *s1, char *s2, char *s3, t_game *game)
{
	int	i;

	i = game->zeros;
	if (s2[i - 1] == ' ' || s2[i + 1] == ' ' || !s2[i + 1]
		|| s2[i + 1] == '\n' || s1[i + 1] == '\n' || !s1[i + 1]
		|| s1[i - 1] == ' ' || s1[i + 1] == ' ' || s1[i] == ' '
		|| s3[i - 1] == ' ' || s3[i + 1] == ' ' || s3[i] == ' '
		|| s3[i + 1] == '\n' || !s3[i + 1])
		p_error("Invalid Map!\n", game);
	if (s2[i] == '0' && s2[i + 1] == '1' && s2[i - 1] == '1'
		&& s1[i] == '0' && s3[i] == '0' && (s1[i + 1] == '1'
			|| s3[i + 1] == '1'))
		s2[i] = 'D';
	else if (game->is_key == '0' && s2[i] == '0' && s2[i - 1] == '0'
		&& s2[i + 1] == '0' && s1[i - 1] == '0' && s1[i] == '0'
		&& s1[i + 1] == '0' && s3[i] == '0' && s3[i + 1] == '0'
		&& s3[i - 1] == '0')
	{
		game->is_key = '1';
		s2[i] = 'K';
		game->key_px = i;
	}
}

void	ft_check_maplines(char *s, char *s2, char *s3, t_game *game)
{
	int	i;

	i = 0;
	while (s2[i] && s2[i] == ' ')
		i++;
	if (s2[i] != '1')
		p_error("Error! Map is invalid.\n", game);
	while (s2 && s2[i] && s2[i] != '\n')
	{
		while (s2[i] && (s2[i] == ' ' || s2[i] == '1'))
			i++;
		if (s2[i] && s2[i] != '\n')
		{
			game->zeros = i;
			algorithm_door_key(s, s2, s3, game);
			i++;
		}
	}
}

void	map_control(t_list	*map, t_game *game)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = map->next;
	if (!tmp)
		p_error("Error! Map is invalid.\n", game);
	tmp2 = tmp->next;
	while (tmp)
	{
		if (map == game->map)
			ft_wall_control(map->content, game);
		if (tmp2 == NULL)
		{
			ft_wall_control(tmp->content, game);
			return ;
		}
		ft_check_maplines(map->content, tmp->content, tmp2->content, game);
		map = map->next;
		tmp = tmp->next;
		tmp2 = tmp2->next;
		if (game->is_key == '0')
		{
			game->key_py++;
		}	
	}
}
