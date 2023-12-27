/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:06:32 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/27 20:07:38 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_rotate_hook(int keycode, t_param *param)
{
	if (keycode == 86)
		ft_rotate_x(param->ptrs, param->maps, 'x', M_PI / 18);
	else if (keycode == 87)
		ft_rotate_y(param->ptrs, param->maps, 'y', M_PI / 18);
	else if (keycode == 88)
		ft_rotate_z(param->ptrs, param->maps, 'z', M_PI / 18);
	else if (keycode == 83)
		ft_rotate_x(param->ptrs, param->maps, 'x', -M_PI / 18);
	else if (keycode == 84)
		ft_rotate_y(param->ptrs, param->maps, 'y', -M_PI / 18);
	else if (keycode == 85)
		ft_rotate_z(param->ptrs, param->maps, 'z', -M_PI / 18);
}

void	ft_translate_hook(int keycode, t_param *param)
{
	if (keycode == 123)
		ft_transleft(param);
	else if (keycode == 124)
		ft_transright(param);
	else if (keycode == 125)
		ft_transdown(param);
	else if (keycode == 126)
		ft_transup(param);
}

int	key_hook(int keycode, t_param *param)
{
	mlx_destroy_image(param->ptrs->mlx, param->ptrs->img);
	param->ptrs->img = mlx_new_image(param->ptrs->mlx, \
	param->maps->img_x, param->maps->img_y);
	if (keycode == 53)
		exit(53);
	else if (keycode >= 83 && keycode <= 88)
		ft_rotate_hook(keycode, param);
	else if (keycode >= 123 && keycode <= 126)
		ft_translate_hook(keycode, param);
	else if (keycode == 24)
		ft_zoomin(param);
	else if (keycode == 27)
		ft_zoomout(param);
	else if (keycode == 18)
	{
		param->maps->proj_mode = 1;
		ft_readmap(param->ptrs, param->maps, param->maps->proj_mode);
	}
	else if (keycode == 19)
	{
		param->maps->proj_mode = 2;
		ft_readmap(param->ptrs, param->maps, param->maps->proj_mode);
	}
	ft_printf("%d %d\n", param->maps->mid_x, param->maps->mid_y);
	return (0);
}
