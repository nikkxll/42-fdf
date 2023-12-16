/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/16 17:02:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print(t_map *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < matrix->size_y)
	{
		j = 0;
		while (j < matrix->size_x)
		{
			printf("%d ", matrix->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_col(t_map *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < matrix->size_y)
	{
		j = 0;
		while (j < matrix->size_x)
		{
			printf("%s ", matrix->colmap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*matrix;

	if (argc == 2)
	{
		matrix = reader(argv);
		print(matrix);
		printf("\n");
		print_col(matrix);
		free_array((void **)matrix->map, matrix->size_y);
		free_triple_pointer(matrix, matrix->size_y);
		free(matrix);
	}
}
