/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:57:01 by mshad             #+#    #+#             */
/*   Updated: 2022/03/12 14:57:02 by mshad            ###   ########.fr       */
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

typedef struct s_data
{
	t_win		win;
	t_player	player;
}	t_data;

int		main(int argc, char **argv);

#endif