/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:47:13 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/02 15:16:54 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_fdf *data_)
{
	data_->height = 0;
	data_->width = 0;
	data_->matrix = NULL;
	data_->zoom = 30;
	data_->z_zoom = data_->zoom;
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

void	set_mlx_variable(t_fdf *d_, int width, int height, char *title)
{
	d_->mlx_ptr = mlx_init();
	d_->window_ptr = mlx_new_window(d_->mlx_ptr, width, height, title);
	d_->img = mlx_new_image(d_->mlx_ptr, d_->win_width, d_->win_height);
	d_->img_ptr = \
	(int *)mlx_get_data_addr(d_->img, &(d_->bpp), &(d_->size_l), &(d_->endian));
}
