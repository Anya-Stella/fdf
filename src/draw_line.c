/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:34:39 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/23 19:03:11 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw_line(int x1, int y1, int x2, int y2, t_fdf *data_)
void	draw_line(t_fdf *data_)
{
	int x= 900;
	int x_end = 1800;

	//pixel_put
	while (x++ < x_end)
	{
		if (x%2 == 0)
		{

		mlx_pixel_put(data_->mlx_ptr, data_->window_ptr, x, 100, 0xffffff);
		}
	}
}