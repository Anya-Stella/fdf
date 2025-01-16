/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/16 15:39:14 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"






int	main()
{
	int		fd;
	char	*line;

	// ファイルを開く
	fd = open("../test_maps/42.fdf", O_RDONLY);
	if (fd == -1)
	{
		perror("open failed.");
		return (1);
	}
	
	// 初期化して二次元配列に格納する
	// line : 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 \0 \n \0
	while (!!(line = get_next_line(fd)))
	{
		
	

		free(line);
	}

	close(fd);
	return (0);


}