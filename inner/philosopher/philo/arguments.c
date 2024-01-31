/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:59:10 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:49 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (-1);
		val = 10 * val + str[i++] - '0';
	}
	if (!(sign * val >= -2147483648 && sign * val <= 2147483647) || \
	(i == 0 && str[i] == '\0') || str[i] != '\0')
		return (-1);
	if (sign * val == 0)
		return (-1);
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
	args[4] = -1;
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

void	free_func(pthread_t *philo, t_tt *st, pthread_mutex_t *fork, int *args)
{
	free(philo);
	free(st);
	free(fork);
	free(args);
	return ;
}

void	free_two(t_tt *st)
{
	free(st->time);
	free(st->cnt_eat_mutex);
	free(st->print_mutex);
	free(st->flag_stop);
}

void	count_eat(t_tt *philo_st)
{
	pthread_mutex_lock(philo_st->cnt_eat_mutex);
	philo_st->cnt_eat++;
	pthread_mutex_unlock(philo_st->cnt_eat_mutex);
}
