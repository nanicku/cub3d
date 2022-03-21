/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanicku <nanicku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:56 by mshad             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/21 18:22:15 by nanicku          ###   ########.fr       */
=======
/*   Updated: 2022/03/21 18:28:04 by lfornio          ###   ########.fr       */
>>>>>>> mini
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	graphics(data);
	free_data(data);
	return (0);
}
