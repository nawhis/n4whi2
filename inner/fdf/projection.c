/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:39:47 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 16:27:35 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_topprojection(t_mapinfo *maps, double *point, int x, int y)
{
	maps->proj[y][x][0] = (double)maps->zoom_level * point[0];
	maps->proj[y][x][1] = (double)maps->zoom_level * point[1];
}

void	ft_isometric(t_mapinfo *maps, double *point, int x, int y)
{
	maps->proj[y][x][0] = (double)maps->zoom_level * \
	((sqrt(3) / 2) * (point[0] - point[1]));
	maps->proj[y][x][1] = (double)maps->zoom_level * \
	((point[0] + point[1]) / 2.0 - point[2]);
}

void	ft_projection(t_mapinfo *maps, double *point, int x, int y)
{
	if (maps->proj_mode == 1)
		ft_isometric(maps, maps->point_3d[y][x], x, y);
	else if (maps->proj_mode == 2)
		ft_topprojection(maps, maps->point_3d[y][x], x, y);
}
