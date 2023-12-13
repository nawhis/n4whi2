/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:35:03 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/20 17:30:47 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	s1_c;
	unsigned char	s2_c;
	size_t			index;

	index = 0;
	while (index < n)
	{
		s1_c = ((unsigned char *)s1)[index];
		s2_c = ((unsigned char *)s2)[index];
		if (s1_c != s2_c)
		{
			return ((int)s1_c - (int)s2_c);
		}
		index++;
	}
	return (0);
}
