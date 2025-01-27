/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:34:39 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/27 16:24:00 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw_line(int x1, int y1, int x2, int y2, t_fdf *data_)
// void	draw_line(t_fdf *data_)
// {
// 	int x= 900;
// 	int x_end = 1800;

// 	//pixel_put
// 	while (x++ < x_end)
// 	{
// 		if (x%2 == 0)
// 		{

// 		mlx_pixel_put(data_->mlx_ptr, data_->window_ptr, x, 100, 0xffffff);
// 		}
// 	}
// }


//-----Bresenham's line algorithm divide dy/dx >= 1-----
// gear4
// dx = abs(x2 - x1);
// dy = abs(y2 - y1);
// sx = (x2 >= x1) ? 1 : -1;
// sy = (y2 >= y1) ? 1 : -1;

// if (dx >= dy)
//     // xをメインに進めるバージョン
// else
//     // yをメインに進めるバージョン
//--------------------------------------



// (x1, y1)と(x2, y2)を結ぶ直線を描画する関数
// Bresenham's line algorithm gear5
// 理解のための注釈：
// d > -dy、d < dxはgear4の条件と同じものをdの初項を2(dx-dy)にし、
// 公差も２倍にすることで成り立つので、gear4を数学的理解するところからはじまる。
void	draw_line(int x0, int y0, int x1, int y1, t_fdf *data_)
{
	int	dx;
	int	dy;
	int d;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	d = 2 * (dx - dy);
	while (1)
	{
		put_pixel(x0, y0, data_);
		if (x0 == x1 && y0 == y1)
			return ;
		if (d > -dy)
		{
			d += -2 * dy;
			x0 += 2 * (x0 < x1) - 1;
		}
		if (d < dx)
		{
			d += 2 * dx;
			y0 += 2 * (y0 < y1) - 1;
		}
	}	
}
