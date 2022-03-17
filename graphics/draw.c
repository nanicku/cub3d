/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:22:17 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/17 12:24:40 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_line(t_data *data, int x)
{
	data->ray.draw_start = -data->ray.line_height / 2 + W_HEIGHT / 2;
	if (data->ray.draw_start  < 0)
		data->ray.draw_start  = 0;
	data->ray.draw_end = data->ray.line_height / 2 + W_HEIGHT / 2;
	if (data->ray.draw_end >= W_HEIGHT)
		data->ray.draw_end = W_HEIGHT - 1;
	while(data->ray.draw_start  <= data->ray.draw_end)
	{
		ft_pix_put(&data->back, x, data->ray.draw_start , 0xFF0096);
		data->ray.draw_start++;
	}
}
