/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:41:47 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 18:28:06 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			id;
	unsigned char	tmp;

	tmp = c;
	id = 0;
	while (id < n)
	{
		((unsigned char *)dst)[id] = ((unsigned char *)src)[id];
		if (((unsigned char *)dst)[id] == tmp)
			return (dst + id + 1);
		id++;
	}
	return (NULL);
}
