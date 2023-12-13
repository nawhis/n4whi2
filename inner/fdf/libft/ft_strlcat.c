/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:28:17 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 14:43:30 by sihkang          ###   ########seoul.kr  */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_index;
	size_t	dst_len;
	size_t	s_index;

	s_index = 0;
	if ((!dst && !dstsize) || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	dst_len = ft_strlen(dst);
	d_index = dst_len;
	while (d_index < dstsize - 1 && src[s_index])
	{
		dst[d_index++] = src[s_index++];
	}
	dst[d_index] = '\0';
	return (dst_len + ft_strlen(src));
}
