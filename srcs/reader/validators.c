/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:03:46 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/18 15:19:12 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_num_with_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_null(char *str, int j, int temp)
{
	if (str[j] == 0)
		return (1);
	temp = ft_atoi(str);
	while (str[j] != '\n' && str[j] != '\0')
	{
		if (temp == 0)
		{
			if (str[j] == '-' || str[j] == '+')
				j++;
			while (str[j] != '\0')
			{
				if (str[j] != '0' && str[j] != '\n')
					return (1);
				j++;
			}
			continue ;
		}
		j++;
	}
	return (0);
}

int	atoi_checker(t_map *matrix, char **temp, int i, int j)
{
	int	k;

	k = 0;
	while (temp[k] != NULL && temp[k][0] != '\n')
		k++;
	if (k != matrix->size_x)
		return (1);
	while (i < matrix->size_x)
	{
		if (is_valid_null(temp[i], 0, 0) || is_valid_num_with_sign(temp[i]))
			return (1);
		matrix->map[j][i] = ft_atoi(temp[i]);
		i++;
	}
	return (0);
}
