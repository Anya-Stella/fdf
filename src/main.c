/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/03 14:12:35 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ---注釈---
// 以下FDFの動かし方。
// 1: 列の数はすべての行で同じ値を渡すこと。
// 2: .fdfファイルを出力できる範囲はint_maxまで。
// 3: .fdfファイルの配列に色情報が含まれるものは未定義。
// ---------

int	main(int ac, char **av)
{
	t_fdf	data_;
	char	*map;

	if (ac != 2)
		return (1);
	map = *(++av);
	init_data(&data_);
	if (!validation_and_set_data(map, &data_))
		return (1);
	set_mlx_variable(&data_, data_.win_width, data_.win_height, "Hello world!");
	draw(&data_);
	hook_close(&data_);
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