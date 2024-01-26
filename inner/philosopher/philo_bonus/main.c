/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/26 16:46:17 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char **argv)
{
	int			*args;
	sem_t		*forks;
	pid_t		*philo;
	pthread_t	thrd;
	t_data		*data;
	int			i;
	
	if (argc != 5 && argc != 6)
		exit(1);
	i = 0;
	args = get_args(argc, argv);
	philo = (pid_t *)malloc(sizeof(pid_t) * args[0]);
	data = (t_data *)malloc(sizeof(t_data) * args[0]);
	if (!args || !philo || !data)
		exit(2);
	forks = sem_open("forks", O_CREAT, 0644, args[0]);
	while (i < args[0])
	{
		data[i].philo = fork();
		if (!data[i].philo)
		{
			data[i].forks = forks;
			data[i].args = args;
			data[i].num = i + 1;
			if (pthread_create(thrd, NULL, tf, &data[i]))
				exit(3);
			exit(0);
		}
		i++;
	}
	monitoring();	
	exit(0);
}
