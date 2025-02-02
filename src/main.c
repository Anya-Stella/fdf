/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/02 15:49:09 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ---注釈---
// 以下FDFの動かし方。
// 1: 列の数はすべての行で同じ値を渡すこと。
// 2: .FDFファイルを出力できる範囲はint_maxまで。
// 3: .fdfファイルの配列に色が含まれる場合、それは考慮しない。（// TODO: koremada）
// ---------

// • Clicking on the cross on the window’s frame must close the window and quit the　program in a clean way.

int	deal_key(int keycode, t_fdf *data_)
{
	if (keycode == 65307)
		escape(data_);
	if (keycode == 65362)
		data_->z_zoom += 5;
	if (keycode == 65364)
		data_->z_zoom -= 5;
	if (keycode == 65361)
		data_->zoom -= 5;
	if (keycode == 65363)
		data_->zoom += 5;
	if (keycode == 119)
		data_->shift_y -= 10;
	if (keycode == 97)
		data_->shift_x -= 10;
	if (keycode == 115)
		data_->shift_y += 10;
	if (keycode == 100)
		data_->shift_x += 10;
	draw(data_);
	return (0);
}

int	main(void)
{
	t_fdf		data_;

	init_data(&data_);
	if (!validation_and_set_data("../test_maps/pyra.fdf", &data_))
		return (1);
	set_mlx_variable(&data_, data_.win_width, data_.win_height, "Hello world!");
	draw(&data_);
	mlx_key_hook(data_.window_ptr, deal_key, &data_);
	mlx_loop(data_.mlx_ptr);
	vacuum_matrix(data_.matrix, &data_);
	return (0);
}

	// set_data("../test_maps/10-2.fdf", &data);
	// set_data("../test_maps/100-6.fdf", &data);
	// set_data("../test_maps/42.fdf", &data);
	// set_data("../test_maps/elem-col.fdf", &data);
	// set_data("../test_maps/elem-fract.fdf", &data);------------not
	// set_data("../test_maps/elem2.fdf", &data);
	// set_data("../test_maps/mars.fdf", &data);
	// 確認用
	// print_z((&data)->matrix, (&data)->height, (&data)->width);