/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:49:29 by dnikifor          #+#    #+#             */
/*   Updated: 2024/01/25 12:28:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

static void	last_pixel(t_wf *frame, t_map *matrix, float x, float y)
{
	frame->z = matrix->map[(int)frame->y - 1][(int)frame->x - 1];
	isometric(&x, &y, frame->z, frame->angle);
	x += frame->shift_x;
	y += frame->shift_y;
	if (x >= 1000 || y >= 1000 || x <= 0 || y <= 0)
		return ;
	mlx_put_pixel(frame->img, x, y,
		colour_to_long(frame, matrix, matrix->size_y - 1, matrix->size_x - 1));
}

static void	algorithm_preset(t_wf *frame, t_map *matrix, float *x1, float *y1)
{
	frame->colour_delta = 0;
	frame->z = matrix->map[(int)frame->y][(int)frame->x];
	frame->z1 = matrix->map[(int)*y1][(int)*x1];
	if (frame->z > 50000 || frame->z1 > 50000
		|| frame->z < -50000 || frame->z1 < -50000)
		ft_exit(frame, 1);
	frame->temp_x = frame->x * frame->zoom;
	frame->temp_y = frame->y * frame->zoom;
	*x1 *= frame->zoom;
	*y1 *= frame->zoom;
	frame->z *= frame->zoom;
	frame->z1 *= frame->zoom;
	isometric(&frame->temp_x, &frame->temp_y, frame->z, frame->angle);
	isometric(x1, y1, frame->z1, frame->angle);
	frame->temp_x += frame->shift_x;
	frame->temp_y += frame->shift_y;
	*x1 += frame->shift_x;
	*y1 += frame->shift_y;
}

static void	bresenham(t_wf *frame, t_map *matrix, float x1, float y1)
{
	algorithm_preset(frame, matrix, &x1, &y1);
	frame->x_incr = x1 - frame->temp_x;
	frame->y_incr = y1 - frame->temp_y;
	frame->max = ft_max(fabs(frame->x_incr), fabs(frame->y_incr));
	frame->x_incr /= frame->max;
	frame->y_incr /= frame->max;
	while ((int)(frame->temp_x - x1) || (int)(frame->temp_y - y1))
	{
		if (frame->dimension)
			frame->colour = set_x(frame, matrix);
		else
			frame->colour = set_y(frame, matrix);
		if (frame->temp_x >= 1000 || frame->temp_y >= 1000
			|| frame->temp_x <= 0 || frame->temp_y <= 0)
		{
			frame->temp_x += frame->x_incr;
			frame->temp_y += frame->y_incr;
			frame->colour_delta++;
			continue ;
		}
		mlx_put_pixel(frame->img, frame->temp_x, frame->temp_y, frame->colour);
		frame->temp_x += frame->x_incr;
		frame->temp_y += frame->y_incr;
		frame->colour_delta++;
	}
}

void	draw_wireframe(t_wf *frame, t_map *matrix)
{
	frame->y = 0;
	while (frame->y < matrix->size_y)
	{
		frame->x = 0;
		while (frame->x < matrix->size_x)
		{
			if (frame->x < matrix->size_x - 1)
			{
				frame->dimension = 1;
				bresenham(frame, matrix, frame->x + 1, frame->y);
			}
			if (frame->y < matrix->size_y - 1)
			{
				frame->dimension = 0;
				bresenham(frame, matrix, frame->x, frame->y + 1);
			}
			frame->x++;
		}
		frame->y++;
	}
	last_pixel(frame, matrix, (frame->x - 1) * frame->zoom,
		(frame->y - 1) * frame->zoom);
}
