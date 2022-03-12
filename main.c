/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:56 by mshad             #+#    #+#             */
/*   Updated: 2022/03/12 21:28:19 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_data(t_data *data)
{
	printf("%d\n", data->player.x);
	printf("%d\n", data->player.y);
	printf("%c\n", data->player.dir);
	printf("%d\n", data->map.f_color);
	printf("%d\n", data->map.c_color);
	printf("%s\n", data->map.texture_addr[0]);
	printf("%s\n", data->map.texture_addr[1]);
	printf("%s\n", data->map.texture_addr[2]);
	printf("%s\n", data->map.texture_addr[3]);
	printf("%s\n", data->map.map_arr[0]);
	printf("%s\n", data->map.map_arr[1]);
}

static int	error_arg(void)
{
	ft_putstr_fd("error: arg.. Please, usage: ./cub3D [path to map]\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		error_arg();
		return (0);
	}
	printf("Hello, I'm here.. \n");
	printf ("%s\n", argv[1]);
	data = init_data();
	parser_file(data, argv[1]);
	// init_game();
	print_data(data);
	free_data(data);
	return (0);
}
