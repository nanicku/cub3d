/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:22:17 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/17 15:29:12 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void height_line(t_data *data)
{
	data->ray.draw_start = -data->ray.line_height / 2 + W_HEIGHT / 2;
	if (data->ray.draw_start  < 0)
		data->ray.draw_start  = 0;
	data->ray.draw_end = data->ray.line_height / 2 + W_HEIGHT / 2;
	if (data->ray.draw_end >= W_HEIGHT)
		data->ray.draw_end = W_HEIGHT - 1;
}

void	get_flag_wall(t_data *data)
{
	if(data->ray.side == 1)
	{
		if(data->ray.ray_vec_y > 0)
			data->tex.tex_flag = 0;
		else if(data->ray.ray_vec_y < 0)
			data->tex.tex_flag = 1;
	}
	else if(data->ray.side == 0)
	{
		if(data->ray.ray_vec_x > 0)
			data->tex.tex_flag = 2;
		else if(data->ray.ray_vec_x < 0)
			data->tex.tex_flag = 3;
	}
}


// void draw_texture(t_data *data, int x)
// {
// 	height_line(data);
// 	get_flag_wall(data);

// 	if (data->ray.side == 0)
// 		data->tex.wall_x = data->ray.pl_y + data->ray.perp_wall_dist * data->ray.ray_vec_y;
// 	else
// 		data->tex.wall_x = data->ray.pl_x + data->ray.perp_wall_dist * data->ray.ray_vec_x;
// 	data->tex.wall_x -= floor((data->tex.wall_x));

// 	data->tex.tex_x = (int)(data->tex.wall_x * (double)TEX);
// 	if (data->ray.side == 0 && data->ray.ray_vec_x > 0)
// 		data->tex.tex_x = TEX - data->tex.tex_x - 1;
// 	if (data->ray.side == 1 && data->ray.ray_vec_y < 0)
// 		data->tex.tex_x = TEX - data->tex.tex_x - 1;

// 	data->tex.step = 1.0 * TEX / data->ray.line_height;
// 	data->tex.tex_pos = (data->ray.draw_start  - W_HEIGHT / 2 + data->ray.line_height / 2) * data->tex.step;

// 	// while(drawStart <= drawEnd)
// 	// {
// 	// 	img_pix_put(&data->images->fon, x, drawStart, buf[1][1]);
// 	// 	drawStart++;
// 	// }


// }

void print_line(t_data *data, int x)
{
	height_line(data);
	while(data->ray.draw_start  <= data->ray.draw_end)
	{
		ft_pix_put(&data->back, x, data->ray.draw_start , 0xFF0096);
		data->ray.draw_start++;
	}
}
