/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:05:12 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 17:06:29 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printnum(long num, int fd)
{
	char	ch;

	if (num < 10)
	{
		ch = num + '0';
		write(fd, &ch, 1);
	}
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ch = (num % 10) + '0';
		write(fd, &ch, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	printnum(num, fd);
}
