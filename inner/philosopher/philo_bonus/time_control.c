/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:50:31 by sihwan            #+#    #+#             */
/*   Updated: 2024/01/26 22:35:56 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	timetable(t_data *st)
{
	struct timeval		end;
	long long			difftime;

	sem_wait(st->time_sem);
	gettimeofday(&end, NULL);
	difftime = ((end.tv_sec - st->start.tv_sec - 1) * 1000000 + \
				(1000000 + end.tv_usec - st->start.tv_usec)) / 1000;
	sem_post(st->time_sem);
	return (difftime / 1000);
}

void	msleep(long long milisecond)
{
	struct timeval		tmp;
	struct timeval		t;
	long long			time;

	time = 0;
	gettimeofday(&t, NULL);
	while (time < milisecond * 1000)
	{
		usleep(100);
		gettimeofday(&tmp, NULL);
		time = ((tmp.tv_sec - 1 - t.tv_sec) * 1000000) + \
				((1000000 + tmp.tv_usec - t.tv_usec));
	}
	return ;
}
