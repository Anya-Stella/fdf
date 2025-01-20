/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/20 21:59:39 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ---注釈---
// 以下FDFの動かし方。
// 1: 列の数はすべての行で同じ値を渡すこと。O
// 2: .FDFファイルを出力できる範囲はintに限ります。O
// 3: .fdfファイルの配列に色が含まれる場合、それを考慮します。
// ---------

int	main()
{
	t_fdf		data;

	// 初期化：ファイル名をつっこんでmatrixを初期化する
	init_data(&data);
	
	// バリデーション&セットでーた

	

	// set_data("../test_maps/10-2.fdf", &data);
	// set_data("../test_maps/100-6.fdf", &data);
	// set_data("../test_maps/42.fdf", &data);
	// set_data("../test_maps/elem-col.fdf", &data);
	set_data("../test_maps/basictest.fdf", &data);

	// set_data("../test_maps/elem-fract.fdf", &data);------------not
	
	// set_data("../test_maps/elem2.fdf", &data);
	// set_data("../test_maps/mars.fdf", &data);
	// この時点でmatrixには数字が入っている

	return (0);
}
