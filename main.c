/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:56 by mshad             #+#    #+#             */
/*   Updated: 2022/03/12 15:09:16 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	error_arg(void)
{
	ft_putstr_fd("error: arg.. Please, usage: ./cub3D [path to map]\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	// t_data	data;

	if (argc != 2)
	{
		error_arg();
		return (0);
	}
	printf("Hello, I'm here.. \n");
	printf ("%s\n", argv[1]);
	// init_data();
	// main_parser();
	// init_game();

	return (0);
}
