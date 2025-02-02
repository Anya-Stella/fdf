/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:07:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/02 15:50:24 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	draw(t_fdf *d_)
{
	draw_grid(d_);
	mlx_put_image_to_window(d_->mlx_ptr, d_->window_ptr, d_->img, 0, 0);
}

void	escape(t_fdf *data_)
{
	mlx_destroy_image(data_->mlx_ptr, data_->img);
	mlx_destroy_window(data_->mlx_ptr, data_->window_ptr);
	vacuum_matrix(data_->matrix, data_);
	exit(0);
}
