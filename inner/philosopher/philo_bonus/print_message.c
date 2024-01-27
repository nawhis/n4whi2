/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:55:18 by sihwan            #+#    #+#             */
/*   Updated: 2024/01/26 22:57:04 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	message_func_f(t_data *data)
{
	sem_wait(data->print_sem);
	printf("%lld %d has taken a fork\n", timetable(data), data->num);
	sem_post(data->print_sem);	
}


void	message_func_e(t_data *data, int time)
{
	sem_wait(data->print_sem);
	printf("%lld %d is eating\n", timetable(data), data->num);
	msleep(time);
	sem_post(data->print_sem);	
}

void	message_func_s(t_data *data, int time)
{
	sem_wait(data->print_sem);
	printf("%lld %d is sleeping\n", timetable(data), data->num);
	msleep(time);
	sem_post(data->print_sem);	
}

void	message_func_t(t_data *data)
{
	sem_wait(data->print_sem);
	printf("%lld %d is thinking\n", timetable(data), data->num);
	sem_post(data->print_sem);	
}
