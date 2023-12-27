/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_dotting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:38:36 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 20:05:59 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_checkrange(t_mapinfo *maps, int tmp, int dot, int type)
{
	if (type == 1)
	{
		if (maps->mid_x + dot < 0 || maps->mid_x + dot > maps->img_x || \
			maps->mid_y + tmp < 0 || maps->mid_y + tmp > maps->img_y)
			return (0);
	}
	else if (type == 2)
	{
		if (maps->mid_x + tmp < 0 || maps->mid_x + tmp > maps->img_x || \
			maps->mid_y + dot < 0 || maps->mid_y + dot > maps->img_y)
			return (0);
	}
	return (1);
}

void	ft_xline_x(t_mlx *ptrs, t_mapinfo *maps, int x, int y)
{
	int	dot;
	int	tmp;

	if (maps->proj[y][x][0] > maps->proj[y][x - 1][0])
	{
		dot = maps->proj[y][x - 1][0];
		while (dot <= maps->proj[y][x][0])
		{
			tmp = ft_lineeq_y(dot++, maps->proj[y][x - 1], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 1) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_x(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
	else
	{
		dot = maps->proj[y][x][0];
		while (dot <= maps->proj[y][x - 1][0])
		{
			tmp = ft_lineeq_y(dot++, maps->proj[y][x - 1], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 1) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_x(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
}

void	ft_xline_y(t_mlx *ptrs, t_mapinfo *maps, int x, int y)
{
	int	dot;
	int	tmp;

	if (maps->proj[y][x][1] > maps->proj[y][x - 1][1])
	{
		dot = maps->proj[y][x - 1][1];
		while (dot <= maps->proj[y][x][1])
		{
			tmp = ft_lineeq_x(dot++, maps->proj[y][x - 1], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 2) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_y(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
	else
	{
		dot = maps->proj[y][x][1];
		while (dot <= maps->proj[y][x - 1][1])
		{
			tmp = ft_lineeq_x(dot++, maps->proj[y][x - 1], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 2) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_y(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
}

void	ft_yline_x(t_mlx *ptrs, t_mapinfo *maps, int x, int y)
{
	int	dot;
	int	tmp;

	if (maps->proj[y - 1][x][0] < maps->proj[y][x][0])
	{
		dot = maps->proj[y - 1][x][0];
		while (dot <= maps->proj[y][x][0])
		{
			tmp = ft_lineeq_y(dot++, maps->proj[y - 1][x], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 1) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_x(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
	else
	{
		dot = maps->proj[y][x][0];
		while (dot <= maps->proj[y - 1][x][0])
		{
			tmp = ft_lineeq_y(dot++, maps->proj[y - 1][x], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 1) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_x(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
}

void	ft_yline_y(t_mlx *ptrs, t_mapinfo *maps, int x, int y)
{
	int	dot;
	int	tmp;

	if (maps->proj[y - 1][x][1] < maps->proj[y][x][1])
	{
		dot = maps->proj[y - 1][x][1];
		while (dot <= maps->proj[y][x][1])
		{
			tmp = ft_lineeq_x(dot++, maps->proj[y - 1][x], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 2) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_y(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
	else
	{
		dot = maps->proj[y][x][1];
		while (dot <= maps->proj[y - 1][x][1])
		{
			tmp = ft_lineeq_x(dot++, maps->proj[y - 1][x], maps->proj[y][x]);
			if (ft_checkrange(maps, tmp, dot, 2) == 0)
				continue ;
			ft_trgb(ptrs, maps, p_y(ptrs, maps, tmp, dot), maps->proj[y][x][2]);
		}
	}
}
