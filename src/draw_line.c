/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:34:39 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/30 15:26:18 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 参照：https://ja.wikipedia.org/wiki/%E3%83%96%E3%83%AC%E3%82%BC%E3%83%B3%E3%83%8F%E3%83%A0%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
//-----Bresenham's line algorithm divide dy/dx >= 1-----
// gear4
// dx = abs(x2 - x1);
// dy = abs(y2 - y1);
// sx = (x2 >= x1) ? 1 : -1;
// sy = (y2 >= y1) ? 1 : -1;
//
// plot(x0,y0, x1,y1)
//   dx=x1-x0
//   dy=y1-y0

//   D = 2*dy - dx
//   plot(x0,y0)
//   y=y0

//   for x from x0+1 to x1
//     if D > 0
//       y = y+1
//       plot(x,y)
//       D = D + (2*dy-2*dx)
//     else
//       plot(x,y)
//       D = D + (2*dy)
//--------------------------------------

// (x1, y1)と(x2, y2)を結ぶ直線を描画する関数
// Bresenham's line algorithm gear5
// 理解のための注釈：
// d > -dy、d < dxはgear4の条件と同じものをdの初項を2(dx-dy)にし、
// 公差も２倍にすることで成り立つので、gear4を数学的理解するところからはじまる。
// void	draw_line(int x0, int y0, int x1, int y1, t_fdf *data_)
// {
// 	int	dx;
// 	int	dy;
// 	int d;

// 	dx = abs(x1 - x0);
// 	dy = abs(y1 - y0);
// 	d = 2 * (dx - dy);
// 	while (1)
// 	{
// 		put_pixel(x0, y0, data_);
// 		if (x0 == x1 && y0 == y1)
// 			return ;
// 		if (d > -dy)
// 		{
// 			d += -2 * dy;
// 			x0 += 2 * (x0 < x1) - 1;
// 		}
// 		if (d < dx)
// 		{
// 			d += 2 * dx;
// 			y0 += 2 * (y0 < y1) - 1;
// 		}
// 	}	
// }

static void init_line_info(t_point *p0_, t_point *p1_, t_line *line_, t_fdf *data_)
{
    int z0  = zoom(data_->matrix[p0_->y][p0_->x], data_->z_zoom);
    int z1  = zoom(data_->matrix[p1_->y][p1_->x], data_->z_zoom);
	
    // 画面中央に移動 (オフセット加算)
    int offsetX = (data_->win_width  - zoom(data_->width, data_->zoom)) / 2;
    int offsetY = (data_->win_height - zoom(data_->height, data_->zoom)) / 2;
	
    p0_->x = zoom(p0_->x, data_->zoom);
    p0_->y = zoom(p0_->y, data_->zoom);
    p1_->x = zoom(p1_->x, data_->zoom);
    p1_->y = zoom(p1_->y, data_->zoom);

    line_->x0 = caluculate_isometric_x(p0_->x, p0_->y) + offsetX;
    line_->y0 = caluculate_isometric_y(p0_->x, p0_->y, z0) + offsetY;
    line_->x1 = caluculate_isometric_x(p1_->x, p1_->y) + offsetX;
    line_->y1 = caluculate_isometric_y(p1_->x, p1_->y, z1) + offsetY;

    // 以下はブレゼンハム用の下準備
    line_->dx = abs(line_->x1 - line_->x0);
    line_->dy = abs(line_->y1 - line_->y0);
    line_->color = (z0 != 0 || z1 != 0) ? 0xffff00 : 0x00ffff;
}


// 上記のブレゼンハムをポイント渡しに改良
void	draw_line(t_point *p0_, t_point *p1_, t_fdf *data_)
{
	int 	d;
	t_line	line;
	
	init_line_info(p0_, p1_, &line, data_);
	d = 2 * ((&line)->dx - (&line)->dy);
	while (1)
	{
		put_pixel((&line)->x0, (&line)->y0, (&line)->color, data_);
		if ((&line)->x0 == (&line)->x1 && (&line)->y0 == (&line)->y1)
			return ;
		if (d > -(&line)->dy)
		{
			d += -2 * (&line)->dy;
			(&line)->x0 += 2 * ((&line)->x0 < (&line)->x1) - 1;
		}
		if (d < (&line)->dx)
		{
			d += 2 * (&line)->dx;
			(&line)->y0 += 2 * ((&line)->y0 < (&line)->y1) - 1;
		}
	}
}

// 格子を描く
void	draw_grid(t_fdf *data_)
{
	int		x;
	int		y;

	y = 0;
	while (y < data_->height)
	{
		x = 0;
		while (x < data_->width)
		{
			if (x + 1 < data_->width)
				draw_line(&((t_point){x, y}), &((t_point){x + 1, y}), data_);
			if (y + 1 < data_->height)
				draw_line(&((t_point){x, y}), &((t_point){x, y + 1}), data_);
			x++;
		}
		y++;
	}
}
