/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:46:14 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/30 15:51:08 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	t_tt			*st;
	int				*args;

	if (argc != 5 && argc != 6)
		return (-1);
	args = get_args(argc, argv);
	if (!args)
		return (-1);
	philo = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	st = (t_tt *)malloc(sizeof(t_tt) * args[0]);
	fork = make_fork(args[0]);
	if (!philo || !st || !fork)
	{
		free_func(philo, st, fork, args);
		return (-1);
	}
	if (!philo_create(st, fork, args, philo))
		monitoring(st, args);
	else
		free_two(&st[0]);
	free_func(philo, st, fork, args);
	return (0);
}
