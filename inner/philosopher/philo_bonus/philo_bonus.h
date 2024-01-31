/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:53 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:30 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

typedef struct s_data
{
	pthread_t		*thrd;
	pid_t			parent;
	pid_t			philo;
	int				*args;
	int				num;
	int				is_die;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*die;
	sem_t			*full_sem;
	sem_t			*main_sem;
	int				cnt_eat;
	struct timeval	start;
	struct timeval	last_eat;
}	t_data;

int			*get_args(int argc, char **argv);
int			ft_atoi(const char *str);
void		*tf(void *arg);
void		tf_odd(t_data *data);
void		tf_even(t_data *data);
void		*malloc2(int size);
void		message_func_d(t_data *data);
void		message_func_f(t_data *data);
void		message_func_e(t_data *data, int time);
void		message_func_s(t_data *data, int time);
void		message_func_t(t_data *data);
void		set_data(t_data *data, int *args, pthread_t *thrd);
long long	timetable(t_data *st);
void		msleep(long long milisecond);
long long	time_last_eat(t_data *st);
void		*tf_main(void *arg);
void		*tf_die(void *arg);
void		unlink_all(void);
void		data_setting(t_data *data, int *args);
void		close_all(t_data data);
void		clear_children(t_data *data, int *args);
void		start_children(t_data *data, int *args, sem_t *main_sem);
void		die_flag_setting(t_data *data);
void		close_for_exit(t_data *data, int *args, pthread_t *thrd);

#endif
