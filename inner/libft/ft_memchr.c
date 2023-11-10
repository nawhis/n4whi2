/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:14:50 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/20 17:30:13 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (((unsigned char *)s)[len] == (unsigned char)c)
			return ((void *)&s[len]);
		len++;
	}
	return (0);
}
