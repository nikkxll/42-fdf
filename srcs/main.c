/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/18 13:17:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>

#define BPP sizeof(int32_t)

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
	unsigned int	i;
	uint32_t		pixel_offset;

	i = 0;
	if (argc == 2)
	{
		matrix = reader(argv);
		print(matrix);
		printf("\n");
		print_col(matrix);
		mlx = mlx_init(512, 512, "MLX42", true);
		if (!mlx)
		{
			ft_error();
			exit(EXIT_FAILURE);
		}

		img = mlx_new_image(mlx, 256, 256);

		while (i < img->width * img->height)
		{
			pixel_offset = i * BPP;
			img->pixels[pixel_offset] = 0;
			img->pixels[pixel_offset + 1] = 255;
			img->pixels[pixel_offset + 2] = 255;
			img->pixels[pixel_offset + 3] = 255;
			i++;
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
