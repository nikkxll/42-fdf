/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_extractor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:22:26 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/18 11:08:09 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	colour_format_checker(t_map *matrix, int j, int k)
{
	int		i;
	char	*list;

	list = "1234567890abcdefABCDEF";
	i = 0;
	if (matrix->colmap[j][k][i] == '0' && matrix->colmap[j][k][i + 1] == 'x')
		i += 2;
	else
		return (1);
	while (matrix->colmap[j][k][i] != '\0')
	{
		if (!ft_strchr(list, matrix->colmap[j][k][i]))
			return (1);
		i++;
	}
	if (i > 8 || i < 3)
		return (1);
	return (0);
}

void	colour_array_free(char **temp, t_map *matrix, int j, int k)
{
	while (k--)
		free(matrix->colmap[j][k]);
	free(matrix->colmap[j]);
	exit(free_mtx_map_tmp_gnl(matrix, temp, j + 1, j));
}

void	colour_extractor(char **temp, t_map *matrix, int j)
{
	char	*comma;
	int		k;

	k = 0;
	while (temp[k] != NULL && temp[k][0] != '\0' && temp[k][0] != '\n')
	{
		comma = ft_strchr(temp[k], ',');
		if (comma != NULL)
		{
			*comma = '\0';
			matrix->colmap[j][k] = ft_strdup_nl(comma + 1);
			if (!matrix->colmap[j][k])
				colour_array_free(temp, matrix, j, k);
			if (colour_format_checker(matrix, j, k))
				colour_array_free(temp, matrix, j, k + 1);
		}
		else
			matrix->colmap[j][k] = NULL;
		k++;
	}
}
