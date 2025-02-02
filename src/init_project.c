/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:47:13 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/01 15:51:49 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_fdf *data_)
{
	data_->height = 0;
	data_->width = 0;
	data_->matrix = NULL;

	data_->zoom = 30;
	data_->z_zoom = 10;

	data_->win_width = 1920;
	data_->win_height = 1080;

	data_->shift_x = 0;
	data_->shift_y = 0;

	data_->mlx_ptr = NULL;
	data_->window_ptr = NULL;
	data_->img = NULL;
	data_->img_ptr = NULL;
}

// matrixをすべて掃除する
void	vacuum_matrix(int **matrix, t_fdf *data_)
{
	int	**temp;
	int	row;

	temp = matrix;
	row = data_->height;
	while (row--)
	{
		free(*temp);
		temp++;
	}
	free(matrix);
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

void	set_mlx_variable(t_fdf *data_, int width, int height, char *title)
{
	data_->mlx_ptr = mlx_init();
	data_->window_ptr = mlx_new_window(data_->mlx_ptr, width, height, title);
	data_->img = mlx_new_image(data_->mlx_ptr, data_->win_width, data_->win_height);
	data_->img_ptr = (int	*)mlx_get_data_addr(data_->img, &(data_->bpp), &(data_->size_l), &(data_->endian));
}
