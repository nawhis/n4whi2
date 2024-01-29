/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:21:39 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/29 21:14:09 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*tf_main(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	if (data->args[4] == 0)
		return (NULL);
	i = data->args[0];
	while (i--)
	{
		sem_wait(data->main_sem);
		if (data->is_die == 0)
		{
			sem_post(data->main_sem);
			sem_wait(data->full_sem);
		}
		else
			return (NULL);
	}
	sem_post(data->die);
	clear_children(data, data->args);
	return (NULL);
}

void	*tf(void *arg)
{
	t_data			*data;

	data = (t_data *)arg;
	sem_wait(data->die);
	sem_wait(data->full_sem);
	sem_wait(data->main_sem);
	sem_post(data->main_sem);
	if (data->num % 2 == 0 || data->num == data->args[0])
		tf_even(data);
	else
		tf_odd(data);
	return (NULL);
}

void	tf_odd(t_data *data)
{
	message_func_t(data);
	while (1)
	{
		sem_wait(data->forks);
		message_func_f(data);
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
	message_func_t(data);
	msleep(data->args[2] / 2);
	while (1)
	{
		sem_wait(data->forks);
		message_func_f(data);
		sem_wait(data->forks);
		message_func_f(data);
		message_func_e(data, data->args[2]);
		sem_post(data->forks);
		sem_post(data->forks);
		message_func_s(data, data->args[3]);
		message_func_t(data);
	}
}
