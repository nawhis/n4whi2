/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:59 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/13 19:16:45 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addrsize(unsigned long long addr)
{
	int	len;

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

void	ft_write_addr(s_string *str, unsigned long long addr, size_t len)
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

int	ft_putaddr(void *ad, s_option *opt, s_string *str)
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
	else
	{
		if (!ft_check_realloc(str, len))
			return (0);
		ft_write_addr(str, addr, len);
	}
	return (1);
}
