/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/28 22:04:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_map	*matrix;
	t_wf	*frame;

	frame = (t_wf *)malloc(sizeof(t_wf));
	if (!frame)
		exit(1);
	if (argc == 2)
	{
		matrix = reader(argv);
		frame->zoom = 12;
		frame->mlx = mlx_init(2000, 2000, "FdF", true);
		if (!frame->mlx)
		{
			ft_error();
			exit(EXIT_FAILURE);
		}
		frame->img = mlx_new_image(frame->mlx, 2000, 2000);
		mlx_image_to_window(frame->mlx, frame->img, 0, 0);
		draw_wireframe(frame, matrix);
		mlx_loop(frame->mlx);
		mlx_terminate(frame->mlx);
		free_array((void **)matrix->map, matrix->size_y);
		free_triple_pointer(matrix, matrix->size_y);
		free(matrix);
		return (EXIT_SUCCESS);
	}
}
