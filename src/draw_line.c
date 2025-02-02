/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:34:39 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/02 15:44:03 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 参照：wikipedia
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

static	void	init_line(t_point *p0_, t_point *p1_, t_line *l_, t_fdf *d_)
{
	int	z0;
	int	z1;
	int	offset_x;
	int	offset_y;

	z0 = zoom(d_->matrix[p0_->y][p0_->x], d_->z_zoom);
	z1 = zoom(d_->matrix[p1_->y][p1_->x], d_->z_zoom);
	offset_x = (d_->win_width) / 2;
	offset_y = (d_->win_height - zoom(d_->height, d_->zoom)) / 2;
	p0_->x = zoom(p0_->x, d_->zoom);
	p0_->y = zoom(p0_->y, d_->zoom);
	p1_->x = zoom(p1_->x, d_->zoom);
	p1_->y = zoom(p1_->y, d_->zoom);
	l_->x0 = calc_isometric_x(p0_->x, p0_->y) + offset_x + d_->shift_x;
	l_->y0 = calc_isometric_y(p0_->x, p0_->y, z0) + offset_y + d_->shift_y;
	l_->x1 = calc_isometric_x(p1_->x, p1_->y) + offset_x + d_->shift_x;
	l_->y1 = calc_isometric_y(p1_->x, p1_->y, z1) + offset_y + d_->shift_y;
	l_->dx = abs(l_->x1 - l_->x0);
	l_->dy = abs(l_->y1 - l_->y0);
	if (z0 != 0 || z1 != 0)
		l_->color = 0xffff00;
	else
		l_->color = 0x00ffff;
}

//　imgのバッファを初期化
static	void	init_screen(t_fdf	*d_)
{
	ft_bzero(d_->img_ptr, d_->win_width * d_->win_height * (d_->bpp / 8));
}

// 上記のブレゼンハムをポイント渡しに改良
void	draw_line(t_point *p0_, t_point *p1_, t_fdf *data_)
{
	int		d;
	t_line	line;

	init_line(p0_, p1_, &line, data_);
	d = 2 * (line.dx - line.dy);
	while (1)
	{
		put_pixel(line.x0, line.y0, line.color, data_);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			return ;
		if (d > -line.dy)
		{
			d += -2 * line.dy;
			line.x0 += 2 * (line.x0 < line.x1) - 1;
		}
		if (d < line.dx)
		{
			d += 2 * line.dx;
			line.y0 += 2 * (line.y0 < line.y1) - 1;
		}
	}
}

// 格子を描く
void	draw_grid(t_fdf *data_)
{
	int		x;
	int		y;

	init_screen(data_);
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
