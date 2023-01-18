/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:05:21 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/28 19:35:33 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;
	char	*s2;

	len = 0;
	while (s1[len])
		len++;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (0);
	s2 = s;
	len = 0;
	while (s1[len] != '\0')
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s);
}
