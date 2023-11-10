/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:26:53 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/18 13:37:42 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n);

void	ft_putnbr_fd(int n, int fd)
{
	char	num[12];
	size_t	size;
	size_t	index;

	index = 0;
	size = ft_size(n);
	num[size] = 0;
	if (n >= 0)
	{
		while (index < size)
		{
			num[size - ++index] = n % 10 + '0';
			n /= 10;
		}
	}
	else
	{
		while (index < size)
		{
			num[size - ++index] = -(n % 10) + '0';
			n /= 10;
		}
		num[0] = '-';
	}
	write(fd, num, ft_strlen(num));
}

static size_t	ft_size(int n)
{
	size_t	size;

	if (n != 0)
	{
		if (n > 0)
			size = 0;
		else
			size = 1;
		while (n != 0)
		{
			n /= 10;
			size++;
		}
		return (size);
	}
	else
		return (1);
}
