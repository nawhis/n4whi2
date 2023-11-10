/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:19:34 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/15 17:46:00 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static size_t	ft_size(int n);
static char		*ft_fillarr(char *str, size_t size, int n);

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_size(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	return (ft_fillarr(str, size, n));
}

static char	*ft_fillarr(char *str, size_t size, int n)
{
	str[size] = '\0';
	if (n >= 0)
	{
		while (size > 0)
		{
			str[--size] = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		str[0] = '-';
		while (size > 1)
		{
			str[--size] = -(n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}

static size_t	ft_size(int n)
{
	size_t	size;

	if (n > 0)
	{
		size = 0;
		while (n)
		{
			size++;
			n /= 10;
		}
	}
	else if (n == 0)
		return (1);
	else
	{
		size = 1;
		while (n)
		{
			size++;
			n /= 10;
		}
	}
	return (size);
}
