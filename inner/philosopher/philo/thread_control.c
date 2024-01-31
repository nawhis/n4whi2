/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:01:07 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:53 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(pthread_mutex_t *time, pthread_mutex_t *cnt_eat_mutex, \
				pthread_mutex_t *print_mutex, pthread_mutex_t *flag_mutex)
{
	if (pthread_mutex_init(time, NULL))
		return (-1);
	if (pthread_mutex_init(cnt_eat_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(print_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(flag_mutex, NULL))
		return (-1);
	return (0);
}

int philo_init2(t_tt *st, pthread_mutex_t *fork, int *args, pthread_t *philo)
{
	int	i;

	i = 0;
	while (i < args[0])
	{
		st[i].args = args;
		st[i].num = i + 1;
		st[i].philo = philo[i];
		st[i].fork_right = &fork[i];
		st[i].fork_left = &fork[(i + 1) % st[i].args[0]];
		i++;
	}
	return (0);
}

int	philo_init(t_tt *st, int *args)
{
	pthread_mutex_t	*time;
	pthread_mutex_t	*cnt_eat_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t *flag_mutex;
	int				i;

	time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	cnt_eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	flag_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!time || !cnt_eat_mutex || !print_mutex || \
		mutex_init(time, cnt_eat_mutex, print_mutex, flag_mutex) == -1)
		return (-1);
	i = 0;
	while (i < args[0])
	{
		st[i].time = time;
		st[i].print_mutex = print_mutex;
		st[i].cnt_eat_mutex = cnt_eat_mutex;
		st[i].flag_mutex = flag_mutex;
		i++;
	}
	return (0);
}

void	remove_thread(t_tt *st)
{
	int	i;
	int	nums;

	i = 0;
	nums = st[i].args[0];
	pthread_mutex_destroy(st[i].time);
	pthread_mutex_destroy(st[i].cnt_eat_mutex);
	pthread_mutex_destroy(st[i].print_mutex);
	pthread_mutex_destroy(st[i].flag_mutex);
	free(st[i].flag_mutex);
	free(st[i].time);
	free(st[i].cnt_eat_mutex);
	free(st[i].print_mutex);
	free(st[i].flag_stop);
	while (i < nums)
	{
		pthread_join(st[i].philo, NULL);
		pthread_mutex_destroy(st[i].fork_right);
		i++;
	}
	return ;
}

int	philo_create(t_tt *st, pthread_mutex_t *fork, int *args, pthread_t *philo)
{
	struct timeval	start;
	int				i;
	int				*flag_stop;

	i = 0;
	if (philo_init(st, args) || philo_init2(st, fork, args, philo))
		return (-1);
	if (gettimeofday(&start, NULL))
		return (-1);
	flag_stop = (int *)malloc(sizeof(int));
	if (!flag_stop)
		return (-1);
	flag_stop[0] = 0;
	while (i < args[0])
	{
		st[i].flag_stop = flag_stop;
		st[i].cnt_eat = 0;
		st[i].start = start;
		st[i].last_eat = start;
		if (pthread_create(&philo[i], NULL, tf, &st[i]))
			return (-1);
		i++;
	}
	return (0);
}

pthread_mutex_t	*make_fork(int nums)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nums);
	if (!fork)
		return (NULL);
	while (i < nums)
		if (pthread_mutex_init(&fork[i++], NULL))
			return (NULL);
	return (fork);
}
