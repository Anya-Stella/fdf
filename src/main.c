/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/20 12:49:28 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"





// ---注釈---
// 1: .FDFファイルに入ってくる最大行。最大列は、int内にしないとオーバーフロー起きる
// ２: width,heightはすべて固定値で頼む。
int	main()
{
	t_fdf		data;

	// 初期化：ファイル名をつっこんでmatrixを初期化する
	init_data(&data);
	set_data("../test_maps/42.fdf", &data);
	



	
	return (0);


}