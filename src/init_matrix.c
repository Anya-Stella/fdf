/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:28:20 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/20 14:34:46 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

// arrayはrowの先頭ぽいんた
static	void	fill_array(char *line, int *col, int width)
{
	char	**nums;
	char	**temp;

	nums = ft_split(line, ' ');// " "123", "45", "834" "
	if (!nums)
		return ;

	temp = nums;
	while (width--)// *temp = "123"
	{
		*col = ft_atoi(*temp);
		free(*temp);

		col++;
		temp++;
	}

	free(nums);
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
		fill_array(line, *matrix_dummy, data_->width);
		free(line);
		
		matrix_dummy++;
	}
	close(fd);

	data_->matrix = matrix;
	return (true);
}

// matrixをすべて掃除する
void	vacuum_matrix(int **matrix)
{
	int**	origin;

	origin = matrix;
	while (*matrix)
	{
		free(*matrix);
		matrix++;
	}
	free(origin);
}
