/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:08:23 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/26 12:30:16 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*tf(void *arg)
{
	t_tt			*philo_st;

	philo_st = (t_tt *)arg;
	if (philo_st->num % 2 == 0 || philo_st->num == philo_st->args[0])
		tf_even(philo_st);
	else
		tf_odd(philo_st);
	return (NULL);
}

void	tf_odd(t_tt *philo_st)
{
	while (1)
	{
		pthread_mutex_lock(philo_st->fork_right);
		if (message_func_f(philo_st) == -1)
			break ;
		pthread_mutex_lock(philo_st->fork_left);
		if (message_func_f(philo_st) == -1)
			break ;
		message_func_e(philo_st);
		count_eat(philo_st);
		gettimeofday(&philo_st->last_eat, NULL);
		msleep(philo_st->args[2] * 1000);
		pthread_mutex_unlock(philo_st->fork_left);
		pthread_mutex_unlock(philo_st->fork_right);
		if (message_func_s(philo_st) == -1)
			break ;
		msleep(philo_st->args[3] * 1000);
		if (message_func_t(philo_st) == -1)
			break ;
	}
}

void	tf_even(t_tt *philo_st)
{
	usleep(100);
	message_func_t(philo_st);
	while (1)
	{
		pthread_mutex_lock(philo_st->fork_right);
		if (message_func_f(philo_st) == -1)
			break ;
		pthread_mutex_lock(philo_st->fork_left);
		if (message_func_f(philo_st) == -1)
			break ;
		message_func_e(philo_st);
		count_eat(philo_st);
		gettimeofday(&philo_st->last_eat, NULL);
		msleep(philo_st->args[2] * 1000);
		pthread_mutex_unlock(philo_st->fork_left);
		pthread_mutex_unlock(philo_st->fork_right);
		if (message_func_s(philo_st) == -1)
			break ;
		msleep(philo_st->args[3] * 1000);
		if (message_func_t(philo_st) == -1)
			break ;
	}
}
