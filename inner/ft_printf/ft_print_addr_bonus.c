/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:59 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/14 20:57:01 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_addrsize(unsigned long long addr)
{
	size_t	len;

	len = 0;
	if (!addr)
		return (1);
	while (addr)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

void	ft_write_addr(t_string *str, unsigned long long addr, size_t len)
{
	const char	hex_nums[] = "0123456789abcdef";
	size_t		size;

	str->array[str->index++] = '0';
	str->array[str->index++] = 'x';
	size = len - 2;
	len -= 2;
	while (len-- > 0)
	{
		str->array[str->index + len] = hex_nums[addr % 16];
		addr /= 16;
	}
	str->index += size;
}

int	ft_putaddr(void *ad, t_option *opt, t_string *str)
{
	size_t				len;
	unsigned long long	addr;

	addr = (unsigned long long)ad;
	len = ft_addrsize(addr) + 2;
	if (opt->width > len)
	{
		if (!ft_check_realloc(str, opt->width))
			return (0);
		opt->width -= (len);
		ft_width_bigger(str, opt, addr, len);
	}
	else
	{
		if (!ft_check_realloc(str, len))
			return (0);
		ft_write_addr(str, addr, len);
	}
	return (1);
}

void	ft_width_bigger(t_string *str, t_option *opt, \
		unsigned long long addr, size_t len)
{
	if (opt->flag[0])
	{
		ft_write_addr(str, addr, len);
		while (opt->width--)
			str->array[str->index++] = ' ';
	}
	else
	{
		while (opt->width--)
			str->array[str->index++] = ' ';
		ft_write_addr(str, addr, len);
	}
}
