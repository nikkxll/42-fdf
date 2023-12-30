/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 00:56:02 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#include "MLX42/MLX42.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	initial_params(t_wf *frame)
{
	frame->zoom = 500 / ft_max(frame->matrix->size_x, frame->matrix->size_y);
	frame->shift_x = 500;
	frame->shift_y = 250;
	frame->angle = 0.8;
	if (frame->zoom == 0)
		frame->zoom = 1;
}

int	main(int argc, char **argv)
{
	t_wf	*frame;

	frame = (t_wf *)malloc(sizeof(t_wf));
	if (!frame)
		exit(1);
	if (argc == 2)
	{
		frame->matrix = reader(argv);
		initial_params(frame);
		frame->mlx = mlx_init(1000, 1000, "FdF", true);
		if (!frame->mlx)
			ft_error();
		frame->img = mlx_new_image(frame->mlx, 1000, 1000);
		render_background(frame);
		draw_wireframe(frame, frame->matrix);
		mlx_image_to_window(frame->mlx, frame->img, 0, 0);
		mlx_key_hook(frame->mlx, move_rotate_iso, frame);
		mlx_scroll_hook(frame->mlx, zoom, frame);
		mlx_loop(frame->mlx);
		mlx_delete_image(frame->mlx, frame->img);
		mlx_terminate(frame->mlx);
		free_array((void **)frame->matrix->map, frame->matrix ->size_y);
		free_triple_pointer(frame->matrix, frame->matrix->size_y);
		free(frame->matrix);
		return (EXIT_SUCCESS);
	}
}
