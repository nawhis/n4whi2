/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:59:35 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:31 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	unlink_all(void)
{
	sem_unlink("die");
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("full_sem");
	sem_unlink("main_sem");
	return ;
}

void	free_all(int *args, pthread_t *thrd, t_data *data)
{
	free(thrd);
	free(data);
	free(args);
	return ;
}

void	close_for_exit(t_data *data, int *args, pthread_t *thrd)
{
	die_flag_setting(data);
	close_all(data[0]);
	clear_children(data, args);
	unlink_all();
	free_all(args, thrd, data);
	return ;
}

void	clear_children(t_data *data, int *args)
{
	int	i;

	i = 1;
	while (i <= args[0])
	{
		kill(data[i].philo, SIGKILL);
		i++;
	}
	return ;
}

void	close_all(t_data data)
{
	sem_close(data.forks);
	sem_close(data.print_sem);
	sem_post(data.full_sem);
	sem_close(data.full_sem);
	sem_post(data.die);
	sem_close(data.die);
	sem_close(data.main_sem);
	return ;
}
