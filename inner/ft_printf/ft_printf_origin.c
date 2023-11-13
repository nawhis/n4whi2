/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:25:05 by sihkang           #+#    #+#             */
/*   Updated: 2023/11/12 19:15:05 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_realloc(s_string *str)
{
	char	*newstr;
	size_t	len;
	size_t	index;

	index = 0;
	len = (str->max) * 2;
	newstr = (char *)malloc(sizeof(char) * (len));
	if (newstr)
	{
		while (index < str->index)
		{
			newstr[index] = str->array[index];
			index++;
		}
		newstr[index] = 0;
	}
	str->max = len;
	free(str->array);
	str->array = newstr;
}

int	ft_check_realloc(s_string *str, size_t len)
{
	while (str->max <= str->index + len)
	{
		ft_realloc(str);
		if (!str->array)
			return (0);
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (char *)s;
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (0);
}


void	*ft_calloc(size_t size, size_t count)
{
	void	*mem;
	size_t	index;

	index = 0;
	if ((size != 0 && (size_t)-1 / size < count))
		return (0);
	mem = malloc(count * size);
	if (!mem)
		return (0);
	while (index < count * size)
		((char *)mem)[index++] = 0;
	return (mem);
}

int		ft_addrsize(unsigned long long addr)
{
	int		len;

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

int	ft_putaddr(void *ad, s_option *opt, s_string *str)
{
	char	hex_nums[] = "0123456789abcdef";
	size_t	len;
	size_t	size;
	unsigned long long	addr;

	addr = (unsigned long long)ad;
	len = ft_addrsize(addr);
	size = len;
	if (opt->width > len + 2)
	{
		if (!ft_check_realloc(str, opt->width))
			return (0);
		opt->width -= (len) + 2;
		if (opt->flag[0])
		{
			str->array[str->index++] = '0';
			str->array[str->index++] = 'x';
			while (len-- > 0)
			{	
				str->array[str->index + len] = hex_nums[addr % 16];
				addr /= 16;
			}
			str->index += size;
			while (opt->width--)
				str->array[str->index++] = ' ';
		}
		else
		{
			while (opt->width--)
				str->array[str->index++] = ' ';
			str->array[str->index++] = '0';
			str->array[str->index++] = 'x';
			while (len-- > 0)
			{	
				str->array[str->index + len] = hex_nums[addr % 16];
				addr /= 16;
			}
			str->index += size;
		}
	}
	else
	{
		if (!ft_check_realloc(str, len + 2))
			return (0);
		str->array[str->index++] = '0';
		str->array[str->index++] = 'x';
		while (len-- > 0)
		{	
			str->array[str->index + len] = hex_nums[addr % 16];
			addr /= 16;
		}
		str->index += size;
	}
	return (1);
}

size_t	ft_hexsize(unsigned int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_hextostr(unsigned int num, size_t *len, s_option *opt, char *xX)
{
	char	*nums;
	ssize_t	size;
	unsigned int digits;

	digits = ft_hexsize(num);
	if (*len < opt->prec)
	{
		*len += (opt->prec - *len);
	}
	if (opt->flag[4])
		(*len) += 2;
	if (*len < opt->width && opt->flag[2])
		*len += (opt->width - *len);
	size = *len;
	if (opt->flag[5] && !opt->prec && num == 0)	
	{
		*len = 0;
		return ((char *)ft_calloc(sizeof(char), 1));
	}
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

int	ft_puthex(unsigned int num, s_option *opt, s_string *str)
{
	size_t	len;
	size_t	size;
	size_t	start;
	size_t	idx;
	char	*nums;

	idx = 0;
	len = ft_hexsize(num);
	if (opt->flag[2] && opt->flag[5])
		opt->flag[2] = 0;
	if (opt->flag[4] && num == 0)
		opt->flag[4] = 0;
	if (opt->flag[6] == 'x')
		nums = ft_hextostr(num, &len, opt, "0123456789abcdef");
	else
		nums = ft_hextostr(num, &len, opt, "0123456789ABCDEF");
	if (!nums)
		return (0);
	if (len < opt->width)
		size = opt->width;
	else
		size = len;
	if (size < opt->prec)
		size = opt->prec;
	if (!ft_check_realloc(str, size))
	{
		free(nums);
		return (0);
	}
	if (!opt->flag[0])
	{
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
	}
	else
	{
		start = len;
		while (idx < len)
			str->array[str->index++] = nums[idx++];
		if (size == opt->prec)
			while (opt->prec-- > start)
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
	}
	free(nums);
	return (1);
}

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
	nums = (char *)ft_calloc(sizeof(char), (size--) + 1);
	if (!nums)
		return (0);
	if (opt->flag[1])
		nums[0] = '+';
	else if (opt->flag[3])
		nums[0] = ' ';
	if (num > 0)
	{
		while (num)
		{
			nums[(size)--] = num % 10 + '0';
			num /= 10;
		}
	}
	if (nums[0] != '\0')
		while (size > 0)
			nums[size--] = '0';
	else
		while (size >= 0)
			nums[size--] = '0';
	return (nums);
}

char	*ft_numtostr(int num, size_t *len, s_option *opt)
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

int	ft_putunbr(unsigned int num, s_option *opt, s_string *str)
{
	size_t	len;
	size_t	size;
	size_t	start;
	size_t	idx;
	char	*nums;

	if (opt->flag[2] && opt->flag[5])
		opt->flag[2] = 0;
	idx = 0;
	len = ft_numsize(num, opt);
	nums = ft_unumtostr(num, &len, opt);
	size = len;
	if (!nums)
		return (0);
	if (size < opt->width)
		size = opt->width;
	if (size < opt->prec)
		size = opt->prec;
	if (!ft_check_realloc(str, size))
		return (0);	
	if (!opt->flag[0])
	{
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
	}
	else
	{
		start = len;
		while (idx < len)
			str->array[str->index++] = nums[idx++];
		if (size == opt->prec)
			while (opt->prec-- > start)
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
	}
	free(nums);
	return (1);
}

int	ft_putnbr(int num, s_option *opt, s_string *str)
{
	size_t	len;
	size_t	size;
	size_t	start;
	size_t	idx;
	char	*nums;

	if (opt->flag[2] && opt->flag[5])
		opt->flag[2] = 0;
	idx = 0;
	len = ft_numsize(num, opt);
	nums = ft_numtostr(num, &len, opt);
	if (!nums)
		return (0);
	if (len < opt->width)
		size = opt->width;
	else
		size = len;
	if (size < opt->prec)
		size = opt->prec;
	if (!ft_check_realloc(str, size))
		return (0);
	if (!opt->flag[0])
	{
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
	}
	else
	{
		start = len;
		while (idx < len)
			str->array[str->index++] = nums[idx++];
		if (size == opt->prec)
			while (opt->prec-- > start)
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
	}
	free(nums);
	return (1);
}

// int	ft_putstr(char *s, s_option *opt, s_string *str)
// {
// 	size_t	len;
// 	size_t	idx;

// 	idx = 0;
// 	if (s == 0)
// 		s = "(null)";
// 	len = ft_strlen(s);
// 	if (opt->flag[2] && opt->flag[0])
// 		opt->flag[2] = 0;
// 	if (opt->flag[5] && opt->prec < len)
// 		len = opt->prec;
// 	if (opt->width > len)
// 	{
// 		if (!ft_check_realloc(str, opt->width))
// 			return (0);
// 		opt->width -= len;
// 		if (opt->flag[0])
// 		{
// 			while (idx < len)
// 			{
// 				str->array[str->index++] = *s++;
// 				idx++;
// 			}
// 			while (opt->width--)
// 				str->array[str->index++] = ' ';
// 		}
// 		else
// 		{
// 			while (opt->width--)
// 				str->array[str->index++] = ' ';
// 			while (idx < len)
// 			{
// 				str->array[str->index++] = *s++;
// 				idx++;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if (!ft_check_realloc(str, len))
// 			return (0);
// 		while (idx < len)
// 		{
// 			str->array[str->index++] = *s++;
// 			idx++;
// 		}
// 	}
// 	return (1);
// }

// int	ft_putchar(char c, s_option *opt, s_string *str)
// {
// 	size_t	len;

// 	if (opt->width > 1)
// 		len = opt->width;
// 	else
// 		len = 1;
// 	if (!ft_check_realloc(str, opt->width))
// 		return (0);
// 	if (opt->width > 1)
// 	{
// 		opt->width -= 1;
// 		if (opt->flag[0])
// 		{
// 			str->array[str->index++] = c;
// 			while (opt->width--)
// 				str->array[str->index++] = ' ';
// 		}
// 		else
// 		{
// 			while (opt->width--)
// 				str->array[str->index++] = ' ';
// 			str->array[str->index++] = c;
// 		}
// 	}
// 	else
// 		str->array[str->index++] = c;
// 	return (1);
// }


int	ft_printf(const char * format, ...)
{
	va_list		args;
	s_string	*str;
	s_option	*opt;
	size_t		ok;

	str = (s_string *)ft_calloc(sizeof(s_string), 1);
	if (!str)
		return (-1);
	str->max = 1024;
	str->array = (char *)ft_calloc(sizeof(char), str->max);
	ok = 1;
	if (!str->array)
	{
		free(str);
		return (-1);
	}
	va_start(args, format);
	while (*format != '\0')
	{	
		if (*(format) == '%')
		{
			opt = (s_option *)ft_calloc(sizeof(s_option), 1);
			if (!opt)
			{
				str->index = -1;
				break;
			}
			format++;
			while (!ft_strchr("cspdiuxX%", *format)) // 여기 걸리면 플래그, width, precision 인 것임.
			{
				if (*format == '-') // left align in field width
					opt->flag[0] = 1;
				else if (*format == '+')
					opt->flag[1] = 1;
				else if (*format == '0')
					opt->flag[2] = 1;
				else if (*format == ' ')
					opt->flag[3] = 1;
				else if (*format == '#')
					opt->flag[4] = 1;
				else if (*format == '.')				
				{
					opt->flag[5] = 1;
					format++;
					while (*format >= '0' && *format <= '9')
							opt->prec = opt->prec * 10 + *(format++) - '0';
					format--;
				}
				else // 플래그들을 제외하고 서식 지정자도 아니라면 올 수 있는 것은 "숫자" -> width값. or prec 값.
				{
					while (*format >= '0' && *format <= '9')
						opt->width = opt->width * 10 + *(format++) - '0';
					format--;
				}
				format++;
			}
			/* 플래그 중복 시 에러인 경우들 -> 함수 종료시키도록 추가 필요 */
			if (*format == 'c' )
				ok = ft_putchar(va_arg(args, int), opt, str);
			else if (*format == 's')
				ok = ft_putstr(va_arg(args, char *), opt, str);
			else if (*format == 'd' || *format == 'i')
				ok = ft_putnbr(va_arg(args, int), opt, str);
			else if (*format == 'u')
				ok = ft_putunbr(va_arg(args, unsigned int), opt, str);
			else if (*format == 'x' || *format == 'X')
			{
				if (*format == 'x')
					opt->flag[6] = 'x';
				else
					opt->flag[6] = 'X';
				ok = ft_puthex(va_arg(args, unsigned int), opt, str);
			}
			else if (*format == 'p')
				ok = ft_putaddr(va_arg(args, void *), opt, str);
			else if (*format == '%')
				ok = ft_putchar('%', opt, str);
			
			format++;
			free(opt);
		}
		else
		{
			if (ft_check_realloc(str, 1))
				str->array[str->index++] = *(format++);
			else
				ok = 0;
		}
		if (ok == 0)
		{
			free(str->array);
			free(str);
			return (-1);
		}
	}
	va_end(args);
	if (write(1, str->array, str->index) == -1)
		ok = -1;
	else
		ok = str->index;
	free(str->array);
	free(str);
	return (ok);
}

