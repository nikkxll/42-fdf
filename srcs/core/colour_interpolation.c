/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_interpolation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:46:36 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 16:53:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	float_to_int_colour(float number)
{
	int		whole_part;
	float	remainder;

	whole_part = (int)number;
	remainder = number - whole_part;
	if (remainder > 0.5 || (remainder > -0.5 && remainder < 0))
		return (ceil(number));
	else
		return (floor(number));
}

long	rgb_to_long(int red, int green, int blue)
{
	long	color;

	color = 0;
	color |= (red << 24) & 0xFF000000;
	color |= (green << 16) & 0x00FF0000;
	color |= (blue << 8) & 0x0000FF00;
	color |= (255 & 0x000000FF);
	return (color);
}

long	getting_new_colour(t_wf *frame, long a, long b)
{
	float	incr_sum[3];
	long	new_col;

	frame->incr[0] = (float)(((b >> 24) & 0xFF) - ((a >> 24) & 0xFF))
		/frame->max;
	frame->incr[1] = (float)(((b >> 16) & 0xFF) - ((a >> 16) & 0xFF))
		/frame->max;
	frame->incr[2] = (float)(((b >> 8) & 0xFF) - ((a >> 8) & 0xFF))
		/frame->max;
	incr_sum[0] = ((a >> 24) & 0xFF) + frame->incr[0] * frame->colour_delta;
	incr_sum[1] = ((a >> 16) & 0xFF) + frame->incr[1] * frame->colour_delta;
	incr_sum[2] = ((a >> 8) & 0xFF) + frame->incr[2] * frame->colour_delta;
	new_col = rgb_to_long(float_to_int_colour(incr_sum[0]),
			float_to_int_colour(incr_sum[1]),
			float_to_int_colour(incr_sum[2]));
	return (new_col);
}

long	set_x(t_wf *frame, t_map *matrix)
{
	long	a;
	long	b;
	long	new_col;

	a = colour_to_long(frame, matrix, frame->y, frame->x);
	b = colour_to_long(frame, matrix, frame->y, frame->x + 1);
	new_col = getting_new_colour(frame, a, b);
	return (new_col);
}

long	set_y(t_wf *frame, t_map *matrix)
{
	long	a;
	long	b;
	long	new_col;

	a = colour_to_long(frame, matrix, frame->y, frame->x);
	b = colour_to_long(frame, matrix, frame->y + 1, frame->x);
	new_col = getting_new_colour(frame, a, b);
	return (new_col);
}
