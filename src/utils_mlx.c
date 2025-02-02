/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:07:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/02 17:22:30 by tishihar         ###   ########.fr       */
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

static	int	deal_key(int keycode, t_fdf *data_)
{
	if (keycode == 65307)
		escape(data_);
	if (keycode == 65362)
		data_->z_zoom += 5;
	if (keycode == 65364)
		data_->z_zoom -= 5;
	if (keycode == 65361)
		data_->zoom -= 5;
	if (keycode == 65363)
		data_->zoom += 5;
	if (keycode == 119)
		data_->shift_y -= 10;
	if (keycode == 97)
		data_->shift_x -= 10;
	if (keycode == 115)
		data_->shift_y += 10;
	if (keycode == 100)
		data_->shift_x += 10;
	draw(data_);
	return (0);
}

static	int	deal_cross(t_fdf *data_)
{
	escape(data_);
	return (0);
}

// window_colse_hook
void	hook_close(t_fdf *data_)
{
	mlx_key_hook(data_->window_ptr, deal_key, data_);
	mlx_hook(data_->window_ptr, 17, 0, deal_cross, data_);
}
