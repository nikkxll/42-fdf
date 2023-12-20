/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/20 15:47:14 by dnikifor         ###   ########.fr       */
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

void	horizontal_lines(mlx_image_t *img, int incr, int offset_x, int offset_y)
{
	int	i;

	i = 1;
	while (i < incr)
	{
		mlx_put_pixel(img, offset_x + i, offset_y, 0x000000FF);
		i++;
	}
}

void	vertical_lines(mlx_image_t *img, int incr, int offset_x, int offset_y)
{
	int	i;

	i = 0;
	while (i++ < incr - 1)
		mlx_put_pixel(img, offset_x, offset_y - i, 0x000000FF);
}

int	main(int argc, char **argv)
{
	t_map			*matrix;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				i;
	int				j;
	int				pixel_offset_x;
	int				pixel_offset_y;
	int				incr;

	i = 0;
	j = 1;
	pixel_offset_x = 0;
	pixel_offset_y = 0;
	if (argc == 2)
	{
		matrix = reader(argv);
		// print(matrix);
		// printf("\n");
		// print_col(matrix);
		mlx = mlx_init(1500, 1500, "MLX42", true);
		if (!mlx)
		{
			ft_error();
			exit(EXIT_FAILURE);
		}

		img = mlx_new_image(mlx, 1024, 1024);
		if (matrix->size_x > matrix->size_y)
			incr = 1023 / matrix->size_x;
		else
			incr = 1023 / matrix->size_y;
		while (i < matrix->size_y)
		{
			j = 0;
			while (j < matrix->size_x - 1)
			{
				mlx_put_pixel(img, pixel_offset_x, pixel_offset_y,
					colour_modifier(matrix, i, j));
				if (i > 0)
					vertical_lines(img, incr, pixel_offset_x, pixel_offset_y);
				j++;
				horizontal_lines(img, incr, pixel_offset_x, pixel_offset_y);
				pixel_offset_x += incr;
				if (j == matrix->size_x - 1 && i > 0)
					vertical_lines(img, incr, pixel_offset_x, pixel_offset_y);
			}
			mlx_put_pixel(img, pixel_offset_x, pixel_offset_y,
				colour_modifier(matrix, i, j));
			i++;
			pixel_offset_y = i * incr;
			pixel_offset_x = 0;
		}
		mlx_image_to_window(mlx, img, 200, 200);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free_array((void **)matrix->map, matrix->size_y);
		free_triple_pointer(matrix, matrix->size_y);
		free(matrix);
		return (EXIT_SUCCESS);
	}
}
