/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:59:10 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/29 01:13:14 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	long long		sign;
	long long		val;
	long long		i;

	sign = 1;
	val = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i > 10)
			exit(1);	
		val = 10 * val + str[i++] - '0';
	}
	if (!(sign * val >= -2147483648 && sign * val <= 2147483647) || \
	(i == 0 && str[i] == '\0') || str[i] != '\0')
		exit(1);
	if (sign * val <= 0)
		exit(1);
	return (sign * val);
}

int	*get_args(int argc, char **argv)
{
	int	*args;
	int	i;

	args = (int *)malloc(sizeof(int) * (5));
	if (!args)
		return (NULL);
	i = 0;
	args[4] = 0;
	while (i < argc - 1)
	{
		args[i] = ft_atoi(argv[i + 1]);
		if (args[i] <= 0)
		{
			free(args);
			return (NULL);
		}
		i++;
	}
	return (args);
}
