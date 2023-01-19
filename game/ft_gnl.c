/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:08:52 by vrsargsy          #+#    #+#             */
/*   Updated: 2023/01/15 22:08:53 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*gnl(int fd)
{
	int		rd;
	int		i;
	char	c;
	char	*buffer;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 100000);
	rd = read(fd, &c, 1);
	while (rd > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
		rd = read(fd, &c, 1);
	}
	if (rd == -1 || (rd == 0 && !buffer[i - 1]))
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
