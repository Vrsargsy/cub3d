/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:03:29 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/23 16:50:42 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			tlen;

	if (start > ft_strlen(s))
		tlen = 0;
	else if (ft_strlen(s) - start > len)
		tlen = len;
	else
		tlen = ft_strlen(s) - start;
	str = (char *)malloc(tlen);
	if (str)
		ft_strlcpy(str, s + start, tlen + 1);
	return (str);
}
