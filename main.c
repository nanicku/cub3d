/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:56 by mshad             #+#    #+#             */
/*   Updated: 2022/03/17 10:29:39 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_data(t_data *data)
{
	int	y = 0;

	printf("%d\n", data->player.x);
	printf("%d\n", data->player.y);
	printf("%c\n", data->player.dir);
	printf("\n");
	printf("%d\n", data->map.f_color);
	printf("%d\n", data->map.c_color);
	printf("\n");
	printf("%s\n", data->map.no_tex);
	printf("%s\n", data->map.so_tex);
	printf("%s\n", data->map.ea_tex);
	printf("%s\n", data->map.we_tex);
	printf("\n");
	while (data->map.map_arr[y] != 0)
	{
		printf("%s\n", data->map.map_arr[y++]);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		printf(YELLOW "Error\nPlease, usage: ./cub3D [path to map]\n");
		return (0);
	}
	data = init_data();
	read_and_parse_file(data, argv[1]);
	print_data(data);
	printf("TEST\n");
	free_data(data);
	return (0);
}
