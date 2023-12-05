/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:57:25 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/14 21:14:54 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_hexsize(unsigned int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_write_hex(t_option *opt, unsigned int num, ssize_t size, char *xX)
{
	char	*nums;

	nums = (char *)ft_calloc(sizeof(char), (size--) + 1);
	if (!nums)
		return (0);
	while (num)
	{
		nums[(size)--] = xX[num % 16];
		num /= 16;
	}
	if (opt->flag[4])
	{
		if ((opt->flag[2] || (opt->flag[5])))
			while (size > 1)
				nums[(size)--] = '0';
		if (opt->flag[6] == 'x')
			nums[size--] = 'x';
		else
			nums[size--] = 'X';
		nums[size] = '0';
	}
	else
		while (size >= 0)
			nums[size--] = '0';
	return (nums);
}

char	*ft_hextostr(unsigned int num, size_t *len, t_option *opt)
{
	char	*nums;

	if (opt->flag[5] && !opt->prec && num == 0)
	{
		*len = 0;
		return ((char *)ft_calloc(sizeof(char), 1));
	}
	if (*len < opt->prec)
		*len = opt->prec;
	if (opt->flag[4])
		(*len) += 2;
	if (*len < opt->width && opt->flag[2])
		*len = opt->width;
	if (opt->flag[6] == 'x')
		nums = ft_write_hex(opt, num, *len, "0123456789abcdef");
	else
		nums = ft_write_hex(opt, num, *len, "0123456789ABCDEF");
	return (nums);
}

int	ft_puthex(unsigned int num, t_option *opt, t_string *str, char xX)
{
	size_t	len;
	char	*nums;

	opt->flag[6] = xX;
	if (opt->flag[2] && opt->flag[5])
		opt->flag[2] = 0;
	if (opt->flag[4] && num == 0)
		opt->flag[4] = 0;
	len = ft_hexsize(num);
	nums = ft_hextostr(num, &len, opt);
	if (!nums)
		return (0);
	if (!ft_check_realloc(str, len))
	{
		free(nums);
		return (0);
	}
	if (!opt->flag[0])
		ft_fill_no_minus(nums, str, opt, len);
	else
		ft_fill_minus(nums, str, opt, len);
	return (1);
}
