/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:04:01 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 16:27:55 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	//mlx_pixel_put(mlx_ptr, win_ptr, ); // 이 스코프로 파라미터 어캐쓰게함?
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	for (int i = 0 ; i < 500 ; i++)
		for (int j = 0; j < 500 ; j++)
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}