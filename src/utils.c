/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:41:36 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/29 21:33:10 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

// pixelを打つ関数
void	put_pixel(int x, int y, int color, t_fdf *data_)
{
	mlx_pixel_put(data_->mlx_ptr, data_->window_ptr, x, y, color);
}


// 座標を定数倍するための関数
int	zoom(int value, int magnification)
{
	return (value * magnification);
}

// ---以下アイソメトリック記法にするための位置ベクトル変換---
// 位置ベクトル変換を理解するための注釈
// 通常のx-y平面の座標は(1,0)ｘ単位ベクトルを定数倍したものと(0,1)のy単位ベクトルの合成ベクトルである。
//　なので、いつもどおりのx-y平面上に、
//
//        vz
//　　　　　｜
//        |
//       / \　
//     /    \　
//   /       \　
//  vy        vx
// 
//
// みたいにする時のそれぞれの軸への単位ベクトルvx=(cosθ,sinθ)とvy=(-cosθ,sinθ)とvz=(0,1)をそれぞれの大きさぶんスカラー倍したものの合成ベクトルをかんがえればよい。

int    caluculate_isometric_x(int x, int y)
{
    double angle;
    double pie = 3.141592653589793;
    double result;

    angle = pie / 6.0;
    result = (x - y) * cos(angle);
    return  ((int)result);
}

int    caluculate_isometric_y(int x, int y, int z)
{
    double angle;
    double pie = 3.141592653589793;
    double result;

    angle = pie / 6.0;
    result = (x + y) * sin(angle) - z;
    return  ((int)result);
}
