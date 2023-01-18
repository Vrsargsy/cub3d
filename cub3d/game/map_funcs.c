/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:38 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:39 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	fill_with_rows(t_game *game)
{
	char	*tmp;
	int		i;

	while (game->map_height < 10)
	{
		i = 0;
		tmp = malloc(game->map_width + 1);
		while (i < game->map_width)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		ft_lstadd_back(&game->map, ft_lstnew(tmp));
		game->map_height++;
	}
}

void	complete_to_rect(t_list *map, t_game *game)
{
	char	*tmp;

	if (game->map_width < 10)
		game->map_width = 10;
	while (map)
	{
		while ((int)ft_strlen(map->content) < game->map_width)
		{
			tmp = map->content;
			map->content = ft_strjoin(map->content, " ");
			free(tmp);
		}
		map = map->next;
	}
	if (game->map_height < 10)
		fill_with_rows(game);
}

int	ft_player_position(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			if (game->player != '\0')
				p_error("Error!\n", game);
			game->player = line[i];
			game->px = i + 0.5;
			game->py = game->map_height + 0.5;
			line[i] = '0';
		}
		else if (line[i] != ' ' && line[i] != '1' && line[i] != '0')
			p_error("Error!\n", game);
		i++;
	}
	return (i);
}

void	init_map(char *line, t_game *game, int fd)
{
	int		i;

	while (line)
	{
		i = 0;
		while (line[i] && line[i] == ' ')
			i++;
		if (!line[i] || line[i] == '\n')
		{
			free(line);
			game->line = NULL;
			break ;
		}
		i = ft_player_position(line, game);
		if (i > game->map_width)
			game->map_width = i;
		ft_lstadd_back(&game->map, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
		game->line = NULL;
		line = gnl(fd);
		game->map_height++;
	}
	map_control(game->map, game);
	complete_to_rect(game->map, game);
}

void	check_map(t_game *game, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		p_error("File could not found!\n", game);
	game->line = gnl(fd);
	if (!game->line)
		p_error("Map format is invalid!\n", game);
	while (game->line)
	{
		read_map(game, game->line, fd);
		if (!game->line)
			break ;
		free(game->line);
		game->line = gnl(fd);
	}
	close(fd);
	if (game->map == NULL)
		p_error("Given map rules are not valid!\n", game);
}
