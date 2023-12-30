/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:41:03 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 01:10:51 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_update(t_wf *frame)
{
	mlx_delete_image(frame->mlx, frame->img);
	frame->img = mlx_new_image(frame->mlx, 1000, 1000);
	render_background(frame);
	draw_wireframe(frame, frame->matrix);
	mlx_image_to_window(frame->mlx, frame->img, 0, 0);
}

void	set_default(t_wf *frame)
{
	frame->angle = 0.8;
	frame->shift_x = 500;
	frame->shift_y = 250;
	frame->zoom = 500 / ft_max(frame->matrix->size_x, frame->matrix->size_y);
}

void	move_rotate_iso(mlx_key_data_t keydata, void *param)
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
