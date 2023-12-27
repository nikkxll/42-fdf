/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/27 17:42:17 by dnikifor         ###   ########.fr       */
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

int	set_colour(int i, t_map *matrix, t_wf *frame, int flag)
{
	long	a;
	long	b;

	if (flag)
	{
		a = colour_to_long(matrix, frame->row, frame->column - 1);
		b = colour_to_long(matrix, frame->row, frame->column);
		frame->incr[0] = (float)(((a >> 24) & 0xFF) - ((b >> 24) & 0xFF)) / frame->steps;
		frame->incr[1] = ((a >> 16) & 0xFF - (b >> 16) & 0xFF) / frame->steps;
		frame->incr[2] = ((a >> 8) & 0xFF - (b >> 8) & 0xFF) / frame->steps;
		i = 0;
	}
	return (0);
}

void	horizontal_lines(mlx_image_t *img, t_wf *frame, t_map *matrix)
{
	int	i;
	int	colour;

	i = 1;
	while (i < frame->steps)
	{
		colour = set_colour(i, matrix, frame, 1);
		mlx_put_pixel(img, frame->offset_x + i, frame->offset_y, 255);
		i++;
	}
}

void	vertical_lines(mlx_image_t *img, t_wf *frame, t_map *matrix)
{
	int	i;
	int	colour;

	i = 0;
	while (i++ < frame->steps - 1)
	{
		colour = set_colour(i, matrix, frame, 1);
		mlx_put_pixel(img, frame->offset_x, frame->offset_y - i, 255);
	}
}

int	main(int argc, char **argv)
{
	t_map			*matrix;
	t_wf			*frame;
	mlx_t			*mlx;
	mlx_image_t		*img;

	frame = (t_wf *)malloc(sizeof(t_wf));
	if (!frame)
	{
		ft_error();
		exit(EXIT_FAILURE);
	}
	frame->column = 1;
	frame->row = 0;
	frame->offset_x = 0;
	frame->offset_y = 0;
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
			frame->steps = 1023 / matrix->size_x;
		else
			frame->steps = 1023 / matrix->size_y;
		while (frame->row < matrix->size_y)
		{
			frame->column = 0;
			while (frame->column < matrix->size_x - 1)
			{
				mlx_put_pixel(img, frame->offset_x, frame->offset_y,
					colour_to_long(matrix, frame->row, frame->column));
				if (frame->row > 0)
					vertical_lines(img, frame, matrix);
				frame->column++;
				horizontal_lines(img, frame, matrix);
				frame->offset_x += frame->steps;
				if (frame->column == matrix->size_x - 1 && frame->row > 0)
					vertical_lines(img, frame, matrix);
			}
			mlx_put_pixel(img, frame->offset_x, frame->offset_y,
				colour_to_long(matrix, frame->row, frame->column));
			frame->row++;
			frame->offset_y = frame->row * frame->steps;
			frame->offset_x = 0;
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
