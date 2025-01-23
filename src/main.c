/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/23 18:18:19 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ---注釈---
// 以下FDFの動かし方。
// 1: 列の数はすべての行で同じ値を渡すこと。
// 2: .FDFファイルを出力できる範囲はint_maxまで。
// 3: .fdfファイルの配列に色が含まれる場合、それは考慮しない。（// TODO: koremada）
// ---------

int	main()
{
	t_fdf		data_;

	// 初期化：ファイル名をつっこんでmatrixを初期化する
	init_data(&data_);
	
	// バリデーション&セットでーた
	if (!validation_and_set_data("../test_maps/mars.fdf", &data_))
		return (1);
	
	// --- ここから描画処理 ---
	// 初期化
	set_mlx(&data_, 1920, 1080, "Hello world!");
	// 処理をloopさせる
	mlx_loop((&data_)->mlx_ptr);

	

	


	// clean
	vacuum_matrix((&data_)->matrix);
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