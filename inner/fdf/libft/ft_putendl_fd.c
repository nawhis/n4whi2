/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:23:42 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 14:41:58 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s == 0)
		write(fd, "\n", 1);
	else
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
