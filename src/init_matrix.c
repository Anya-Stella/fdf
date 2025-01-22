/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:28:20 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/22 19:20:14 by tishihar         ###   ########.fr       */
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
static	bool	fill_array(char *line, int *col, int width)
{
	char	**nums;
	char	**iter;
	char	**temp;

	nums = ft_split(line, ' ');
	if (!nums)
		return (false);
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
		free (*iter);
		iter++;
	}
	free (nums);
	return (true);
}

static	bool	fill_matrix(int **matrix, char *file_name, int width)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		if (!fill_array(line, *matrix, width))
		{
			free(line);
			close(fd);
			return (false);
		}
		free(line);
		matrix++;
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}

bool	set_matrix(char *file_name, t_fdf *data_)
{
	int		**matrix;

	matrix = create_matrix(data_->width, data_->height);
	if (!matrix)
		return (false);
	if (!fill_matrix(matrix, file_name, data_->width))
	{
		vacuum_matrix(matrix);
		return (false);
	}
	data_->matrix = matrix;
	return (true);
}
