/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:40:16 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/17 15:17:29 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	s1_c;
	unsigned char	s2_c;

	index = 0;
	while (index < n)
	{
		s1_c = s1[index];
		s2_c = s2[index];
		if (s1_c != s2_c)
			return ((int)s1_c - (int)s2_c);
		else if (!s1_c && !s2_c)
			return (0);
		index++;
	}
	return (0);
}
