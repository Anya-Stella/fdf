/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/30 14:02:13 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ---注釈---
// 以下FDFの動かし方。
// 1: 列の数はすべての行で同じ値を渡すこと。
// 2: .FDFファイルを出力できる範囲はint_maxまで。
// 3: .fdfファイルの配列に色が含まれる場合、それは考慮しない。（// TODO: koremada）
// ---------

int	deal_key(int keycode , void *param)
{
	(void)param;
	 
	printf("key is:%d", keycode);
	return (0);
}

int	main()
{
	t_fdf		data_;

	// 初期化 ---------------
	init_data(&data_);
	if (!validation_and_set_data("../test_maps/42.fdf", &data_))
		return (1);
	
	// --- ここから描画処理 ---
	// mlx初期化
	set_mlx(&data_, (&data_)->win_width, (&data_)->win_height, "Hello world!");
	// key_hook
	mlx_key_hook((&data_)->window_ptr, deal_key, NULL);

	
	draw_grid(&data_);




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