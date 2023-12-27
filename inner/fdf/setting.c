/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:42:32 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 18:46:50 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_starting(t_mapinfo *maps)
{
	maps->img_x = 2000;
	maps->img_y = 1300;
	maps->mid_x = maps->img_x / 2;
	maps->mid_y = maps->img_y / 2;
	maps->zoom_level = 1;
	maps->proj_mode = 1;
}

void	ft_validmap(char *map_argv, int fd)
{
	char	**title;
	int		i;

	i = 1;
	title = ft_split(map_argv, '.');
	while (title[i])
	{
		if (title[i + 1] == NULL && ft_strncmp(title[i], "fdf", 3) == 0)
		{
			if (fd < 0 || fd == 2)
			{
				ft_printf("OPEN ERROR !\n");
				exit(-1);
			}
			return ;
		}
		i++;
	}
	ft_printf("INVALID MAP FORMAT!\n");
	exit(-1);
}

int	ft_mapsize(char *map_argv, int *map_size)
{
	int		fd;
	char	**elems;
	int		max_x;

	fd = open(map_argv, O_RDONLY);
	ft_validmap(map_argv, fd);
	elems = ft_split(get_next_line(fd), ' ');
	while (elems)
	{
		map_size[0] = 0;
		while (*elems)
		{
			elems++;
			map_size[0]++;
		}
		if (map_size[1] == 0)
			max_x = map_size[0];
		else
			if (max_x != map_size[0])
				return (-1);
		map_size[1]++;
		elems = ft_split(get_next_line(fd), ' ');
	}
	close(fd);
	return (0);
}
