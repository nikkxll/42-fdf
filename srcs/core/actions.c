/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:41:03 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 23:16:59 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	img_update(t_wf *frame)
{
	mlx_delete_image(frame->mlx, frame->img);
	frame->img = mlx_new_image(frame->mlx, 1000, 1000);
	render_background(frame);
	draw_wireframe(frame, frame->matrix);
	mlx_image_to_window(frame->mlx, frame->img, 0, 0);
}

static void	set_default(t_wf *frame)
{
	frame->angle = 0.8;
	frame->shift_x = 500;
	frame->shift_y = 250;
	frame->zoom = 500 / ft_max(frame->matrix->size_x, frame->matrix->size_y);
}

void	ft_exit(t_wf *frame, int status)
{
	mlx_delete_image(frame->mlx, frame->img);
	mlx_terminate(frame->mlx);
	free_array((void **)frame->matrix->map, frame->matrix ->size_y);
	free_triple_pointer(frame->matrix, frame->matrix->size_y);
	free(frame->matrix);
	free(frame);
	if (status)
	{
		perror("Map content error");
		exit (EXIT_FAILURE);
	}
	else
		exit (EXIT_SUCCESS);
}

void	move_rotate_iso_exit(mlx_key_data_t keydata, void *param)
{
	t_wf	*frame;

	frame = param;
	if (keydata.key == 265)
		frame->shift_y -= 20;
	if (keydata.key == 264)
		frame->shift_y += 20;
	if (keydata.key == 263)
		frame->shift_x -= 20;
	if (keydata.key == 262)
		frame->shift_x += 20;
	if (keydata.key == 65)
		frame->angle += 0.01;
	if (keydata.key == 68)
		frame->angle -= 0.01;
	if (keydata.key == 83)
		frame->angle = 0;
	if (keydata.key == 87)
		frame->angle = 0.8;
	if (keydata.key == 32)
		set_default(frame);
	if (keydata.key == 256)
		ft_exit(frame, 0);
	img_update(frame);
}

void	zoom(double xdelta, double ydelta, void *param)
{
	t_wf	*frame;

	frame = param;
	(void) xdelta;
	if (ydelta > 0)
		frame->zoom += 1;
	else if (ydelta < 0)
		frame->zoom -= 1;
	img_update(frame);
}
