/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:29:37 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/19 15:53:12 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

typedef struct s_vars
{
	void *mlx;
	void *win;
}		t_vars;

typedef struct s_mapinfo
{
	int		x;
	int		y;
	long	color;
}		t_mapinfo;

#endif