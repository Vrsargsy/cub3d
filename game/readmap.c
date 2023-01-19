/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:49 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:50 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_textures_read(t_game *game, char *line, char c)
{
	char	*tmp;

	if ((c == 'N' && game->no) || (c == 'S' && game->so)
		|| (c == 'W' && game->we) || (c == 'E' && game->ea))
		p_error("Error!\n", game);
	tmp = ft_strtrim(line, "\n");
	if (c == 'N')
		game->no = ft_strtrim(tmp, " ");
	else if (c == 'S')
		game->so = ft_strtrim(tmp, " ");
	else if (c == 'W')
		game->we = ft_strtrim(tmp, " ");
	else if (c == 'E')
		game->ea = ft_strtrim(tmp, " ");
	free(tmp);
}

int	ft_floorceiling_read_2(char *line, int j, t_game *a)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ','
		&& (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '\t'))
		i++;
	if (j < 2 && line[i] != ',')
		p_error("Error! RGB format is invalid.\n", a);
	if (j == 2 && line[i] && line[i] != '\n'
		&& line[i] != ' ' && line[i] != '\t')
		p_error("Error! RGB format is invalid.\n", a);
	return (i);
}

void	ft_floorceiling_read(t_game *game, char *line, char c)
{
	int		i;
	char	*tmp;
	int		j;

	j = 0;
	while (line && (*line == ' ' || *line == '\t'))
		line++;
	while (j < 3)
	{
		i = ft_floorceiling_read_2(line, j, game);
		tmp = ft_substr(line, 0, i);
		if (line[i] == ',')
			line++;
		line = line + i;
		i = ft_atoi(tmp);
		free(tmp);
		if (i > 255 || i < 0)
			p_error("Error! Colour value can be in between 0-255\n", game);
		if (c == 'C')
			game->c[j] = i;
		else if (c == 'F')
			game->f[j] = i;
		j++;
	}
}

void	read_map(t_game *a, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		ft_textures_read(a, line + 2, 'N');
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ft_textures_read(a, line + 2, 'S');
	else if (line[i] == 'W' && line[i + 1] == 'E')
		ft_textures_read(a, line + i + 2, 'W');
	else if (line[i] == 'E' && line[i + 1] == 'A')
		ft_textures_read(a, line + i + 2, 'E');
	else if (line[i] == 'F')
		ft_floorceiling_read(a, line + i + 1, 'F');
	else if (line[i] == 'C')
		ft_floorceiling_read(a, line + i + 1, 'C');
	else if (line[i] == '1')
		init_map(line, a, fd);
	else if (line[i] && line[i] != '\n')
		p_error("Map is invalid!\n", a);
}
