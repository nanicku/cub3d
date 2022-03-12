/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:54:39 by mshad             #+#    #+#             */
/*   Updated: 2022/03/12 21:05:46 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_textures(t_data *data, char *str)
{
	int	x;

	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
	{
		if (ft_strncmp(str, "NO ", 3) == 0)
			x = 0;
		else if (ft_strncmp(str, "SO ", 3) == 0)
			x = 1;
		else if (ft_strncmp(str, "WE ", 3) == 0)
			x = 3;
		else
			x = 2;
		if (data->map.texture_addr[x] != NULL)
			error_exit(2);
		data->map.texture_addr[x] = ft_strtrim(str + 3, " \t");
		if (data->map.texture_addr[x] == NULL
			|| ft_strlen(data->map.texture_addr[x]) == 0)
			error_exit(2);
		return (1);
	}
	return (0);
}

int	parse_colors(t_data *data, char *str)
{
	if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
	{
		if (ft_strncmp(str, "F ", 2) == 0)
		{
			if (data->map.f_color != -1)
				error_exit(2);
		data->map.f_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		else
		{
			if (data->map.c_color != -1)
				error_exit(2);
		data->map.c_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		return (1);
	}
	return (0);
}

int	init_map(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (i < 4)
		if (data->map.texture_addr[i++] == NULL)
			error_exit(2);
	if (data->map.f_color == -1 || data->map.c_color == -1)
		error_exit(2);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
	{
		parse_map(data, line);
		return (1);
	}
	else
		error_exit(2);
	return (0);
}
