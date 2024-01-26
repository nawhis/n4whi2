/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:53 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/26 15:47:19 by sihkang          ###   ########seoul.kr  */
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
	pid_t	philo;
	int		*args;
}	t_data;

int		*get_args(int argc, char **argv);
int		ft_atoi(const char *str);

#endif