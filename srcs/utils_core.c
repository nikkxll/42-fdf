/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:01:37 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 01:58:08 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	render_background(t_wf *frame)
{
    int	i;
    int	j;

    if (frame->img == NULL)
        return ;
    i = 0;
    while (i < 1000)
    {
        j = 0;
        while (j < 1000)
            mlx_put_pixel(frame->img, j++, i, 0x000000ff);
        ++i;
    }
}
