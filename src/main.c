/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/20 16:45:50 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ---注釈---
// 1: .FDFファイルに入ってくる最大行。最大列は、int内にしないとオーバーフロー起きる
// ２: width,heightはすべて固定値で頼む。
// ２: 適切に空白いれやがれ（途中で空白に連続or最後に空白終了）
int	main()
{
	t_fdf		data;

	// バリデーション
	

	// 初期化：ファイル名をつっこんでmatrixを初期化する
	init_data(&data);
	// set_data("../test_maps/10-2.fdf", &data);
	// set_data("../test_maps/100-6.fdf", &data);
	// set_data("../test_maps/42.fdf", &data);
	// set_data("../test_maps/elem-col.fdf", &data);
	set_data("../test_maps/basictest.fdf", &data);

	// set_data("../test_maps/elem-fract.fdf", &data);------------not
	
	// set_data("../test_maps/elem2.fdf", &data);
	// set_data("../test_maps/mars.fdf", &data);------------------not
	// この時点でmatrixには数字が入っている

	return (0);
}
