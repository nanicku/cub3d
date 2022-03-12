/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:08:16 by mshad             #+#    #+#             */
/*   Updated: 2022/03/12 21:11:24 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_natoi(const char *str, int len)
{
	int	res;
	int	ptr;

	res = 0;
	ptr = 0;
	while (ptr < len)
	{
		res = res * 10 + str[ptr] - '0';
		ptr++;
	}
	return (res);
}

int	color_range(char *str, int *i, int *comma)
{
	int	temp;
	int	j;

	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (!ft_isdigit(str[*i]) || (str[*i] == '0' && ft_isdigit(str[*i + 1])))
		error_exit(3);
	j = *i;
	while (ft_isdigit(str[*i]))
		(*i)++;
	temp = ft_natoi(str + j, *i - j);
	if (*i - j > 3 || temp > 255)
		error_exit(3);
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (*comma == 0 && str[*i] == '\0')
		return (temp);
	(*comma)--;
	if (str[*i] == ',')
	{
		(*i)++;
		return (temp);
	}
	error_exit(3);
	return (0);
}

int	color_converting(char *str)
{
	int	i;
	int	temp;
	int	res;
	int	comma;

	i = 0;
	temp = 0;
	res = 0;
	comma = 2;
	while (1)
	{
		temp = color_range(str, &i, &comma);
		res = (res << 8) + temp;
		temp = 0;
		if (str[i] == '\0')
			break ;
	}
	free(str);
	return (res);
}
