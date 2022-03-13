/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:52:44 by mshad             #+#    #+#             */
/*   Updated: 2022/03/13 13:16:01 by mshad            ###   ########.fr       */
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
	else if (err == 4)
		printf("Reading failed!\n");
	else if (err == 3)
		printf("Invalid color!\n");
	// else if (err == INVAL_TEXTURE)
	// 	printf("Invalid texture address!\n");
	else if (err == 6)
		printf("error: file not .cub\n");
	else if (err == 7)
		printf("No map!\n");
	else if (err == 8)
		printf("error: not reading file\n");
	exit(1);
}
