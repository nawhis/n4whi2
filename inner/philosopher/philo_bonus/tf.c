/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:21:39 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/27 23:09:33 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void	*tf(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->num % 2 == 0 || data->num == data->args[0])
		tf_even(data);
	else
		tf_odd(data);
	return (NULL);
}

void	tf_odd(t_data *data)
{
	message_func_t(data);
	while (*(data->is_die) == 0)
	{
		sem_wait(data->forks);
		if (*(data->is_die))
			break ;
		message_func_f(data);
		sem_wait(data->forks);
		if (*(data->is_die))
			break ;
		message_func_f(data);
		if (*(data->is_die))
			break ;
		message_func_e(data, data->args[2]);
		sem_post(data->forks);
		sem_post(data->forks);
		if (*(data->is_die))
			break ;
		message_func_s(data, data->args[3]);
		if (*(data->is_die))
			break ;
		message_func_t(data);
	}
	printf("byebye %d\n", data->num);
}

void	tf_even(t_data *data)
{
	usleep(100);
	message_func_t(data);
	while (*(data->is_die) == 0)
	{
		sem_wait(data->forks);
		if (*(data->is_die))
			break ;
		message_func_f(data);
		sem_wait(data->forks);
		if (*(data->is_die))
			break ;
		message_func_f(data);
		if (*(data->is_die))
			break ;
		message_func_e(data, data->args[2]);
		sem_post(data->forks);
		sem_post(data->forks);
		if (*(data->is_die))
			break ;
		message_func_s(data, data->args[3]);
		if (*(data->is_die))
			break ;
		message_func_t(data);
	}
	printf("byebye %d\n", data->num);
}
