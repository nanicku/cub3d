/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:29:06 by mshad             #+#    #+#             */
/*   Updated: 2022/03/12 20:40:10 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	error_malloc(void)
{
	ft_putstr_fd("Error with malloc\n", 2);
	exit(1);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_malloc();
	data->player.x = -1;
	data->player.y = -1;
	data->player.dir = -1;
	data->map.map_arr = NULL;
	data->map.texture_addr = (char **)ft_calloc(sizeof(char *), 4);
	data->map.f_color = -1;
	data->map.c_color = -1;
	return (data);
}

void	free_data(t_data *data)
{	
	free(data->map.texture_addr);
	free(data);
}
