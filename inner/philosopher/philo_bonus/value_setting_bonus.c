/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_setting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:07:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:27 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_data(t_data *data, int *args, pthread_t *thrd)
{
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*full_sem;
	sem_t			*die;
	int				i;

	unlink_all();
	full_sem = sem_open("full_sem", O_CREAT, 0666, args[0]);
	forks = sem_open("forks", O_CREAT, 0666, args[0]);
	print_sem = sem_open("print", O_CREAT, 0666, 1);
	die = sem_open("die", O_CREAT, 0666, args[0]);
	i = 0;
	data[0].philo = 0;
	data_setting(data, args);
	while (i <= args[0])
	{
		data[i].die = die;
		data[i].full_sem = full_sem;
		data[i].forks = forks;
		data[i].print_sem = print_sem;
		data[i].thrd = &thrd[i];
		i++;
	}
}

void	data_setting(t_data *data, int *args)
{
	int				i;

	i = 0;
	while (i <= args[0])
	{
		data[i].is_die = 0;
		data[i].cnt_eat = 0;
		data[i].args = args;
		data[i].num = i;
		i++;
	}
	return ;
}

void	start_children(t_data *data, int *args, sem_t *main_sem)
{
	int				i;
	struct timeval	start;

	i = 0;
	gettimeofday(&start, NULL);
	while (++i <= args[0])
	{
		data[i].main_sem = main_sem;
		data[i].start = start;
		data[i].last_eat = start;
		data[i].philo = fork();
		if (!data[i].philo)
		{
			pthread_create(data[i].thrd, NULL, tf, &data[i]);
			while (1)
			{
				if (time_last_eat(&data[i]) == -1)
				{
					sem_post(data[i].die);
					break ;
				}
			}
			exit(9);
		}
	}
}

void	die_flag_setting(t_data *data)
{
	sem_wait(data->main_sem);
	data[0].is_die = 1;
	sem_post(data->main_sem);
	return ;
}
