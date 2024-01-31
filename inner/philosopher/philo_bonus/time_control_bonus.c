/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:50:31 by sihwan            #+#    #+#             */
/*   Updated: 2024/01/31 18:42:28 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	timetable(t_data *st)
{
	struct timeval		end;
	long long			difftime;

	gettimeofday(&end, NULL);
	difftime = ((end.tv_sec - st->start.tv_sec - 1) * 1000000 + \
				(1000000 + end.tv_usec - st->start.tv_usec)) / 1000;
	return (difftime);
}

long long	time_last_eat(t_data *st)
{
	struct timeval	tmp;
	long long		difftime;

	sem_wait(st->print_sem);
	gettimeofday(&tmp, NULL);
	difftime = ((tmp.tv_sec - st->last_eat.tv_sec - 1) * 1000000 + \
				(1000000 + tmp.tv_usec - st->last_eat.tv_usec)) / 1000;
	if (difftime > st->args[1])
	{
		difftime = ((tmp.tv_sec - st->start.tv_sec - 1) * 1000000 + \
				(1000000 + tmp.tv_usec - st->start.tv_usec)) / 1000;
		printf("%lld %d is died\n", difftime, st->num);
		return (-1);
	}
	sem_post(st->print_sem);
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
		time = ((tmp.tv_sec - 1 - t.tv_sec) * 1000000 + \
				(1000000 + tmp.tv_usec - t.tv_usec)) / 1000;
	}
	return ;
}
