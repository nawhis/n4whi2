/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:43:20 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 17:28:35 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawmap(t_mlx *ptrs, t_mapinfo *maps)
{
	ft_makeline_x(ptrs, maps);
	ft_makeline_y(ptrs, maps);
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, ptrs->img, 0, 0);
}

long	ft_parsecolor(char *s)
{
	const char	*base = "0123456789ABCDEF";
	long		res;
	int			digits;

	res = 0;
	s = s + 2;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			res = res * 16 + (*s - '0');
		else if (*s >= 'A' && *s <= 'F')
			res = res * 16 + (*s - 'A' + 10);
		else if (*s >= 'a' && *s <= 'f')
			res = res * 16 + (*s - 'a' + 10);
		s++;
	}
	return (res);
}

void	ft_maptoarr(t_mapinfo *maps, char *map_elem, int x, int y)
{
	char	**alt_color;

	alt_color = ft_split(map_elem, ',');
	if (alt_color[1])
		maps->proj[y][x][2] = ft_parsecolor(alt_color[1]);
	else
		maps->proj[y][x][2] = 0xFFFFFF;
	maps->point_3d[y][x][0] = x;
	maps->point_3d[y][x][1] = y;
	maps->point_3d[y][x][2] = ft_atoi(alt_color[0]);
	ft_projection(maps, maps->point_3d[y][x], x, y);
}

void	ft_readmap(t_mlx *ptrs, t_mapinfo *maps, int projection_method)
{
	char			**map_line;
	char			**alt_color;
	int				x;
	int				y;
	int				fd;

	fd = open(maps->arg_data, O_RDONLY);
	if (ft_make2dmaparr(maps))
		return ;
	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		map_line = ft_split(get_next_line(fd), ' ');
		if (!map_line)
			exit(-1);
		while (x < maps->size_map[0])
			ft_maptoarr(maps, *(map_line++), x++, y);
		y++;
	}
	close(fd);
	ft_drawmap(ptrs, maps);
}
