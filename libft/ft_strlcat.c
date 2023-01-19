/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:20:25 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 18:32:35 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*source;
	size_t	dst_length;
	size_t	i;

	dest = dst;
	source = (char *)src;
	i = dstsize + 1;
	while (--i != 0 && *dest != '\0')
		dest++;
	dst_length = dest - dst;
	i = dstsize - dst_length;
	if (i == 0)
		return (dst_length + ft_strlen(source));
	while (*source != '\0')
	{
		if (i > 1)
		{
			*dest++ = *source;
			i--;
		}
		source++;
	}
	*dest = '\0';
	return (dst_length + (source - src));
}
