/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:41:36 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/27 22:37:14 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	put_pixel(int x, int y, int color, t_fdf *data_)
{
	mlx_pixel_put(data_->mlx_ptr, data_->window_ptr, x, y, color);
}
