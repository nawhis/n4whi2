/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:55:18 by sihwan            #+#    #+#             */
/*   Updated: 2024/01/29 01:37:00 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	message_func_d(t_data *data)
// {
// 	sem_wait(data->print_sem);
// 	printf("%lld %d is died\n", timetable(data), data->num);
// 	sem_post(data->print_sem);	
// }

void	message_func_f(t_data *data)
{
	sem_wait(data->print_sem);
	printf("%lld %d has taken a fork\n", timetable(data), data->num);
	sem_post(data->print_sem);	
}


void	message_func_e(t_data *data, int time)
{
	struct timeval	last_eat;

	sem_wait(data->print_sem);
	gettimeofday(&last_eat, NULL);
	data->last_eat = last_eat;
	printf("%lld %d is eating\n", timetable(data), data->num);
	data->cnt_eat++;
	sem_post(data->print_sem);
	if (data->args[4] != 0 && data->cnt_eat == data->args[4])
	{
		sem_post(data->full_sem);
		printf("did it!\n");
	}
	msleep(time);
}

void	message_func_s(t_data *data, int time)
{
	sem_wait(data->print_sem);
	printf("%lld %d is sleeping\n", timetable(data), data->num);
	sem_post(data->print_sem);	
	msleep(time);
}

void	message_func_t(t_data *data)
{
	sem_wait(data->print_sem);
	printf("%lld %d is thinking\n", timetable(data), data->num);
	sem_post(data->print_sem);	
}
