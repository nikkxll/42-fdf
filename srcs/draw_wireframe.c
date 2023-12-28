/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:49:29 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/28 21:56:14 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	last_pixel(t_wf *frame, t_map *matrix, float x, float y)
{
	int	z;

	z = matrix->map[(int)frame->y - 1][(int)frame->x - 1];
	isometric(&x, &y, z);
	x += 1000;
	y += 500;
	mlx_put_pixel(frame->img, x, y,
		colour_to_long(matrix, matrix->size_y - 1, matrix->size_x - 1));
}

void	bresenham(t_wf *frame, t_map *matrix, float x1, float y1, int flag)
{
	float	x_incr;
	float	y_incr;
	float	temp_x;
	float	temp_y;
	int		z;
	int		z1;
	int		i;

	i = 0;
	z = matrix->map[(int)frame->y][(int)frame->x];
	z1 = matrix->map[(int)y1][(int)x1];

	temp_x = frame->x * frame->zoom;
	temp_y = frame->y * frame->zoom;
	x1 *= frame->zoom;
	y1 *= frame->zoom;

	isometric(&temp_x, &temp_y, z);
	isometric(&x1, &y1, z1);

	temp_x += 1000;
	temp_y += 500;
	x1 += 1000;
	y1 += 500;

	x_incr = x1 - temp_x;
	y_incr = y1 - temp_y;

	frame->max = ft_max(fabs(x_incr), fabs(y_incr));
	x_incr /= frame->max;
	y_incr /= frame->max;
	while ((int)(temp_x - x1) || (int)(temp_y - y1))
	{
		if (flag)
			frame->colour = set_x(frame, matrix, i);
		else
			frame->colour = set_y(frame, matrix, i);
		mlx_put_pixel(frame->img, temp_x, temp_y, frame->colour);
		temp_x += x_incr;
		temp_y += y_incr;
		i++;
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
				bresenham(frame, matrix, frame->x + 1, frame->y, 1);
			if (frame->y < matrix->size_y - 1)
				bresenham(frame, matrix, frame->x, frame->y + 1, 0);
			frame->x++;
		}
		frame->y++;
	}
	last_pixel(frame, matrix, (frame->x - 1) * frame->zoom,
		(frame->y - 1) * frame->zoom);
}
