/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:17:03 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/13 17:49:04 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numsize(long long num, s_option *opt)
{
	size_t	len;

	len = 0;
	if (opt->flag[5] && !opt->prec && num == 0)
		return (0);
	else if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_write_unum(unsigned int num, ssize_t size)
{
	char	*nums;

	nums = (char *)ft_calloc(sizeof(char), (size--) + 1);
	if (!nums)
		return (0);
	while (num)
	{
		nums[(size)--] = num % 10 + '0';
		num /= 10;
	}
	while (size > 0)
		nums[size--] = '0';
	return (nums);
}

char	*ft_unumtostr(unsigned int num, size_t *len, s_option *opt)
{
	char	*nums;
	ssize_t	size;

	if (*len < opt->prec)
		*len += (opt->prec - *len);
	if (opt->flag[1] || opt->flag[3])
		(*len)++;
	if (num < 0 && !(opt->flag[1] || opt->flag[3]))
		(*len)++;
	if (opt->width > *len && !opt->flag[0] && opt->flag[2])
		*len = opt->width;
	size = *len;
	nums = ft_write_unum(num, size);
	if (!nums [0])
	{
		if (opt->flag[1])
			nums[0] = '+';
		else if (opt->flag[3])
			nums[0] = ' ';
		else
			nums[0] = '0';
	}
	return (nums);
}

int	ft_putunbr(unsigned int num, s_option *opt, s_string *str)
{
	size_t	len;
	size_t	size;
	char	*nums;

	if (opt->flag[2] && opt->flag[5])
		opt->flag[2] = 0;
	len = ft_numsize(num, opt);
	nums = ft_unumtostr(num, &len, opt);
	if (!nums)
		return (0);
	size = ft_check_size(len, opt);
	if (!ft_check_realloc(str, size))
		return (0);
	if (!opt->flag[0])
		ft_fill_no_minus(nums, str, opt, len);
	else
		ft_fill_minus(nums, str, opt, len);
	return (1);
}

size_t	ft_check_size(size_t len, s_option *opt)
{
	size_t	size;

	size = len;
	if (size < opt->width)
		size = opt->width;
	if (size < opt->prec)
		size = opt->prec;
	return (size);
}
