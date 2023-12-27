/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eqs_arrays_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:44:03 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 20:07:19 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_lineeq_x(int y, long *point1, long *point2)
{
	double	grad;
	int		x;

	grad = (double)(point2[0] - point1[0]) / (double)(point2[1] - point1[1]);
	x = grad * (y - point1[1]) + point1[0];
	return (x);
}

int	ft_lineeq_y(int x, long *point1, long *point2)
{
	double	grad;
	int		y;

	grad = (double)(point2[1] - point1[1]) / (double)(point2[0] - point1[0]);
	y = grad * (x - point1[0]) + point1[1];
	return (y);
}

void	ft_trgb(t_mlx *ptrs, t_mapinfo *maps, int pixel, long colors)
{
	if (pixel < 0 || pixel > maps->img_x * maps->img_y * 4)
		return ;
	ptrs->img_data[pixel + 2] = colors >> 16 & 0xFF;
	ptrs->img_data[pixel + 1] = colors >> 8 & 0xFF;
	ptrs->img_data[pixel + 0] = colors & 0xFF;
}

int	ft_make2dmaparr(t_mapinfo *maps)
{
	int	y;
	int	x;

	y = 0;
	if (maps->proj)
		return (0);
	maps->proj = (long ***)ft_calloc(sizeof(long **), maps->size_map[1] + 1);
	if (!maps->proj)
		exit(-1);
	while (y < maps->size_map[1])
	{
		maps->proj[y] = (long **)ft_calloc(sizeof(long *), \
		maps->size_map[0] + 1);
		if (!maps->proj[y])
			exit(-1);
		x = 0;
		while (x < maps->size_map[0])
		{
			maps->proj[y][x] = (long *)ft_calloc(sizeof(long), 3);
			if (!maps->proj[y][x++])
				exit(-1);
		}
		y++;
	}
	return (0);
}

int	ft_make3dmaparr(t_mapinfo *maps)
{
	int	y;
	int	x;

	y = 0;
	maps->point_3d = (double ***)ft_calloc(sizeof(double **), \
					maps->size_map[1] + 1);
	if (!maps->point_3d)
		exit(-1);
	while (y < maps->size_map[1])
	{
		maps->point_3d[y] = (double **)ft_calloc(sizeof(double *), \
							maps->size_map[0] + 1);
		if (!maps->point_3d[y])
			exit(-1);
		x = 0;
		while (x < maps->size_map[0])
		{
			maps->point_3d[y][x] = (double *)ft_calloc(sizeof(double), 4);
			if (!maps->point_3d[y][x++])
				exit(-1);
		}
		y++;
	}
	return (0);
}
