/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:56 by mshad             #+#    #+#             */
/*   Updated: 2022/03/11 11:54:17 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	error_arg(void)
{
	ft_putstr_fd("error: arg.. Please, usage: ./cub3D [path to map]", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (error_arg());
	init_data();
	main_parser();
	// init_game();
	data->win.mlx = mlx_init();
	data->win.win = mlx_new_window(data->win.mlx, 640, 480, "cub3D");
	// data->img.img = mlx_new_image(data->win.mlx, 640, 480);
	// data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
	// 		&data->img.line_length, &data->img.endian);
	player_set();
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img.img, 0, 0);
	mlx_hook(data->win.win, 02, (1L << 0), &key_hook, &data);
	mlx_hook(data->win.win, 17, 0, &close_win, &data);
	mlx_loop(data->win.mlx);
	return (0);
}
