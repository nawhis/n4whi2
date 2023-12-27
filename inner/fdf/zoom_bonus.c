/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:41:49 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 20:12:13 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_exit(void)
{
	exit(17);
	return (0);
}

void	ft_zoomin(t_param *param)
{
	int	x;
	int	y;

	param->maps->zoom_level++;
	y = 0;
	while (y < param->maps->size_map[1])
	{
		x = 0;
		while (x < param->maps->size_map[0])
		{
			ft_projection(param->maps, param->maps->point_3d[y][x], x, y);
			x++;
		}
		y++;
	}
	ft_drawmap(param->ptrs, param->maps);
}

void	ft_zoomout(t_param *param)
{
	int	x;
	int	y;

	if (param->maps->zoom_level > 1)
		param->maps->zoom_level--;
	y = 0;
	while (y < param->maps->size_map[1])
	{
		x = 0;
		while (x < param->maps->size_map[0])
		{
			ft_projection(param->maps, param->maps->point_3d[y][x], x, y);
			x++;
		}
		y++;
	}
	ft_drawmap(param->ptrs, param->maps);
}
