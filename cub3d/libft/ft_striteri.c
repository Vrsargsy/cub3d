/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:23:53 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 18:30:20 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{	
	unsigned int	i;

	i = -1;
	if (!s || !f)
		return ;
	while (s[++i])
		f(i, s + i);
}
