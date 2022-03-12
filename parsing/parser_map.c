/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:14:08 by mshad             #+#    #+#             */
/*   Updated: 2022/03/12 21:22:56 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(int err)
{
	printf("Error\n");
	if (err == 1)
		printf("Malloc failed!\n");
	else if (err == 2)
		printf("Arguments error!\n");
	// else if (err == ERR_READING)
	// 	printf("Reading failed!\n");
	else if (err == 3)
		printf("Invalid color!\n");
	// else if (err == INVAL_TEXTURE)
	// 	printf("Invalid texture address!\n");
	exit(1);
}

static int	check_file_format(const char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len)
		len--;
	while (len && map_path[len] != '.')
		len--;
	if (!ft_strcmp(map_path + len + 1, "cub"))
		return (0);
	return (-1);
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
		tmp = (char **)ft_calloc(i + 2, sizeof(char *));
		if (!tmp)
			error_exit(1);
		tmp[i + 1] = NULL;
		tmp[i] = ft_strdup(line);
		if (!tmp[i])
			error_exit(1);
		while (i-- > 0)
			tmp[i] = data->map.map_arr[i];
		free(data->map.map_arr);
		data->map.map_arr = tmp;
		return ;
	}
	data->map.map_arr = (char **)ft_calloc(2, sizeof(char *));
	data->map.map_arr[0] = ft_strdup(line);
	data->map.map_arr[1] = NULL;
}

void	read_next_line(t_data *data, char *line)
{
	int	i;

	if (line == NULL)
	{
		printf("Arguments error!\n");
		exit (1);
	}
	if (data->map.map_arr != NULL)
	{
		parse_map(data, line);
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (parse_textures(data, line + i))
			break ;
		else if (parse_colors(data, line + i))
			break ;
		else if (init_map(data, line))
			break ;
	}
}

void	parser_file(t_data *data, const char *map_file)
{
	int		fd;
	int		ret;
	char	*line;

	if (check_file_format(map_file) == -1)
	{
		printf("error: file not .cub\n");
		exit(1);
	}
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Reading failed!\n");
		exit (1);
	}
	while (1)
	{
		ret = get_next_line(fd, &line);
		read_next_line(data, line);
		free(line);
		if (ret == 0)
			break ;
	}
	close(fd);
	if (data->map.map_arr == NULL)
	{
		printf("No map!\n");
		exit(1);
	}
}
