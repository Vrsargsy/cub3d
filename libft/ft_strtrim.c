/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:17:04 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 18:38:06 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_c(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	start_cursor(const char *str, const char *set,
							size_t length, char step)
{
	size_t	cursor;
	size_t	id;

	cursor = 0;
	while (cursor < length)
	{
		id = cursor;
		if (step < 0)
			id = length - 1 - cursor;
		if (!find_c(str[id], set))
			return (id);
		cursor++;
	}
	return (cursor);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	length = ft_strlen(s1);
	end = start_cursor(s1, set, length, -1);
	start = start_cursor(s1, set, length, 1);
	if (start > end)
		length = 0;
	else
		length = end - start + 1;
	if (length <= 0)
		return (ft_strdup(""));
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + start, length);
	str[length] = '\0';
	return (str);
}
