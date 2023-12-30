/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 23:21:14 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	args_error(t_wf *frame)
{
	free(frame);
	perror("Number of arguments is not equal to one");
	exit(EXIT_FAILURE);
}

static void	initial_params(t_wf *frame)
{
	frame->zoom = 500 / ft_max(frame->matrix->size_x, frame->matrix->size_y);
	frame->shift_x = 500;
	frame->shift_y = 250;
	frame->angle = 0.8;
	if (frame->zoom == 0)
		frame->zoom = 1;
	frame->matrix->max_height = find_max(frame);
	frame->matrix->min_height = find_min(frame);
	frame->colour_flag = if_colours_exist(frame);
	if (!frame->colour_flag)
		synt_colmap_creation(frame);
}

int	main(int argc, char **argv)
{
	t_wf	*frame;

	frame = (t_wf *)malloc(sizeof(t_wf));
	if (!frame)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		frame->matrix = reader(argv);
		initial_params(frame);
		frame->mlx = mlx_init(1000, 1000, "FdF", true);
		if (!frame->mlx)
			exit(free_if_init_fail(frame));
		frame->img = mlx_new_image(frame->mlx, 1000, 1000);
		render_background(frame);
		draw_wireframe(frame, frame->matrix);
		mlx_image_to_window(frame->mlx, frame->img, 0, 0);
		mlx_key_hook(frame->mlx, move_rotate_iso_exit, frame);
		mlx_scroll_hook(frame->mlx, zoom, frame);
		mlx_loop(frame->mlx);
		ft_exit(frame, 0);
	}
	else
		args_error(frame);
}
