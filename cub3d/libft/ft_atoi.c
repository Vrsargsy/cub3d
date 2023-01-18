/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:00:21 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 17:33:59 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				id;
	int					negative;
	unsigned long int	res;

	id = 0;
	negative = 1;
	res = 0;
	while ((str[id] == ' ' || str[id] == '\t')
		|| (str[id] == '\n' || str[id] == '\f')
		|| (str[id] == '\v' || str[id] == '\r'))
		id++;
	if (str[id] == '+' || str[id] == '-')
		if (str[id++] == '-')
			negative *= -1;
	while (ft_isdigit(str[id]))
	{
		res *= 10;
		res += str[id] - '0';
		id++;
	}
	return (res * negative);
}
