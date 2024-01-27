/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/27 23:09:34 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int g_running = 1;

void handle_sigint(int sig) {
	sig = sig + 1;
    g_running = 0;
}

void	set_data(t_data *data, int *args, pthread_t *thrd)
{
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*time_sem;
	int				i;
	struct timeval	start;

	i = 0;
	gettimeofday(&start, NULL);
	forks = sem_open("forks", O_CREAT, 0666, args[0]);
	print_sem = sem_open("print", O_CREAT, 0666, 1);
	time_sem = sem_open("time", O_CREAT, 0666, 1);
	while (i < args[0])
	{
		data[i].start = start;
		data[i].last_eat = start;
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
	int			is_die;
	
	if (argc != 5 && argc != 6)
		exit(1);
	signal(SIGINT, handle_sigint);
	args = get_args(argc, argv);
	thrd = (pthread_t *)malloc2(sizeof(pthread_t) * args[0]);
	data = (t_data *)malloc2(sizeof(t_data) * args[0]);
	is_die = 0;
	set_data(data, args, thrd);
	i = 0;
	while (i < args[0])
	{
		data[i].is_die = &is_die;
		data[i].philo = fork();
		if (!data[i].philo)
		{
			pthread_create(data[i].thrd, NULL, tf, &data[i]);
			while (1)
			{
				if (time_last_eat(&data[i]) == -1)
					break;
			}
			exit(9);
		}
		i++;
	}
	while (1) 
	{
		printf("%d, ", is_die);
		if (g_running == 0 || is_die)
		{
			printf("삭제를 진행합니다\n");
			for (int j = 0 ; j < args[0]; j++)
				kill(data[j].philo, SIGTERM);
			sem_close(data[0].forks);
			sem_close(data[0].time_sem);
			sem_close(data[0].print_sem);
			sem_unlink("forks");
			sem_unlink("print");
			sem_unlink("time");
			printf("먼저가요\n");
			waitpid(-1, NULL, 0);
			exit(0);
		}
	}	
}

void	*malloc2(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(-1);
	return (ptr);
}
