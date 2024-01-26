/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/26 15:48:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char **argv)
{
	int		*args;
	pid_t	*philo;
	t_data	*data;
	int		i;
	
	if (argc != 5 && argc != 6)
		return (-1);
	i = 0;
	args = get_args(argc, argv);
	philo = (pid_t *)malloc(sizeof(pid_t) * args[0]);
	data = (t_data *)malloc(sizeof(t_data) * args[0]);
	while (i < args[0])
	{
		data[i].args = args;
		data[i].philo = fork();
		i++;
	}
	return (0);
}
