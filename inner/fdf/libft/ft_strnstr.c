/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:40:04 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 14:43:50 by sihkang          ###   ########seoul.kr  */
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_idx;
	size_t	h_idx;
	size_t	h_len;
	size_t	n_len;

	h_idx = 0;
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	if (len == 0 || h_len < n_len)
		return (0);
	while (h_idx + n_len <= len)
	{
		n_idx = 0;
		while (haystack[h_idx + n_idx] != '\0' && \
		haystack[h_idx + n_idx] == needle[n_idx])
			n_idx++;
		if (n_idx >= n_len)
			return ((char *)&haystack[h_idx]);
		h_idx++;
	}
	return (0);
}
