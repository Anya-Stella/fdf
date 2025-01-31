/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:41:36 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/31 21:08:21 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

// pixelを打つ関数->bufferに保存// ()
void	put_pixel(int x, int y, int color, t_fdf *data_)
{
	if (0 <= x && x < data_->win_width && 0 <= y && y < data_->win_height)
		data_->img_ptr[y * data_->win_width + x] = color;
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

// cos(π/6)＝１に近似
int    caluculate_isometric_x(int x, int y)
{
    double result;

    result = (x - y) * 1;// 0.8666
    return  ((int)result);
}

// sin(π/6)＝0.5
int    caluculate_isometric_y(int x, int y, int z)
{
    double result;

    result = (x + y) * 0.5 - z;
    return  ((int)result);
}
