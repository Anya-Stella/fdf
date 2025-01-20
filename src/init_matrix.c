/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:28:20 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/20 21:48:51 by tishihar         ###   ########.fr       */
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
	int	allocated;

	matrix = (int **)ft_calloc(height + 1, sizeof(int *));
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
	char	**iter;
	char	**temp;

	nums = ft_split(line, ' ');
	if (!nums)
		return ;
	iter = nums;
	temp = nums;
	while (width-- && *temp)
	{
		*col = ft_atoi(*temp);
		col++;
		temp++;
	}
	while (*iter)
    {
        free(*iter);
        iter++;
    }
	free(nums);
}

bool	set_matrix(char *file_name, t_fdf *data_)
{
	int		**matrix;
	int		**matrix_dummy;
	int		fd;
	char	*line;

	matrix = create_matrix(data_->width, data_->height);
	matrix_dummy = matrix;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		fill_array(line, *matrix_dummy, data_->width);
		free(line);
		line = get_next_line(fd);
		matrix_dummy++;
	}
	close(fd);
	data_->matrix = matrix;
	return (true);
}

// matrixをすべて掃除する
void	vacuum_matrix(int **matrix)
{
	int	**origin;

	origin = matrix;
	while (*matrix)
	{
		free(*matrix);
		matrix++;
	}
	free(origin);
}
