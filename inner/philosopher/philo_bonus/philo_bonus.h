/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:53 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/29 01:01:20 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <stdio.h>      // printf
#include <string.h>     // memset
#include <stdlib.h>     // malloc, free, exit
#include <unistd.h>     // write, fork, usleep
#include <sys/types.h>  // fork
#include <sys/wait.h>   // waitpid
#include <sys/time.h>   // gettimeofday
#include <pthread.h>    // pthread_create, pthread_detach, pthread_join
#include <semaphore.h>  // sem_open, sem_close, sem_post, sem_wait, sem_unlink
#include <signal.h>     // kill

typedef struct s_data
{
	pthread_t 		*thrd;
	pid_t			parent;
	pid_t			philo;
	int				*args;
	int				num;
	int				is_die;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*time_sem;
	sem_t			*die;
	sem_t			*full_sem;
	int				cnt_eat;
	struct timeval 	start;
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
long long	timetable(t_data *st);
void		msleep(long long milisecond);
long long	time_last_eat(t_data *st);
void		*tf_main(void *arg);
void	*tf_die(void *arg);

#endif
