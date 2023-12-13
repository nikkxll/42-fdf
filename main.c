/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/13 21:02:41 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	main(int argc, char **argv)
{
	t_map	*matrix;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = 0;
	if (argc == 2)
	{
		matrix = (t_map *)malloc(sizeof(t_map));
		if (!matrix)
			exit(1);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			free(matrix);
			exit(1);
		}
		line = matrix_initializer(matrix, argv, fd);
		matrix = reader(matrix, argv, fd, line);
		if (!matrix)
			return (0);
		print(matrix);
		free_set_four(matrix, matrix->size_y);
		if (close(fd) < 0)
			exit(1);
	}
}
