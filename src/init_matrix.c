/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:28:20 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/17 20:04:55 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// matrixを掃除する
// void	vacuum_matrix(int **matrix)
// {
// 	int**	start;

// 	start = matrix;
// 	while (*(matrix++))
// 		free(*matrix);
// 	free(start);
// }


// create_matrix関数を中断する場合にフリーする関数
static	void	interruption_create_matrix(int allocated, int **matrix)
{
	int	**curr;

	curr = matrix;
	while (allocated--)
	{
		free(*curr);
		curr++;
	}
	free(matrix);
}	

// サイズ分を初期化した二次元配列の初期ポインタを返す
static	int	**create_matrix(int width, int height)
{
	int	**matrix;
	int	**temp;
	int	row;
	int allocated;

	matrix = (int **)ft_calloc(height, sizeof(int *));// 000000
	if (!matrix)
        return (NULL);
	temp = matrix;
	row = height;
	allocated = 0;
	while (row--)
	{
		*temp = (int *)ft_calloc(width, sizeof(int));
		if (!*temp)
		{
			interruption_create_matrix(allocated, matrix);
			return (NULL);
		}
		allocated++;
		temp++;
	}
	return (matrix);
}


bool	set_matrix(char *file_name, t_fdf *data_)
{
	int	**matrix;

	// 二次元配列を確保する
	matrix = create_matrix(data_->width, data_->height);


	


	// 二次元配列に登録する
}
