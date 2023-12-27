/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:29:37 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 17:34:46 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}		t_mlx;

typedef struct s_mapinfo
{
	char	*arg_data;
	double	***point_3d;
	long	***proj;
	int		*size_map;
	int		zoom_level;
	int		proj_mode;
	int		img_x;
	int		img_y;
	int		mid_x;
	int		mid_y;
}		t_mapinfo;

typedef struct s_param
{
	struct s_mlx		*ptrs;
	struct s_mapinfo	*maps;
}		t_param;

void	ft_projection(t_mapinfo *maps, double *point, int x, int y);
void	ft_rotate_x(t_mlx *ptrs, t_mapinfo *maps, char axis, double theta);
void	ft_rotate_y(t_mlx *ptrs, t_mapinfo *maps, char axis, double theta);
void	ft_rotate_z(t_mlx *ptrs, t_mapinfo *maps, char axis, double theta);
int		ft_lineeq_x(int y, long *point1, long *point2);
int		ft_lineeq_y(int x, long *point1, long *point2);
void	ft_trgb(t_mlx *ptrs, t_mapinfo *maps, int pixel, long colors);
int		ft_make2dmaparr(t_mapinfo *maps);
int		ft_make3dmaparr(t_mapinfo *maps);
void	ft_drawmap(t_mlx *ptrs, t_mapinfo *maps);
long	ft_parsecolor(char *s);
void	ft_maptoarr(t_mapinfo *maps, char *map_elem, int x, int y);
void	ft_readmap(t_mlx *ptrs, t_mapinfo *maps, int projection_method);
void	ft_starting(t_mapinfo *maps);
int		ft_mapsize(char *map_argv, int *map_size);
int		ft_exit(void);
void	ft_zoomin(t_param *param);
void	ft_zoomout(t_param *param);
void	ft_transdown(t_param *param);
void	ft_transup(t_param *param);
void	ft_transleft(t_param *param);
void	ft_transright(t_param *param);
void	ft_topprojection(t_mapinfo *maps, double *point, int x, int y);
void	ft_isometric(t_mapinfo *maps, double *point, int x, int y);
void	ft_rotate_hook(int keycode, t_param *param);
void	ft_translate_hook(int keycode, t_param *param);
int		key_hook(int keycode, t_param *param);
void	ft_makeline_x(t_mlx *ptrs, t_mapinfo *maps);
void	ft_makeline_y(t_mlx *ptrs, t_mapinfo *maps);
int		p_x(t_mlx *ptrs, t_mapinfo *maps, int tmp, int start);
int		p_y(t_mlx *ptrs, t_mapinfo *maps, int tmp, int start);
int		ft_checkrange(t_mapinfo *maps, int tmp, int dot, int type);
void	ft_xline_x(t_mlx *ptrs, t_mapinfo *maps, int x, int y);
void	ft_xline_y(t_mlx *ptrs, t_mapinfo *maps, int x, int y);
void	ft_yline_x(t_mlx *ptrs, t_mapinfo *maps, int x, int y);
void	ft_yline_y(t_mlx *ptrs, t_mapinfo *maps, int x, int y);

#endif