/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:06:40 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/30 15:51:02 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tt
{
	pthread_t		philo;
	pthread_mutex_t	*flag_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*cnt_eat_mutex;
	pthread_mutex_t	*time;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	struct timeval	start;
	struct timeval	last_eat;
	int				*flag_stop;
	int				num;
	int				*args;
	int				cnt_eat;
}				t_tt;

void			*tf(void *arg);
void			tf_odd(t_tt *philo_st);
void			tf_even(t_tt *philo_st);
int				ft_atoi(const char *str);
int				*get_args(int argc, char **argv);
int				philo_init(t_tt *st, int *args);
void			remove_thread(t_tt *st);
void			count_eat(t_tt *philo_st);
pthread_mutex_t	*make_fork(int nums);
int				philo_create(t_tt *st, pthread_mutex_t *fork, \
				int *args, pthread_t *philo);
int 			philo_init2(t_tt *st, pthread_mutex_t *fork, int *args, pthread_t *philo);
long long		timetable(t_tt *st);
long long		time_last_eat(t_tt *st);
int				message_func_d(t_tt *philo_st);
int				message_func_f(t_tt *philo_st);
int				message_func_e(t_tt *philo_st);
int				message_func_s(t_tt *philo_st);
int				message_func_t(t_tt *philo_st);
int				mutex_init(pthread_mutex_t *time, pthread_mutex_t *cnt_eat_mutex, \
				pthread_mutex_t *print_mutex, pthread_mutex_t *flag_mutex);
void			count_eat(t_tt *philo_st);
void			msleep(long long milisecond);
void			monitoring(t_tt *st, int *args);
void			free_func(pthread_t *philo, t_tt *st, \
				pthread_mutex_t *fork, int *args);
void			free_two(t_tt *st);

#endif