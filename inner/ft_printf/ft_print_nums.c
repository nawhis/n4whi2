/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:32:09 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/13 16:19:02 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_write_num(int num, ssize_t size)
{
	char	*nums;

	nums = (char *)ft_calloc(sizeof(char), (size--) + 1);
	if (!nums)
		return (0);
	if (num > 0)
	{
		while (num)
		{
			nums[(size)--] = num % 10 + '0';
			num /= 10;
		}
	}
	else if (num < 0)
	{
		while (num)
		{
			nums[(size)--] = -(num % 10) + '0';
			num /= 10;
		}
		nums[0] = '-';
	}
	while (size > 0)
		nums[size--] = '0';
	return (nums);
}

char	*ft_numtostr(int num, size_t *len, s_option *opt)
{
	ssize_t	size;
	char	*nums;

	if (*len < opt->prec)
		*len += (opt->prec - *len);
	if (opt->flag[1] || opt->flag[3])
		(*len)++;
	if (num < 0 && !(opt->flag[1] || opt->flag[3]))
		(*len)++;
	if (opt->width > *len && !opt->flag[0] && opt->flag[2])
		*len = opt->width;
	size = *len;
	nums = ft_write_num(num, size);
	if (!nums[0])
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

void	ft_fill_minus(char *nums, s_string *str, s_option *opt, size_t len)
{
	size_t	idx;
	size_t	size;

	size = ft_check_size(len, opt);
	idx = 0;
	while (idx < len)
		str->array[str->index++] = nums[idx++];
	if (size == opt->prec)
		while (opt->prec-- > len)
			str->array[str->index++] = '0';
	else if (size == opt->width)
	{
		while (opt->width-- > len)
		{
			if (opt->flag[2])
				str->array[str->index++] = '0';
			else
				str->array[str->index++] = ' ';
		}
	}
	free(nums);
}

void	ft_fill_no_minus(char *nums, s_string *str, s_option *opt, size_t len)
{
	size_t	idx;
	size_t	size;

	size = ft_check_size(len, opt);
	idx = 0;
	if (size == opt->prec)
		while (opt->prec-- > len)
			str->array[str->index++] = '0';
	else if (size == opt->width)
	{
		while (opt->width-- > len)
		{
			if (opt->flag[2])
				str->array[str->index++] = '0';
			else
				str->array[str->index++] = ' ';
		}
	}
	while (idx < len)
		str->array[str->index++] = nums[idx++];
	free(nums);
}

int	ft_putnbr(int num, s_option *opt, s_string *str)
{
	size_t	len;
	size_t	size;
	char	*nums;

	if (opt->flag[2] && opt->flag[5])
		opt->flag[2] = 0;
	len = ft_numsize(num, opt);
	nums = ft_numtostr(num, &len, opt);
	if (!nums)
		return (0);
	size = ft_check_size(len, opt);
	if (!ft_check_realloc(str, size))
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
