/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:02:18 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/31 18:42:51 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_tt *st, int *args)
{
	int	i;
	int	cnt;

	while (1)
	{
		i = 0;
		cnt = 0;
		while (i < args[0])
		{
			if (time_last_eat(&st[i]) == -1)
			{
				message_func_d(&st[i]);
				remove_thread(st);
				return ;
			}
			pthread_mutex_lock(st[i].cnt_eat_mutex);
			if (args[4] != -1 && st[i].cnt_eat >= args[4])
				cnt++;
			pthread_mutex_unlock(st[i++].cnt_eat_mutex);
		}
		if (cnt == args[0])
			break ;
	}
	remove_thread(st);
	return ;
}
