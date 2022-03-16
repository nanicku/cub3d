/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:54:39 by mshad             #+#    #+#             */
/*   Updated: 2022/03/16 11:47:25 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_textures(t_data *data, char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
	{
		parsing_tex(data, str);
		if (data->map.no_tex)
			check_tex(data->map.no_tex, data);
		if (data->map.so_tex)
			check_tex(data->map.so_tex, data);
		if (data->map.ea_tex)
			check_tex(data->map.ea_tex, data);
		if (data->map.no_tex)
			check_tex(data->map.we_tex, data);
		return (1);
	}
	return (0);
}

void	parsing_tex(t_data *data, char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		if (data->map.no_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.no_tex = ft_strtrim(str + 3, " \t");
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		if (data->map.so_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.so_tex = ft_strtrim(str + 3, " \t");
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		if (data->map.we_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.we_tex = ft_strtrim(str + 3, " \t");
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		if (data->map.ea_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.ea_tex = ft_strtrim(str + 3, " \t");
	}
}

void	parse_map(t_data *data, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	if (data->map.map_arr != NULL)
	{
		while (data->map.map_arr[i])
			i++;
		tmp = (char **)malloc(sizeof(char *) * (i + 2));
		if (!tmp)
			error_exit("Malloc failed!\n");
		tmp[i + 1] = NULL;
		tmp[i] = ft_strdup(line);
		if (!tmp[i])
			error_exit("Malloc failed!\n");
		while (i-- > 0)
			tmp[i] = data->map.map_arr[i];
		free(data->map.map_arr);
		data->map.map_arr = tmp;
		return ;
	}
	data->map.map_arr = (char **)malloc(sizeof(char *) * 2);
	data->map.map_arr[0] = ft_strdup(line);
	data->map.map_arr[1] = NULL;
}
