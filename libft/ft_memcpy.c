/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:02:26 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 18:28:43 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	id;

	if (!dst && !src)
		return (NULL);
	id = 0;
	while (id < n)
	{
		((unsigned char *)dst)[id] = ((unsigned char *)src)[id];
		id++;
	}
	return (dst);
}
