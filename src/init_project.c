/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:47:13 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/22 18:25:06 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_fdf *data_)
{
	data_->height = 0;
	data_->width = 0;
	data_->matrix = NULL;
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

bool	validation_and_set_data(char *file_name, t_fdf *data_)
{
	if (!set_height(file_name, &(data_->height)))
		return (false);
	if (!set_width(file_name, &(data_->width)))
		return (false);
	if (!set_matrix(file_name, data_))
		return (false);
	return (true);
}
