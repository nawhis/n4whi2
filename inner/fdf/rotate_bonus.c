/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:40:21 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 20:11:48 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_rotate_x(t_mlx *ptrs, t_mapinfo *maps, char axis, double theta)
{
	int		x;
	int		y;
	double	tmp[3];

	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		while (x < maps->size_map[0])
		{
			tmp[1] = cos(theta) * (double)maps->point_3d[y][x][1] - \
			sin(theta) * (double)maps->point_3d[y][x][2];
			tmp[2] = sin(theta) * (double)maps->point_3d[y][x][1] + \
			cos(theta) * (double)maps->point_3d[y][x][2];
			maps->point_3d[y][x][1] = tmp[1];
			maps->point_3d[y][x][2] = tmp[2];
			ft_projection(maps, maps->point_3d[y][x], x, y);
			x++;
		}
		y++;
	}
	ptrs->img_data = mlx_get_data_addr(ptrs->img, \
	&ptrs->bpp, &ptrs->size_line, &ptrs->endian);
	ft_drawmap(ptrs, maps);
}

void	ft_rotate_y(t_mlx *ptrs, t_mapinfo *maps, char axis, double theta)
{
	int			x;
	int			y;
	double		tmp[3];

	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		while (x < maps->size_map[0])
		{
			tmp[0] = cos(theta) * (double)maps->point_3d[y][x][0] - \
			sin(theta) * (double)maps->point_3d[y][x][2];
			tmp[2] = sin(theta) * (double)maps->point_3d[y][x][0] + \
			cos(theta) * (double)maps->point_3d[y][x][2];
			maps->point_3d[y][x][0] = tmp[0];
			maps->point_3d[y][x][2] = tmp[2];
			ft_projection(maps, maps->point_3d[y][x], x, y);
			x++;
		}
		y++;
	}
	ptrs->img_data = mlx_get_data_addr(ptrs->img, \
	&ptrs->bpp, &ptrs->size_line, &ptrs->endian);
	ft_drawmap(ptrs, maps);
}

void	ft_rotate_z(t_mlx *ptrs, t_mapinfo *maps, char axis, double theta)
{
	int			x;
	int			y;
	double		tmp[3];

	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		while (x < maps->size_map[0])
		{
			tmp[0] = cos(theta) * (double)maps->point_3d[y][x][0] - \
			sin(theta) * (double)maps->point_3d[y][x][1];
			tmp[1] = sin(theta) * (double)maps->point_3d[y][x][0] + \
			cos(theta) * (double)maps->point_3d[y][x][1];
			maps->point_3d[y][x][0] = tmp[0];
			maps->point_3d[y][x][1] = tmp[1];
			ft_projection(maps, maps->point_3d[y][x], x, y);
			x++;
		}
		y++;
	}
	ptrs->img_data = mlx_get_data_addr(ptrs->img, \
	&ptrs->bpp, &ptrs->size_line, &ptrs->endian);
	ft_drawmap(ptrs, maps);
}
