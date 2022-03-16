/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:08:16 by mshad             #+#    #+#             */
/*   Updated: 2022/03/16 10:16:45 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(int red, int green, int blue)
{
	return ((((red * 256) + green) * 256) + blue);
}

int	color_converting(char *str)
{
	int		result;
	char	**rgb;

	rgb = ft_split(str, ',');
	result = 0;
	while (rgb[result])
		result++;
	if (result != 3)
	{
		free_str_arr(rgb);
		error_exit("Invalid color!\n");
	}
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255
		|| ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255
		|| ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
	{
		free_str_arr(rgb);
		error_exit("Invalid color!\n");
	}
	result = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_str_arr(rgb);
	return (result);
}

int	parse_colors(t_data *data, char *str)
{
	if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
	{
		if (ft_strncmp(str, "F ", 2) == 0)
		{
			if (data->map.f_color != -1)
				error_exit("Arguments error!\n");
		data->map.f_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		else
		{
			if (data->map.c_color != -1)
				error_exit("Arguments error!\n");
		data->map.c_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		return (1);
	}
	return (0);
}
