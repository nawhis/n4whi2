/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:30 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int			*args;
	pthread_t	*thrd;
	t_data		*data;
	sem_t		*main_sem;

	if (argc != 5 && argc != 6)
		exit(1);
	args = get_args(argc, argv);
	thrd = (pthread_t *)malloc2(sizeof(pthread_t) * (args[0] + 1));
	data = (t_data *)malloc2(sizeof(t_data) * (args[0] + 1));
	main_sem = sem_open("main_sem", O_CREAT, 0666, 1);
	set_data(data, args, thrd);
	sem_wait(main_sem);
	start_children(data, args, main_sem);
	data[0].main_sem = main_sem;
	data[0].thrd = thrd;
	sem_post(main_sem);
	msleep(60);
	if (pthread_create(data[0].thrd, NULL, tf_main, &data[0]))
		sem_post(data->die);
	pthread_detach(*data[0].thrd);
	sem_wait(data->die);
	close_for_exit(data, args, thrd);
	msleep(1000);
	exit(0);
}	
