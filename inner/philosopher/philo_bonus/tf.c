/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:21:39 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/26 23:00:03 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*tf(void *arg)
{
	t_data	*data;
	struct timeval	start;

	printf("tt");
	data = (t_data *)arg;
	gettimeofday(&start, NULL);
	data->start = start;
	data->last_eat = start;
	if (data->num % 2 == 0 || data->args[0] == data->num)
		tf_even(data);
	else
		tf_odd(data);
	return (NULL);
}

void	tf_odd(t_data *data)
{
	while (1)
	{
		sem_wait(data->forks);
		sem_wait(data->forks);
		message_func_f(data);
		message_func_e(data, data->args[2]);
		sem_post(data->forks);
		sem_post(data->forks);
		message_func_s(data, data->args[3]);
		message_func_t(data);
	}
}

void	tf_even(t_data *data)
{
	usleep(200);
	message_func_t(data);
	while (1)
	{
		sem_wait(data->forks);
		sem_wait(data->forks);
		message_func_f(data);
		message_func_e(data, data->args[2]);
		sem_post(data->forks);
		sem_post(data->forks);
		message_func_s(data, data->args[3]);
		message_func_t(data);
	}	
}
