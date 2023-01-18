/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:02:37 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 17:02:39 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst > src)
		while (len--)
			*(d + len) = *(s + len);
	else if (dst < src)
		while (len--)
			*(d++) = *(s++);
	return (dst);
}
