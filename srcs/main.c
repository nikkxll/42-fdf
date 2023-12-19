/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/19 17:02:37 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>

#define BPP sizeof(int32_t)
#define GAP 10

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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
	t_map			*matrix;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				i;
	int				j;
	int				pixel_offset;
	int				colours[3];
	int				incr;

	i = 0;
	j = 0;
	pixel_offset = 0;
	if (argc == 2)
	{
		matrix = reader(argv);
		print(matrix);
		printf("\n");
		print_col(matrix);
		mlx = mlx_init(1024, 1024, "MLX42", true);
		if (!mlx)
		{
			ft_error();
			exit(EXIT_FAILURE);
		}

		img = mlx_new_image(mlx, 1024, 1024);
		if (matrix->size_x > matrix->size_y)
			incr = 1024 / matrix->size_x;
		else
			incr = 1024 / matrix->size_y;
		while (i < matrix->size_y)
		{
			j = 0;
			while (j < matrix->size_x)
			{
				colour_modifier(matrix, colours, i, j);
				img->pixels[pixel_offset] = colours[0];
				img->pixels[pixel_offset + 1] = colours[1];
				img->pixels[pixel_offset + 2] = colours[2];
				img->pixels[pixel_offset + 3] = 255;
				j++;
				pixel_offset += incr * BPP;
			}
			i++;
			pixel_offset = i * incr * 1024 * BPP;
		}
		mlx_image_to_window(mlx, img, 0, 0);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free_array((void **)matrix->map, matrix->size_y);
		free_triple_pointer(matrix, matrix->size_y);
		free(matrix);
		return (EXIT_SUCCESS);
	}
}
