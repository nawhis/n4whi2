/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:37:15 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/19 18:04:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

t_mapinfo	*ft_isometric(long *point)
{
	t_mapinfo	*after_point;

	after_point = (t_mapinfo *)ft_calloc(sizeof(t_mapinfo), 3);
	after_point->x = (double)(sqrt(3) / 2) * (double)(point[0] - point[1]);
	after_point->y = ((double)(point[0] + point[1]) / 2.0) - point[2];
	after_point->color = point[3];
	return (after_point);
}

int	ft_lineeq_x(int y, t_mapinfo *point1, t_mapinfo *point2)
{
	double	grad;
	int		x;

	grad = (double)(point2->x - point1->x) / (double)(point2->y - point1->y);
	x = grad * (y - point1->y) + point1->x;
	return (x);
}

int ft_lineeq_y(int x, t_mapinfo *point1, t_mapinfo *point2)
{
	double	grad;
	int		y;

	grad = (double)(point2->y - point1->y) / (double)(point2->x - point1->x);
	y = grad * (x - point1->x) + point1->y;
	return (y);
}

void	ft_makeline_x(void *mlx_ptr, void *win_ptr, t_mapinfo ***map_2d)
{
	int x, y;
	int	tmp;
	int	standard_point;
	int	pix_num;

	y = 0;
	while (map_2d[y])
	{
		x = 1;
		while (map_2d[y][x])
		{
			if (abs(map_2d[y][x]->x - map_2d[y][x-1]->x) > abs(map_2d[y][x]->y - map_2d[y][x-1]->y))
			{
				if (map_2d[y][x]->x > map_2d[y][x-1]->x)
				{
					standard_point = map_2d[y][x-1]->x;
					pix_num = map_2d[y][x]->x - standard_point;
					while (standard_point <= map_2d[y][x]->x)
					{
						tmp = ft_lineeq_y(standard_point, map_2d[y][x-1], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + standard_point++, 500 + tmp, map_2d[y][x-1]->color);
					}
				}
				else
				{
					standard_point = map_2d[y][x]->x;
					pix_num = map_2d[y][x-1]->x - standard_point;
					while (standard_point <= map_2d[y][x-1]->x)
					{
						tmp = ft_lineeq_y(standard_point, map_2d[y][x-1], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + standard_point++, 500 + tmp, map_2d[y][x]->color);
					}
				}
			}
			else
			{
				if (map_2d[y][x]->y > map_2d[y][x-1]->y)
				{
					standard_point = map_2d[y][x-1]->y;
					pix_num = map_2d[y][x]->y - standard_point;
					while (standard_point <= map_2d[y][x]->y)
					{
						tmp = ft_lineeq_x(standard_point, map_2d[y][x-1], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + tmp, 500 + standard_point++, map_2d[y][x]->color);	
					}
				}
				else
				{
					standard_point = map_2d[y][x]->y;
					pix_num = map_2d[y][x-1]->x - standard_point;
					while (standard_point <= map_2d[y][x-1]->y)
					{
						tmp = ft_lineeq_x(standard_point, map_2d[y][x-1], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + tmp, 500 + standard_point++, map_2d[y][x]->color);	
					}
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_makeline_y(void *mlx_ptr, void *win_ptr, t_mapinfo ***map_2d)
{
	int x, y;
	int	tmp;
	int	standard_point;
	int pix_num;

	y = 1;
	while (map_2d[y])
	{
		x = 0;
		while (map_2d[y][x])
		{
			if (abs(map_2d[y][x]->x - map_2d[y-1][x]->x > abs(map_2d[y][x]->y - map_2d[y-1][x]->y)))
			{
				if (map_2d[y-1][x]->x < map_2d[y][x]->x)
				{
					standard_point = map_2d[y-1][x]->x;
					pix_num = map_2d[y][x]->x - standard_point;
					while (standard_point <= map_2d[y][x]->x)
					{
						tmp = ft_lineeq_y(standard_point, map_2d[y-1][x], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + standard_point++, 500 + tmp, map_2d[y-1][x]->color);
					}
				}
				else
				{
					standard_point = map_2d[y][x]->x;
					pix_num = map_2d[y-1][x]->x - standard_point;
					while (standard_point <= map_2d[y-1][x]->x)
					{
						tmp = ft_lineeq_y(standard_point, map_2d[y-1][x], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + standard_point++, 500 + tmp, map_2d[y][x]->color);
					}
				}
			}
			else
			{
				if (map_2d[y-1][x]->y < map_2d[y][x]->y)
				{
					standard_point = map_2d[y-1][x]->y;
					pix_num = map_2d[y][x]->y - standard_point;
					while (standard_point <= map_2d[y][x]->y)
					{
						tmp = ft_lineeq_x(standard_point, map_2d[y-1][x], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + tmp, 500 + standard_point++, map_2d[y-1][x]->color);
					}
				}
				else
				{
					standard_point = map_2d[y][x]->y;
					pix_num = map_2d[y-1][x]->y - standard_point;
					while (standard_point <= map_2d[y-1][x]->y)
					{
						tmp = ft_lineeq_x(standard_point, map_2d[y-1][x], map_2d[y][x]);
						mlx_pixel_put(mlx_ptr, win_ptr, 500 + tmp, 500 + standard_point++, map_2d[y][x]->color);
					}
				}
			}
			x++;
		}
		y++;
	}
}

t_mapinfo	***ft_map2d(int *map_size)
{
	int 		y;
	t_mapinfo	***map_2d;

	y = 0;
	map_2d = (t_mapinfo ***)ft_calloc(sizeof(t_mapinfo ***), map_size[1] + 1);
	while (y < map_size[1])
	{
		map_2d[y++] = (t_mapinfo **)ft_calloc(sizeof(t_mapinfo*), map_size[0] + 1);
	}
	return (map_2d);
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

void	ft_readmap(void *mlx_ptr, void *win_ptr, int fd, int *map_size)
{
	char			**map_line;
	char			**alt_color;
	long			*map_point; // with color info
	t_mapinfo		***map_2d;
	int 			x, y;
	int				dot_length = 2;

	map_point = (long *)ft_calloc(sizeof(long), 4);
	map_2d = ft_map2d(map_size);
	if (!map_point)
		return ;
	y = 0;
	while (y < map_size[1])
	{
		map_point[0] = 0;
		x = 0;
		map_line = ft_split(get_next_line(fd), ' ');
		while (x < map_size[0]) //
		{
			alt_color = ft_split(*map_line, ',');
			map_point[2] = ft_atoi(alt_color[0]);
			if (alt_color[1])
				map_point[3] = ft_parsecolor(alt_color[1]);
			else
				map_point[3] = 0xFFFFFF;
			map_2d[y][x++] = ft_isometric(map_point);
			map_point[0] += dot_length;
			map_line++;
		}
		y++;
		map_point[1] += dot_length;
	}
	ft_printf("OK");
	ft_makeline_x(mlx_ptr, win_ptr, map_2d);
	ft_makeline_y(mlx_ptr, win_ptr, map_2d);
	free(map_point);
	return ;
}

void	ft_mapsize(char *map_argv, int *map_size)
{
	int		fd;
	char	**elems;
	int		max_x;

	fd = open(map_argv, O_RDONLY);
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
				return ;
		map_size[1]++;
		elems = ft_split(get_next_line(fd), ' ');
	}
	close(fd);
	return ;
}

int	deal_key(int keycode, t_vars *ptrs)
{
	if (keycode == 53)
	{
		mlx_destroy_window(ptrs->mlx, ptrs->win);
		exit(0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		fd;
	t_vars	ptrs;
	int		*map_size; // 들어오는 맵의 x 요소 수 y 요소 수

	if (argc != 2)
		ft_printf("ARGUMENT ERROR\n");
	map_size = (int *)ft_calloc(sizeof(int), 2);
	ft_mapsize(argv[1], map_size);
	ft_printf("***map size x : %d . y : %d\n", map_size[0], map_size[1]);
	ptrs.mlx = mlx_init();
	ptrs.win = mlx_new_window(ptrs.mlx, 2000, 2000, "mlx 42");
	fd = open(argv[1], O_RDONLY);
	ft_readmap(ptrs.mlx, ptrs.win, fd, map_size);
	mlx_key_hook(ptrs.win, deal_key, &ptrs);
	mlx_loop(ptrs.mlx); 
}
