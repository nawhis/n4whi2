/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:59:58 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:54 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timetable(t_tt *st)
{
	struct timeval		end;
	long long			difftime;

	pthread_mutex_lock(st->time);
	gettimeofday(&end, NULL);
	difftime = ((end.tv_sec - st->start.tv_sec - 1) * 1000000 + \
				(1000000 + end.tv_usec - st->start.tv_usec)) / 1000;
	pthread_mutex_unlock(st->time);
	return (difftime);
}

long long	time_last_eat(t_tt *st)
{
	struct timeval		end;
	long long			difftime;

	pthread_mutex_lock(st->time);
	gettimeofday(&end, NULL);
	difftime = ((end.tv_sec - st->last_eat.tv_sec - 1) * 1000000 + \
				(1000000 + end.tv_usec - st->last_eat.tv_usec)) / 1000;
	if (difftime > st->args[1])
	{
		pthread_mutex_lock(st->print_mutex);
		pthread_mutex_lock(st->flag_mutex);
		st->flag_stop[0]++;
		pthread_mutex_unlock(st->flag_mutex);
		pthread_mutex_unlock(st->print_mutex);
		pthread_mutex_unlock(st->time);
		return (-1);
	}
	pthread_mutex_unlock(st->time);
	return (difftime);
}

void	msleep(long long milisecond)
{
	struct timeval		tmp;
	struct timeval		t;
	long long			time;

	time = 0;
	gettimeofday(&t, NULL);
	while (time < milisecond)
	{
		usleep(100);
		gettimeofday(&tmp, NULL);
		time = ((tmp.tv_sec - 1 - t.tv_sec) * 1000000) + \
				((1000000 + tmp.tv_usec - t.tv_usec));
	}
	return ;
}
