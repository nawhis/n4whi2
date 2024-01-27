/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/26 23:00:23 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_data(t_data *data, int *args, pthread_t *thrd)
{
	sem_t		*forks;
	sem_t		*print_sem;
	sem_t		*time_sem;
	int			i;

	i = 0;
	forks = (sem_t *)malloc2(sizeof(sem_t));
	print_sem = (sem_t *)malloc2(sizeof(sem_t));
	time_sem = (sem_t *)malloc2(sizeof(sem_t));
	forks = sem_open("forks", O_CREAT, 0666, args[0]);
	print_sem = sem_open("print", O_CREAT, 0666, 1);
	time_sem = sem_open("time", O_CREAT, 0666, 1);
	while (i < args[0])
	{
		data[i].forks = forks;
		data[i].print_sem = print_sem;
		data[i].time_sem = time_sem;
		data[i].args = args;
		data[i].num = i + 1;
		data[i].thrd = &thrd[i];
		i++;
	}
}

int main(int argc, char **argv)
{
	int			*args;
	pthread_t	*thrd;
	t_data		*data;
	int			i;
	
	if (argc != 5 && argc != 6)
		exit(1);
	args = get_args(argc, argv);
	thrd = (pthread_t *)malloc2(sizeof(pthread_t) * args[0]);
	data = (t_data *)malloc2(sizeof(t_data) * args[0]);
	set_data(data, args, thrd);
	i = 0;
	while (i < args[0])
	{
		data[i].philo = fork();
		if (!data[i].philo)
		{
			pthread_create(data->thrd, NULL, tf, &data[i]);
			while (1)
			{
				// 스레드종료조건
			}
			exit(9);
		}
		i++;
	}
	while (1){} // monitoring
	exit(7);
}

void	*malloc2(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(-1);
	return (ptr);
}
