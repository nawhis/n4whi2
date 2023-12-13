/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:37:15 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 18:41:18 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	//mlx_pixel_put(mlx_ptr, win_ptr, ); // 이 스코프로 파라미터 어캐쓰게함?
	return (0);
}

int main(int argc, char **argv)
{
	int		fd;	
	void	*mlx_ptr;
	void	*win_ptr;

	if (argc != 2)
		ft_printf("ARGUMENT ERROR\n");
	fd = open(argv[1], O_RDONLY);

	mlx_ptr = mlx_init();

	
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	
	int x = 0;
	int y = 0;
	while (y < 10)
	{
		while (x < 10)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, 250 + x++, 250 + y, 0xFFFFFF);
		}
		x = 0;
		y++;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}