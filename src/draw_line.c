/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:34:39 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/27 21:52:36 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static	void	init_line_info(t_point *p0_, t_point *p1_, t_line *line_, t_fdf *data_)
{
	line_->x0 = data_->zoom * p0_->x;
	line_->y0 = data_->zoom * p0_->y;
	line_->x1 = data_->zoom * p1_->x;
	line_->y1 = data_->zoom * p1_->y;	
	line_->dx = abs(p1_->x - p0_->x);
	line_->dy = abs(p1_->y - p0_->y);
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
		put_pixel((&line)->x0, (&line)->y0, data_);
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
	while (y <= data_->height)
	{
		x = 0;
		while (x <= data_->width)
		{
			if (x < data_->width)
				draw_line(&((t_point){x, y}), &((t_point){x + 1, y}), data_);
			if (y < data_->height)
				draw_line(&((t_point){x, y}), &((t_point){x, y + 1}), data_);

			x++;
		}
		y++;
	}
}