/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: nanicku <nanicku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:29:06 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 18:22:47 by nanicku          ###   ########.fr       */
=======
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:29:06 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 18:29:05 by lfornio          ###   ########.fr       */
>>>>>>> mini
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_exit("Malloc failed!\n");
	data->player.x = -1;
	data->player.y = -1;
	data->player.dir = -1;
	data->map.map_arr = NULL;
	data->map.no_tex = NULL;
	data->map.so_tex = NULL;
	data->map.ea_tex = NULL;
	data->map.we_tex = NULL;
	data->map.f_color = -1;
	data->map.c_color = -1;
	return (data);
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (data->map.map_arr[++i])
		free(data->map.map_arr[i]);
	free(data->map.map_arr);
	free(data->map.no_tex);
	free(data->map.so_tex);
	free(data->map.ea_tex);
	free(data->map.we_tex);
	free(data);
}

void	free_str_arr(char **str_arr)
{
	size_t	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}
