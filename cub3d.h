/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:57:01 by mshad             #+#    #+#             */
/*   Updated: 2022/03/13 10:43:29 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_map
{
	char	**map_arr;		//карта-массив
	int		f_color;
	int		c_color;
	char	**texture_addr;
}	t_map;

typedef struct s_data
{
	t_win		win;
	t_player	player;
	t_map		map;
}	t_data;

int		main(int argc, char **argv);
t_data	*init_data(void);
void	free_data(t_data *data);
void	parser_file(t_data *data, const char *argv);
void	error_exit(int err);
void	read_next_line(t_data *data, char *line);
void	parse_map(t_data *data, char *line);
int		check_file_format(const char *map_path, int fd);
int		parse_textures(t_data *data, char *str);
int		parse_colors(t_data *data, char *str);
int		init_map(t_data *data, char *line);
int		ft_natoi(const char *str, int len);
int		color_range(char *str, int *i, int *comma);
int		color_converting(char *str);

#endif