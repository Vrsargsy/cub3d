/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:13 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:14 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	key_a(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->px + (game->pdy * 0.2);
	my = game->py - (game->pdx * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
		{
			game->is_key = '1';
			game->sprite = '0';
			put_map_sym(mx, my, game, '0');
		}
		game->px += (game->pdy * 0.1);
		game->py -= (game->pdx * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

void	key_w(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->px + (game->pdx * 0.2);
	my = game->py + (game->pdy * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
		{
			game->is_key = '1';
			game->sprite = '0';
			put_map_sym(mx, my, game, '0');
		}
		game->px += (game->pdx * 0.1);
		game->py += (game->pdy * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

void	d_key(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->px - (game->pdy * 0.2);
	my = game->py + (game->pdx * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
		{
			game->is_key = '1';
			game->sprite = '0';
			put_map_sym(mx, my, game, '0');
		}
		game->px -= (game->pdy * 0.1);
		game->py += (game->pdx * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

void	key_s(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->px - (game->pdx * 0.2);
	my = game->py - (game->pdy * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
		{
			game->is_key = '1';
			game->sprite = '0';
			put_map_sym(mx, my, game, '0');
		}
		game->px -= (game->pdx * 0.1);
		game->py -= (game->pdy * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

int	key_hooks(int keyboard, t_game *game)
{
	if (keyboard == 13)
		key_w(game);
	else if (keyboard == 0)
		key_a(game);
	else if (keyboard == 1)
		key_s(game);
	else if (keyboard == 2)
		d_key(game);
	else if (keyboard == 14)
		key_e(game);
	else if (keyboard == 53)
		exit_game(game);
	else if (keyboard == 123)
		l_key(game);
	else if (keyboard == 124)
		r_key(game);
	return (0);
}
