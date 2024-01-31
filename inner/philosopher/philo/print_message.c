/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:44:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:52 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	message_func_f(t_tt *philo_st)
{
	pthread_mutex_lock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	printf("%lld %d has taken a fork\n", timetable(philo_st), philo_st->num);
	pthread_mutex_unlock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	return (0);
}

int	message_func_e(t_tt *philo_st)
{
	pthread_mutex_lock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	printf("%lld %d is eating\n", timetable(philo_st), philo_st->num);
	pthread_mutex_unlock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	return (0);
}

int	message_func_s(t_tt *philo_st)
{
	pthread_mutex_lock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	printf("%lld %d is sleeping\n", timetable(philo_st), philo_st->num);
	pthread_mutex_unlock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	return (0);
}

int	message_func_t(t_tt *philo_st)
{
	pthread_mutex_lock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	printf("%lld %d is thinking\n", timetable(philo_st), philo_st->num);
	pthread_mutex_unlock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	return (0);
}

int	message_func_d(t_tt *philo_st)
{
	pthread_mutex_lock(philo_st->print_mutex);
	printf("%lld %d died\n", timetable(philo_st), philo_st->num);
	pthread_mutex_unlock(philo_st->print_mutex);
	pthread_mutex_lock(philo_st->flag_mutex);
	if (*(philo_st->flag_stop))
		return (-1);
	pthread_mutex_unlock(philo_st->flag_mutex);
	return (0);
}
