/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:28:20 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/17 20:19:58 by tishihar         ###   ########.fr       */
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

	matrix = (int **)ft_calloc(height + 1, sizeof(int *));// 000000
	if (!matrix)
        return (NULL);
	temp = matrix;
	row = height;
	allocated = 0;
	while (row--)
	{
		*temp = (int *)ft_calloc(width + 1, sizeof(int));
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
	int	**matrix_dummy;
	int	fd;
	char *line;

	// 二次元配列を確保する
	matrix = create_matrix(data_->width, data_->height);
	matrix_dummy = matrix;

	// 二次元配列に登録する
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	
	while (!!(line = get_next_line(fd)))
	{
		// この段階でline = "0 10 2 34  4  3 3 3 3  \0 \n \0"
		// 入力：lineと書き込むためにmatrixのポインタを渡す

		// 1: 配列に書き込む
		//２：
		fill_array(line, &matrix);
	}
}
