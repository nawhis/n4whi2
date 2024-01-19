/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:46:14 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/19 22:09:16 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_tt
{
	pthread_mutex_t mutex;
	pthread_mutex_t *fork_right;
	pthread_mutex_t *fork_left;
	struct timeval 	start;
	int 			num;
	int				*args;
}				t_tt;

long long ms(struct timeval start);
void	tf_odd(t_tt *philo_st);
void	tf_even(t_tt *philo_st);

int	ft_atoi(const char *str)
{
	int		sign;
	int		val;
	size_t	i;

	sign = 1;
	val = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		val = 10 * val + str[i++] - '0';
	return (sign * val);
}

void	*tf(void *arg)
{
	t_tt			*philo_st;
	pthread_mutex_t	tmp;

	philo_st = (t_tt *)arg;
	tmp = philo_st->mutex;
	if (philo_st->num % 2)
		tf_odd(philo_st);
	else
		tf_even(philo_st);
	return (NULL);
}

void	tf_odd(t_tt *philo_st)
{
	struct timeval	end;

	while (1)
	{
		pthread_mutex_lock(philo_st->fork_right);
		pthread_mutex_lock(philo_st->fork_left);
		printf("%lld %d has taken a fork\n", ms(philo_st->start), philo_st->num);
		// printf("left : %p, right : %p\n", philo_st->fork_left, philo_st->fork_right);
		printf("%lld %d is eating\n", ms(philo_st->start), philo_st->num);
		usleep(philo_st->args[2] * 1000);
		pthread_mutex_unlock(philo_st->fork_left);
		pthread_mutex_unlock(philo_st->fork_right);
		printf("%lld %d is sleeping\n", ms(philo_st->start), philo_st->num);
		usleep(philo_st->args[3] * 1000);
		printf("%lld %d is thinking\n", ms(philo_st->start), philo_st->num);
	}
}

void	tf_even(t_tt *philo_st)
{
	struct timeval	end;

	while (1)
	{
		printf("%lld %d is thinking\n", ms(philo_st->start), philo_st->num);
		pthread_mutex_lock(philo_st->fork_right);
		pthread_mutex_lock(philo_st->fork_left);
		printf("%lld %d has taken a fork\n", ms(philo_st->start), philo_st->num);
		// printf("left : %p, right : %p\n", philo_st->fork_left, philo_st->fork_right);
		printf("%lld %d is eating\n", ms(philo_st->start), philo_st->num);
		usleep(philo_st->args[2] * 1000);
		pthread_mutex_unlock(philo_st->fork_right);
		pthread_mutex_unlock(philo_st->fork_left);
		printf("%lld %d is sleeping\n", ms(philo_st->start), philo_st->num);
		usleep(philo_st->args[3] * 1000);
	}
}

long long ms(struct timeval start)
{
	struct timeval		end;
	long long			difftime;

	gettimeofday(&end, NULL);
	difftime = (end.tv_sec - start.tv_sec) * 1000 + \
				(end.tv_usec - start.tv_usec) / 1000;
	return difftime;
}

int	*get_args(int argc, char **argv)
{
	int	*args;
	int	i;

	args = (int *)malloc(sizeof(int) * (argc - 1));
	if (!args)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (args);
}

void	philo_init(t_tt **st, pthread_mutex_t **fork, int *args)
{
	struct timeval	start;
	int				i;

	i = 0;
	gettimeofday(&start, NULL);
	while (i < args[0])
	{
		st[i]->args = (int *)malloc((sizeof(int) * 5));
		st[i]->num = i + 1;
		st[i]->args = args;
		st[i]->start = start;
		st[i]->fork_right = fork[i];
		if (i != args[0] - 1)
			st[i]->fork_left = fork[i + 1];
		else
			st[i]->fork_left = fork[0];
		printf("%d ->", i + 1);
		printf("left : %p ", &st[i]->fork_left);
		printf("right : %p\n", &st[i]->fork_right);
		i++;
	}
}

int main(int argc, char **argv)
{
	pthread_t		*philo;
	pthread_mutex_t	mutex;
	pthread_mutex_t	**fork;
	int				i;
	t_tt 			**st;
	int 			*args;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	args = get_args(argc, argv);
	philo = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	st = (t_tt **)malloc(sizeof(t_tt *) * args[0]);
	while (i < args[0])
		st[i++] = (t_tt *)malloc(sizeof(t_tt) * 1);
	fork = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * args[0]);
	for (int j = 0; j < args[0]; j++)
	{
		fork[j] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(fork[j], NULL);
	}
	philo_init(st, fork, args);
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	i = 0;
	while (i < args[0])
	{
		st[i]->mutex = mutex;
		pthread_create(&philo[i], NULL, tf, st[i]);
		usleep(50);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	while (1){}
}
