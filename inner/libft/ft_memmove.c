/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:18:11 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/20 17:33:48 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t	index;

	index = 0;
	if (!dst && !src)
		return (0);
	if (dst >= src && (size_t)(dst - src) < len)
	{
		while (index++ < len)
		{
			((unsigned char *)dst)[len - index] = \
			((unsigned char *)src)[len - index];
		}
	}
	else
	{
		while (index < len)
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	return (dst);
}
