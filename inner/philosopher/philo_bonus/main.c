/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/28 22:42:57 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_data(t_data *data, int *args, pthread_t *thrd)
{
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*time_sem;
	sem_t			*full_sem;
	// sem_t			*start_sem;
	int				i;
	struct timeval	start;

	i = 0;
	gettimeofday(&start, NULL);
	sem_unlink("die");
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("time");
	sem_unlink("full_sem");
	full_sem = sem_open("full_sem", O_CREAT, 0666, args[0]);
	forks = sem_open("forks", O_CREAT, 0666, args[0]);
	print_sem = sem_open("print", O_CREAT, 0666, 1);
	time_sem = sem_open("time", O_CREAT, 0666, 1);
	while (i <= args[0])
	{
		data[i].cnt_eat = 0;
		data[i].full_sem = full_sem;
		data[i].start = start;
		data[i].last_eat = start;
		data[i].forks = forks;
		data[i].print_sem = print_sem;
		data[i].time_sem = time_sem;
		data[i].args = args;
		data[i].num = i;
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
	sem_t		*die;
	
	if (argc != 5 && argc != 6)
		exit(1);
	args = get_args(argc, argv);
	thrd = (pthread_t *)malloc2(sizeof(pthread_t) * (args[0] + 1));
	data = (t_data *)malloc2(sizeof(t_data) * (args[0] + 1));
	die = sem_open("die", O_CREAT, 0666, args[0]);
	set_data(data, args, thrd);
	i = 1;
	data[0].philo = 0;
	while (i <= args[0])
	{
		data[i].die = die;
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
		i++;
	}
	msleep(60);
	pthread_create(data[0].thrd, NULL, tf_main, &data[0]);
	pthread_detach(*data[0].thrd);
	sem_wait(die);
	for (int j = args[0]; j >= 1; j--)
		kill(data[j].philo, SIGKILL);
	sem_close(data[0].forks);
	sem_close(data[0].time_sem);
	sem_close(data[0].print_sem);
	sem_close(data[0].full_sem);
	sem_close(data[0].die);
	sem_unlink("full_sem");
	sem_unlink("die");
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("time");
	printf("종료합니다요\n");
	exit(0);
}	

void	*malloc2(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(-1);
	return (ptr);
}
